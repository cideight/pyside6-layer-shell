/*
 * Python-Binding für den LayerShell-Adapter.
 */

#include <pybind11/pybind11.h>

#include "../src/layer_shell_adapter.h"
#include "../src/layer_shell_config.h"

namespace py = pybind11;

PYBIND11_MODULE(layer_shell_native, m)
{
    m.doc() = "LayerShellQt native adapter";

    py::enum_<Layer>(
        m,
        "Layer"
    )
        .value("Background", Layer::Background)
        .value("Bottom", Layer::Bottom)
        .value("Top", Layer::Top)
        .value("Overlay", Layer::Overlay);

    py::enum_<ScreenMode>(
        m,
        "ScreenMode"
    )
        .value("Active", ScreenMode::Active)
        .value("Index", ScreenMode::Index);

    py::class_<LayerShellConfig>(
        m,
        "LayerShellConfig"
    )
        .def(py::init<>())

        .def_readwrite("layer", &LayerShellConfig::layer)
        .def_readwrite("screen", &LayerShellConfig::screen)
        .def_readwrite("screen_mode", &LayerShellConfig::screen_mode)

        .def_readwrite("width", &LayerShellConfig::width)
        .def_readwrite("height", &LayerShellConfig::height)

        .def_readwrite("margin_left", &LayerShellConfig::margin_left)
        .def_readwrite("margin_top", &LayerShellConfig::margin_top)
        .def_readwrite("margin_right", &LayerShellConfig::margin_right)
        .def_readwrite("margin_bottom", &LayerShellConfig::margin_bottom)

        .def_readwrite("anchor_top", &LayerShellConfig::anchor_top)
        .def_readwrite("anchor_bottom", &LayerShellConfig::anchor_bottom)
        .def_readwrite("anchor_left", &LayerShellConfig::anchor_left)
        .def_readwrite("anchor_right", &LayerShellConfig::anchor_right)

        .def_readwrite(
            "exclusive_zone",
            &LayerShellConfig::exclusive_zone
        );

    py::class_<LayerShellAdapter>(
        m,
        "LayerShellAdapter"
    )
        .def(py::init<>())

        .def(
            "available",
            &LayerShellAdapter::available
        )

        .def(
            "initialize_from_pointer",
            &LayerShellAdapter::initialize_from_pointer
        )

        .def(
            "initialize_from_address",
            &LayerShellAdapter::initialize_from_pointer
        );
}
