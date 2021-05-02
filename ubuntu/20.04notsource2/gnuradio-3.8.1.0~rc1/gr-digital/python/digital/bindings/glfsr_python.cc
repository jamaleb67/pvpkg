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
/* BINDTOOL_HEADER_FILE(glfsr.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(4299ef7303d0f404e97b16abb6de32ee)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/glfsr.h>
// pydoc.h is automatically generated in the build directory
#include <glfsr_pydoc.h>

void bind_glfsr(py::module& m)
{

    using glfsr = ::gr::digital::glfsr;


    py::class_<glfsr, std::shared_ptr<glfsr>>(m, "glfsr", D(glfsr))

        .def(py::init<uint32_t, uint32_t>(),
             py::arg("mask"),
             py::arg("seed"),
             D(glfsr, glfsr, 0))
        .def(py::init<gr::digital::glfsr const&>(), py::arg("arg0"), D(glfsr, glfsr, 1))


        .def_static(
            "glfsr_mask", &glfsr::glfsr_mask, py::arg("degree"), D(glfsr, glfsr_mask))


        .def("next_bit", &glfsr::next_bit, D(glfsr, next_bit))


        .def("mask", &glfsr::mask, D(glfsr, mask))

        ;
}
