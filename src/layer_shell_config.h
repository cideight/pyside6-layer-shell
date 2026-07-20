#pragma once

/*
 * Konfigurationsobjekt für LayerShellQt.
 */

enum class Layer
{
    Background,
    Bottom,
    Top,
    Overlay,
};

enum class ScreenMode
{
    Active,
    Index,
};

struct LayerShellConfig
{
    Layer layer = Layer::Top;

    int screen = 0;

    ScreenMode screen_mode = ScreenMode::Index;

    int width = 400;
    int height = 200;

    int margin_left = 0;
    int margin_top = 0;
    int margin_right = 0;
    int margin_bottom = 0;

    bool anchor_top = true;
    bool anchor_bottom = false;

    bool anchor_left = true;
    bool anchor_right = false;

    int exclusive_zone = 0;
};