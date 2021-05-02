/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(pfb_arb_resampler.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(575adbe9dca6665e15803cdc1f2fa028)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/filter/pfb_arb_resampler.h>
// pydoc.h is automatically generated in the build directory
#include <pfb_arb_resampler_pydoc.h>

void bind_pfb_arb_resampler(py::module& m)
{


    py::module m_kernel = m.def_submodule("kernel");

    using pfb_arb_resampler_ccf = ::gr::filter::kernel::pfb_arb_resampler_ccf;
    using pfb_arb_resampler_ccc = ::gr::filter::kernel::pfb_arb_resampler_ccc;
    using pfb_arb_resampler_fff = ::gr::filter::kernel::pfb_arb_resampler_fff;


    py::class_<pfb_arb_resampler_ccf, std::shared_ptr<pfb_arb_resampler_ccf>>(
        m_kernel, "pfb_arb_resampler_ccf", D(kernel, pfb_arb_resampler_ccf))

        .def(py::init<float,
                      std::vector<float, std::allocator<float>> const&,
                      unsigned int>(),
             py::arg("rate"),
             py::arg("taps"),
             py::arg("filter_size"),
             D(kernel, pfb_arb_resampler_ccf, pfb_arb_resampler_ccf, 0))


        .def("set_taps",
             &pfb_arb_resampler_ccf::set_taps,
             py::arg("taps"),
             D(kernel, pfb_arb_resampler_ccf, set_taps))


        .def("taps", &pfb_arb_resampler_ccf::taps, D(kernel, pfb_arb_resampler_ccf, taps))


        .def("print_taps",
             &pfb_arb_resampler_ccf::print_taps,
             D(kernel, pfb_arb_resampler_ccf, print_taps))


        .def("set_rate",
             &pfb_arb_resampler_ccf::set_rate,
             py::arg("rate"),
             D(kernel, pfb_arb_resampler_ccf, set_rate))


        .def("set_phase",
             &pfb_arb_resampler_ccf::set_phase,
             py::arg("ph"),
             D(kernel, pfb_arb_resampler_ccf, set_phase))


        .def("phase",
             &pfb_arb_resampler_ccf::phase,
             D(kernel, pfb_arb_resampler_ccf, phase))


        .def("taps_per_filter",
             &pfb_arb_resampler_ccf::taps_per_filter,
             D(kernel, pfb_arb_resampler_ccf, taps_per_filter))


        .def("interpolation_rate",
             &pfb_arb_resampler_ccf::interpolation_rate,
             D(kernel, pfb_arb_resampler_ccf, interpolation_rate))


        .def("decimation_rate",
             &pfb_arb_resampler_ccf::decimation_rate,
             D(kernel, pfb_arb_resampler_ccf, decimation_rate))


        .def("fractional_rate",
             &pfb_arb_resampler_ccf::fractional_rate,
             D(kernel, pfb_arb_resampler_ccf, fractional_rate))


        .def("group_delay",
             &pfb_arb_resampler_ccf::group_delay,
             D(kernel, pfb_arb_resampler_ccf, group_delay))


        .def("phase_offset",
             &pfb_arb_resampler_ccf::phase_offset,
             py::arg("freq"),
             py::arg("fs"),
             D(kernel, pfb_arb_resampler_ccf, phase_offset))


        .def("filter",
             &pfb_arb_resampler_ccf::filter,
             py::arg("output"),
             py::arg("input"),
             py::arg("n_to_read"),
             py::arg("n_read"),
             D(kernel, pfb_arb_resampler_ccf, filter))

        ;


    py::class_<pfb_arb_resampler_ccc, std::shared_ptr<pfb_arb_resampler_ccc>>(
        m_kernel, "pfb_arb_resampler_ccc", D(kernel, pfb_arb_resampler_ccc))

        .def(py::init<float,
                      std::vector<std::complex<float>,
                                  std::allocator<std::complex<float>>> const&,
                      unsigned int>(),
             py::arg("rate"),
             py::arg("taps"),
             py::arg("filter_size"),
             D(kernel, pfb_arb_resampler_ccc, pfb_arb_resampler_ccc, 0))


        .def("set_taps",
             &pfb_arb_resampler_ccc::set_taps,
             py::arg("taps"),
             D(kernel, pfb_arb_resampler_ccc, set_taps))


        .def("taps", &pfb_arb_resampler_ccc::taps, D(kernel, pfb_arb_resampler_ccc, taps))


        .def("print_taps",
             &pfb_arb_resampler_ccc::print_taps,
             D(kernel, pfb_arb_resampler_ccc, print_taps))


        .def("set_rate",
             &pfb_arb_resampler_ccc::set_rate,
             py::arg("rate"),
             D(kernel, pfb_arb_resampler_ccc, set_rate))


        .def("set_phase",
             &pfb_arb_resampler_ccc::set_phase,
             py::arg("ph"),
             D(kernel, pfb_arb_resampler_ccc, set_phase))


        .def("phase",
             &pfb_arb_resampler_ccc::phase,
             D(kernel, pfb_arb_resampler_ccc, phase))


        .def("taps_per_filter",
             &pfb_arb_resampler_ccc::taps_per_filter,
             D(kernel, pfb_arb_resampler_ccc, taps_per_filter))


        .def("interpolation_rate",
             &pfb_arb_resampler_ccc::interpolation_rate,
             D(kernel, pfb_arb_resampler_ccc, interpolation_rate))


        .def("decimation_rate",
             &pfb_arb_resampler_ccc::decimation_rate,
             D(kernel, pfb_arb_resampler_ccc, decimation_rate))


        .def("fractional_rate",
             &pfb_arb_resampler_ccc::fractional_rate,
             D(kernel, pfb_arb_resampler_ccc, fractional_rate))


        .def("group_delay",
             &pfb_arb_resampler_ccc::group_delay,
             D(kernel, pfb_arb_resampler_ccc, group_delay))


        .def("phase_offset",
             &pfb_arb_resampler_ccc::phase_offset,
             py::arg("freq"),
             py::arg("fs"),
             D(kernel, pfb_arb_resampler_ccc, phase_offset))


        .def("filter",
             &pfb_arb_resampler_ccc::filter,
             py::arg("output"),
             py::arg("input"),
             py::arg("n_to_read"),
             py::arg("n_read"),
             D(kernel, pfb_arb_resampler_ccc, filter))

        ;


    py::class_<pfb_arb_resampler_fff, std::shared_ptr<pfb_arb_resampler_fff>>(
        m_kernel, "pfb_arb_resampler_fff", D(kernel, pfb_arb_resampler_fff))

        .def(py::init<float,
                      std::vector<float, std::allocator<float>> const&,
                      unsigned int>(),
             py::arg("rate"),
             py::arg("taps"),
             py::arg("filter_size"),
             D(kernel, pfb_arb_resampler_fff, pfb_arb_resampler_fff, 0))


        .def("set_taps",
             &pfb_arb_resampler_fff::set_taps,
             py::arg("taps"),
             D(kernel, pfb_arb_resampler_fff, set_taps))


        .def("taps", &pfb_arb_resampler_fff::taps, D(kernel, pfb_arb_resampler_fff, taps))


        .def("print_taps",
             &pfb_arb_resampler_fff::print_taps,
             D(kernel, pfb_arb_resampler_fff, print_taps))


        .def("set_rate",
             &pfb_arb_resampler_fff::set_rate,
             py::arg("rate"),
             D(kernel, pfb_arb_resampler_fff, set_rate))


        .def("set_phase",
             &pfb_arb_resampler_fff::set_phase,
             py::arg("ph"),
             D(kernel, pfb_arb_resampler_fff, set_phase))


        .def("phase",
             &pfb_arb_resampler_fff::phase,
             D(kernel, pfb_arb_resampler_fff, phase))


        .def("taps_per_filter",
             &pfb_arb_resampler_fff::taps_per_filter,
             D(kernel, pfb_arb_resampler_fff, taps_per_filter))


        .def("interpolation_rate",
             &pfb_arb_resampler_fff::interpolation_rate,
             D(kernel, pfb_arb_resampler_fff, interpolation_rate))


        .def("decimation_rate",
             &pfb_arb_resampler_fff::decimation_rate,
             D(kernel, pfb_arb_resampler_fff, decimation_rate))


        .def("fractional_rate",
             &pfb_arb_resampler_fff::fractional_rate,
             D(kernel, pfb_arb_resampler_fff, fractional_rate))


        .def("group_delay",
             &pfb_arb_resampler_fff::group_delay,
             D(kernel, pfb_arb_resampler_fff, group_delay))


        .def("phase_offset",
             &pfb_arb_resampler_fff::phase_offset,
             py::arg("freq"),
             py::arg("fs"),
             D(kernel, pfb_arb_resampler_fff, phase_offset))


        .def("filter",
             &pfb_arb_resampler_fff::filter,
             py::arg("output"),
             py::arg("input"),
             py::arg("n_to_read"),
             py::arg("n_read"),
             D(kernel, pfb_arb_resampler_fff, filter))

        ;
}
