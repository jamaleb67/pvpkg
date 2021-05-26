%ifarch aarch64
%bcond_without neon
%else
%bcond_with neon
%endif

%ifarch %{arm}
%if %{with neon}
%global my_optflags %(echo -n "%{optflags}" | sed 's/-mfpu=[^ \\t]\\+//g'; echo " -mfpu=neon")
%{expand: %global optflags %{my_optflags}}
%global mfpu_neon -Dhave_mfpu_neon=1
%else
%global mfpu_neon -Dhave_mfpu_neon=0
%endif
%endif

Name:           uhd
URL:            http://github.com/pervices/uhd
Version:        3.13.0.0
Release:        master
License:        GPLv3+
BuildRequires:  gcc-c++
BuildRequires:  cmake
BuildRequires:  boost-python3-devel, libusb1-devel, python3-cheetah, ncurses-devel
BuildRequires:  python3-docutils, doxygen, pkgconfig, libpcap-devel
BuildRequires:  python3-numpy, vim-common
%if %{with wireshark}
BuildRequires:  wireshark-devel
%endif
BuildRequires:  python3-mako, python3-requests, python3-devel, tar
%if ! %{with binary_firmware}
BuildRequires: sed
%endif
Requires(pre):  shadow-utils, glibc-common
Requires:       python3-tkinter
Summary:        Universal Hardware Driver for Ettus Research products
#Source0:       %%{url}/archive/v%%{version}/uhd-%%{version}.tar.gz
Source0:        %{url}/archive/refs/heads/master.tar.gz

%description
The UHD is the universal hardware driver for Ettus Research products.
The goal of the UHD is to provide a host driver and API for current and
future Ettus Research products. It can be used standalone without GNU Radio.


%prep
%setup -q -n %{name}-master



%build
mkdir -p host/build
pushd host/build
%cmake %{?have_neon} -DLIB_SUFFIX="/$(DEB_HOST_MULTIARCH)" -DPKG_LIB_DIR="/usr/lib/uhd" -DUHD_RELEASE_MODE="release" -DENABLE_CRIMSON_TNG="ON" -DENABLE_PYTHON3="ON" -DENABLE_CYAN_16T="OFF" -DENABLE_CYAN_64T="OFF" -DENABLE_CYAN_P1HDR16T="OFF" -D Boost_NO_BOOST_CMAKE:BOOL="0" -DBOOST_PYTHON_COMPONENT="python38" -DENABLE_TESTS="OFF" -DENABLE_N230="OFF"  -DENABLE_N300="OFF"  -DENABLE_E320="OFF" -DENABLE_USRP1="OFF" -DENABLE_B200="OFF" -DENABLE_X300="OFF" -DENABLE_OCTOCLOCK="OFF" -DENABLE_DOXYGEN="OFF" -DENABLE_USB="OFF"   \
 ../
make %{?_smp_mflags}
#make -j1
popd

# tools
pushd tools/uhd_dump
make %{?_smp_mflags} CFLAGS="%{optflags}" LDFLAGS="%{?__global_ldflags}"
popd


#%%check
#cd host/build
#make test

%install
# fix python shebangs (run again for generated scripts)
find . -type f -name "*.py" -exec sed -i '/^#!/ s|.*|#!%{__python3}|' {} \;

pushd host/build
make install DESTDIR=%{buildroot}

# Remove tests, examples binaries
rm -rf %{buildroot}%{_libdir}/uhd/{tests,examples}

popd
# Package base docs to base package
mkdir _tmpdoc
mv %{buildroot}%{_docdir}/%{name}/{LICENSE,README.md} _tmpdoc


# remove win stuff
rm -rf %{buildroot}%{_datadir}/uhd/images/winusb_driver

# convert hardlinks to symlinks (to not package the file twice)
pushd %{buildroot}%{_bindir}
for f in uhd_images_downloader usrp2_card_burner
do
  unlink $f
  ln -s ../..%{_libexecdir}/uhd/${f}.py $f
done
popd

# tools
install -Dpm 0755 tools/usrp_x3xx_fpga_jtag_programmer.sh %{buildroot}%{_bindir}/usrp_x3xx_fpga_jtag_programmer.sh
install -Dpm 0755 tools/uhd_dump/chdr_log %{buildroot}%{_bindir}/chdr_log

%if %{with wireshark}
# wireshark dissectors
pushd tools/dissectors
for d in %{wireshark_dissectors}
do
  pushd "build_$d"
  %make_install
  popd
done
popd
mv %{buildroot}${HOME}/.wireshark %{buildroot}%{_libdir}/wireshark
%endif

%ldconfig_scriptlets

%pre
getent group usrp >/dev/null || \
  %{_sbindir}/groupadd -r usrp >/dev/null 2>&1
exit 0

%files
%doc _tmpdoc/*
%{_bindir}/uhd_*
%{_bindir}/usrp2_*
%{_mandir}/man1/*.1*
%{_datadir}/uhd
%{python3_sitearch}/uhd



%changelog
