#include <QApplication>
#include <QWidget>

#include "layer_shell_adapter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;

    widget.resize(
        400,
        200
    );

    LayerShellConfig config;

    config.screen = 1;

    config.anchor_top = false;
    config.anchor_bottom = true;

    config.anchor_left = false;
    config.anchor_right = true;

    config.width = 400;
    config.height = 200;

    LayerShellAdapter adapter;

    adapter.initialize(
        widget,
        config
    );

    widget.show();

    return app.exec();
}