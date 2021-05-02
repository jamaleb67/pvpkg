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
/* BINDTOOL_HEADER_FILE(tsb_vector_sink.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(45f65df7b4f05782ada6c21d6de13d2a)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/tsb_vector_sink.h>

template <typename T>
void bind_tsb_vector_sink_template(py::module& m, const char* classname)
{
    using tsb_vector_sink = gr::blocks::tsb_vector_sink<T>;

    py::class_<tsb_vector_sink,
               gr::tagged_stream_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<tsb_vector_sink>>(m, classname)
        .def(py::init(&gr::blocks::tsb_vector_sink<T>::make),
             py::arg("vlen") = (unsigned int)1,
             py::arg("tsb_key") = std::string("ts_last"))
        .def("reset", &tsb_vector_sink::reset)
        .def("data", &tsb_vector_sink::data)
        .def("tags", &tsb_vector_sink::tags);
}

void bind_tsb_vector_sink(py::module& m)
{
    bind_tsb_vector_sink_template<std::uint8_t>(m, "tsb_vector_sink_b");
    bind_tsb_vector_sink_template<std::int16_t>(m, "tsb_vector_sink_s");
    bind_tsb_vector_sink_template<std::int32_t>(m, "tsb_vector_sink_i");
    bind_tsb_vector_sink_template<float>(m, "tsb_vector_sink_f");
    bind_tsb_vector_sink_template<gr_complex>(m, "tsb_vector_sink_c");
}
