/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* This file is automatically generated using bindtool */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/vocoder/freedv_rx_ss.h>
// pydoc.h is automatically generated in the build directory
#include <freedv_rx_ss_pydoc.h>

void bind_freedv_rx_ss(py::module& m)
{

    using freedv_rx_ss = ::gr::vocoder::freedv_rx_ss;


    py::class_<freedv_rx_ss, gr::block, gr::basic_block, std::shared_ptr<freedv_rx_ss>>(
        m, "freedv_rx_ss", D(freedv_rx_ss))

        .def(py::init(&freedv_rx_ss::make),
             py::arg("mode") = gr::vocoder::freedv_api::MODE_1600,
             py::arg("squelch_thresh") = -100.,
             py::arg("interleave_frames") = 1,
             D(freedv_rx_ss, make))


        .def("set_squelch_thresh",
             &freedv_rx_ss::set_squelch_thresh,
             py::arg("squelch_thresh"),
             D(freedv_rx_ss, set_squelch_thresh))


        .def("squelch_thresh",
             &freedv_rx_ss::squelch_thresh,
             D(freedv_rx_ss, squelch_thresh))


        .def("set_squelch_en",
             &freedv_rx_ss::set_squelch_en,
             py::arg("squelch_enable"),
             D(freedv_rx_ss, set_squelch_en))

        ;
}
