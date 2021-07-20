%define _binaries_in_noarch_packages_terminate_build 0
%define _unpackaged_files_terminate_build 0
# NEON support is by default enabled on aarch64 and disabled on other ARMs (it can be overridden)
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

# For versions not yet on ftp, pull from git
#%%global git_commit 441a3767e05d15e62c519ea66b848b5adb0f4b3a
#%%global alphatag rc1

Name:		volk
Version:	3.9
Release:	volk
Summary:	Software defined radio framework

License:	GPLv3
URL:		https://www.gnuradio.org/
Source0:	volk.tar.gz
# git clone --recursive git clone --recursive https://github.com/gnuradio/volk.git
# tar -czvf volk.tar.gz volk

Provides:	volk

%description
Volk is a component of Gnuradio that needs to be separately installed as of Gnuradio 3.9


%prep
%setup -q -n %{name}

%build
mkdir build
cd build
%cmake \
-DPYTHON_EXECUTABLE=%{__python3} \
%{?mfpu_neon} \
..
#-DENABLE_DOXYGEN=FALSE \

%make_build CFLAGS="%{optflags} -fno-strict-aliasing" CXXFLAGS="%{optflags} -fno-strict-aliasing"

%install
%make_install -C build
      

%ldconfig_scriptlets

%files
/usr/lib64/pkgconfig/volk.pc
/usr/lib64/libvolk*
/usr/bin/volk_profile
/usr/include/volk/*
/usr/lib64/python3.6/site-packages/volk*


%changelog
