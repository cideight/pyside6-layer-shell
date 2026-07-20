#!/usr/bin/env python3

"""
Python-Beispiel für layer-shell-pyside6-bridge.
"""

import sys

from PySide6.QtWidgets import (
    QApplication,
    QWidget,
)

from shiboken6 import Shiboken

import layer_shell_native as ls


def main() -> int:

    app = QApplication(sys.argv)

    widget = QWidget()

    widget.resize(
        400,
        200,
    )

    config = ls.LayerShellConfig()

    config.screen = 0

    adapter = ls.LayerShellAdapter()

    pointer = Shiboken.getCppPointer(
        widget
    )[0]

    adapter.initialize_from_address(
        pointer,
        config,
    )

    widget.show()

    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())