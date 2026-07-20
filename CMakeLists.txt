cmake_minimum_required(VERSION 3.20)

project(layer-shell-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(LayerShellQt REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED)

#
# Gemeinsame Bibliothek
#

add_library(
    layer_shell_core

    src/layer_shell_adapter.cpp
)

target_link_libraries(
    layer_shell_core

    PUBLIC

        Qt6::Widgets
        LayerShellQt::Interface
)

target_include_directories(
    layer_shell_core

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#
# Testprogramm
#

add_executable(
    layer-shell-test

    src/main.cpp
)

target_link_libraries(
    layer-shell-test

    PRIVATE

        layer_shell_core
)

#
# Python-Modul
#

pybind11_add_module(
    layer_shell_native

    bindings/module.cpp
)

target_link_libraries(
    layer_shell_native

    PRIVATE

        layer_shell_core
)