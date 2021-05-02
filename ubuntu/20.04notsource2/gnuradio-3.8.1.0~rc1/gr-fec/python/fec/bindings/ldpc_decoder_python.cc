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
/* BINDTOOL_HEADER_FILE(ldpc_decoder.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(effac3d18ade07156e8eac6d9b292b9f)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fec/ldpc_decoder.h>
// pydoc.h is automatically generated in the build directory
#include <ldpc_decoder_pydoc.h>

void bind_ldpc_decoder(py::module& m)
{

    using ldpc_decoder = ::gr::fec::ldpc_decoder;


    py::class_<ldpc_decoder, gr::fec::generic_decoder, std::shared_ptr<ldpc_decoder>>(
        m, "ldpc_decoder", D(ldpc_decoder))

        .def_static("make",
                    &ldpc_decoder::make,
                    py::arg("alist_file"),
                    py::arg("sigma") = 0.5,
                    py::arg("max_iterations") = 50,
                    D(ldpc_decoder, make))


        .def("rate", &ldpc_decoder::rate, D(ldpc_decoder, rate))


        .def("set_frame_size",
             &ldpc_decoder::set_frame_size,
             py::arg("frame_size"),
             D(ldpc_decoder, set_frame_size))


        .def("get_output_size",
             &ldpc_decoder::get_output_size,
             D(ldpc_decoder, get_output_size))


        .def("get_input_size",
             &ldpc_decoder::get_input_size,
             D(ldpc_decoder, get_input_size))


        .def("get_input_item_size",
             &ldpc_decoder::get_input_item_size,
             D(ldpc_decoder, get_input_item_size))


        .def("get_output_item_size",
             &ldpc_decoder::get_output_item_size,
             D(ldpc_decoder, get_output_item_size))


        .def("get_iterations",
             &ldpc_decoder::get_iterations,
             D(ldpc_decoder, get_iterations))

        ;
}
