#pragma once

/*
 * Adapter für LayerShellQt.
 */

#include <cstdint>

#include <QWidget>

#include "layer_shell_config.h"

class LayerShellAdapter
{
public:
    /*
     * Initialisiert LayerShellQt für das angegebene Fenster.
     */
    void initialize(
        QWidget& widget,
        const LayerShellConfig& config
    );

    /*
     * Initialisiert LayerShellQt über die Speicheradresse
     * eines QWidget.
     */
    void initialize_from_pointer(
        std::uintptr_t pointer,
        const LayerShellConfig& config
    );

    /*
     * Prüft, ob der Adapter verfügbar ist.
     */
    bool available() const;
};