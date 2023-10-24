// Copyright 2023 TikTok Pte. Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "pybind11/functional.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "setops_py_psi.h"

#include "network/network.h"

#include "setops/pjc/pjc.h"
#include "setops/psi/psi.h"

namespace py = pybind11;

PYBIND11_MODULE(pysetops, m) {
    py::enum_<petace::network::NetScheme>(m, "NetScheme", py::module_local())
            .value("SOCKET", petace::network::NetScheme::SOCKET)
            .export_values();

    py::class_<petace::network::NetParams>(m, "NetParams", py::module_local())
            .def(py::init<>())
            .def_readwrite("local_addr", &petace::network::NetParams::local_addr)
            .def_readwrite("local_port", &petace::network::NetParams::local_port)
            .def_readwrite("remote_addr", &petace::network::NetParams::remote_addr)
            .def_readwrite("remote_port", &petace::network::NetParams::remote_port);

    py::enum_<petace::setops::PSIScheme>(m, "PSIScheme", py::module_local())
            .value("ECDH_PSI", petace::setops::PSIScheme::ECDH_PSI)
            .value("KKRT_PSI", petace::setops::PSIScheme::KKRT_PSI)
            .value("VOLE_PSI", petace::setops::PSIScheme::VOLE_PSI)
            .export_values();

    py::enum_<petace::setops::PJCScheme>(m, "PJCScheme", py::module_local())
            .value("CIRCUIT_PSI", petace::setops::PJCScheme::CIRCUIT_PSI)
            .value("VOLE_PSI", petace::setops::PJCScheme::VOLE_PSI)
            .export_values();

    m.def("psi", &petace::setops::psi, "psi from petace");
    m.def("pjc", &petace::setops::pjc, "pjc from petace");
}
