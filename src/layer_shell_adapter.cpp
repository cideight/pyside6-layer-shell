/*
 * Adapter für LayerShellQt.
 */

#include "layer_shell_adapter.h"
#include <iostream>
#include <QGuiApplication>
#include <QMargins>
#include <QSize>

#include <LayerShellQt/window.h>

bool LayerShellAdapter::available() const
{
    return true;
}

void LayerShellAdapter::initialize_from_pointer(
    std::uintptr_t pointer,
    const LayerShellConfig& config
)
{
    auto* widget = reinterpret_cast<QWidget*>(pointer);

    if (!widget) {
        return;
    }

    initialize(
        *widget,
        config
    );
}

void LayerShellAdapter::initialize(
    QWidget& widget,
    const LayerShellConfig& config
)
{
    std::cout
        << "\n=== LayerShellConfig ===\n"
        << "screen: " << config.screen << '\n'
        << "top: " << config.anchor_top << '\n'
        << "bottom: " << config.anchor_bottom << '\n'
        << "left: " << config.anchor_left << '\n'
        << "right: " << config.anchor_right << '\n'
        << "width: " << config.width << '\n'
        << "height: " << config.height << '\n'
        << "margin_left: " << config.margin_left << '\n'
        << "margin_top: " << config.margin_top << '\n'
        << "margin_right: " << config.margin_right << '\n'
        << "margin_bottom: " << config.margin_bottom << '\n'
        << "exclusive_zone: " << config.exclusive_zone << '\n'
        << "========================\n";

    widget.createWinId();

    auto* layerWindow = LayerShellQt::Window::get(
        widget.windowHandle()
    );

    if (!layerWindow) {
        return;
    }

    //
    // Zuerst den Zielbildschirm festlegen.
    //
    switch (config.screen_mode) {

    case ScreenMode::Active:
        layerWindow->setWantsToBeOnActiveScreen(
            true
        );
        break;

    case ScreenMode::Index:
    {
        const auto screens = QGuiApplication::screens();

        if (
            config.screen >= 0
            && config.screen < screens.size()
        ) {
            layerWindow->setScreen(
                screens.at(config.screen)
            );
        }

        break;
    }
    }

    switch (config.layer) {

    case Layer::Background:
        layerWindow->setLayer(
            LayerShellQt::Window::LayerBackground
        );
        break;

    case Layer::Bottom:
        layerWindow->setLayer(
            LayerShellQt::Window::LayerBottom
        );
        break;

    case Layer::Top:
        layerWindow->setLayer(
            LayerShellQt::Window::LayerTop
        );
        break;

    case Layer::Overlay:
        layerWindow->setLayer(
            LayerShellQt::Window::LayerOverlay
        );
        break;
    }

    LayerShellQt::Window::Anchors anchors;

    if (config.anchor_top) {
        anchors |= LayerShellQt::Window::AnchorTop;
    }

    if (config.anchor_bottom) {
        anchors |= LayerShellQt::Window::AnchorBottom;
    }

    if (config.anchor_left) {
        anchors |= LayerShellQt::Window::AnchorLeft;
    }

    if (config.anchor_right) {
        anchors |= LayerShellQt::Window::AnchorRight;
    }

    layerWindow->setAnchors(
        anchors
    );

    layerWindow->setMargins(
        QMargins(
            config.margin_left,
            config.margin_top,
            config.margin_right,
            config.margin_bottom
        )
    );

    layerWindow->setExclusiveZone(
        config.exclusive_zone
    );

    layerWindow->setDesiredSize(
        QSize(
            config.width,
            config.height
        )
    );
}