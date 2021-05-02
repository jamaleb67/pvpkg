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
/* BINDTOOL_HEADER_FILE(tpc_common.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(3a3451c1e4e60a8034a77714e4b18b2c)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fec/tpc_common.h>
// pydoc.h is automatically generated in the build directory
#include <tpc_common_pydoc.h>

void bind_tpc_common(py::module& m)
{

    using tpc_common = ::gr::fec::tpc_common;


    py::class_<tpc_common, std::shared_ptr<tpc_common>>(m, "tpc_common", D(tpc_common))

        .def_static("parity_counter",
                    &tpc_common::parity_counter,
                    py::arg("symbol"),
                    py::arg("length"),
                    D(tpc_common, parity_counter))


        .def_static("rsc_enc_bit",
                    &tpc_common::rsc_enc_bit,
                    py::arg("input"),
                    py::arg("state_in"),
                    py::arg("g"),
                    py::arg("KK"),
                    py::arg("nn"),
                    py::arg("output"),
                    py::arg("nextStates"),
                    D(tpc_common, rsc_enc_bit))


        .def_static("precomputeStateTransitionMatrix_RSCPoly",
                    &tpc_common::precomputeStateTransitionMatrix_RSCPoly,
                    py::arg("numStates"),
                    py::arg("g"),
                    py::arg("KK"),
                    py::arg("nn"),
                    py::arg("output"),
                    py::arg("nextStates"),
                    D(tpc_common, precomputeStateTransitionMatrix_RSCPoly))


        .def_static("rsc_tail",
                    &tpc_common::rsc_tail,
                    py::arg("tail_p"),
                    py::arg("g"),
                    py::arg("max_states"),
                    py::arg("mm"),
                    D(tpc_common, rsc_tail))


        .def_static("itob",
                    &tpc_common::itob,
                    py::arg("binVec"),
                    py::arg("symbol"),
                    py::arg("length"),
                    D(tpc_common, itob))

        ;
}
