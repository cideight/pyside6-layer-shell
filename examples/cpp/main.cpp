/*
 * Einfaches Beispiel für LayerShellQt.
 */

#include <QApplication>
#include <QWidget>

#include "layer_shell_adapter.h"

int main(
    int argc,
    char* argv[]
)
{
    QApplication app(
        argc,
        argv
    );

    QWidget widget;

    widget.resize(
        400,
        200
    );

    LayerShellConfig config;

    config.screen = 0;

    config.anchor_top = false; //oben
    config.anchor_bottom = true; //unten

    config.anchor_left = false;  //links
    config.anchor_right = true;  //rechts


    LayerShellAdapter adapter;

    adapter.initialize(
        widget,
        config
    );

    widget.show();

    return app.exec();
}