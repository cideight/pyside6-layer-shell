# layer-shell-pyside6-bridge

> Eine native Brücke zwischen **PySide6**, **Shiboken6**, **pybind11** und **LayerShellQt** für Wayland.

## Motivation

LayerShellQt stellt eine komfortable C++-API für das Wayland Layer Shell Protocol bereit.

Für Python bzw. PySide6 existiert jedoch keine offizielle Anbindung.

Dieses Projekt schließt diese Lücke und zeigt einen sauberen Weg, LayerShellQt aus einer PySide6-Anwendung heraus zu verwenden.

Die Bibliothek ist bewusst in drei Schichten aufgebaut:

```
PySide6
    │
    ▼
Shiboken6
    │
    ▼
pybind11
    │
    ▼
LayerShellAdapter
    │
    ▼
LayerShellQt
    │
    ▼
Wayland
```

Dadurch bleibt die eigentliche LayerShellQt-Implementierung vollständig unabhängig von Python.

---

# Features

- LayerShellQt Adapter
- pybind11 Python Binding
- PySide6 Integration
- Multi-Monitor-Unterstützung
- Layer-Konfiguration
- Anchors
- Margins
- Exclusive Zone
- Native QWidget-Bridge

---

# Projektstruktur

```
layer-shell-pyside6-bridge/

bindings/
    module.cpp

src/
    layer_shell_adapter.cpp
    layer_shell_adapter.h
    layer_shell_config.h

examples/
    cpp/
    python/

docs/

CMakeLists.txt
```

---

# Voraussetzungen

- C++20
- Qt6
- LayerShellQt
- pybind11
- PySide6
- Shiboken6
- CMake ≥ 3.20

---

# Build

```bash
mkdir build
cd build

cmake ..
cmake --build .
```

---

# Python

```python
from PySide6.QtWidgets import QApplication, QWidget
from shiboken6 import Shiboken

import layer_shell_native as ls

app = QApplication([])

widget = QWidget()

config = ls.LayerShellConfig()

adapter = ls.LayerShellAdapter()

ptr = Shiboken.getCppPointer(widget)[0]

adapter.initialize_from_address(
    ptr,
    config
)
```

---

# Status

Dieses Projekt ist aus der Entwicklung eines Wayland-Desktop-Widget-Frameworks entstanden. Ziel ist es, eine möglichst einfache und nachvollziehbare Referenzimplementierung für die Integration von LayerShellQt in PySide6-Anwendungen bereitzustellen. Entwicklung ist im Gange. 

---

# Lizenz

Dieses Projekt steht unter der LGPLv3-Lizenz und ist damit vollständig kompatibel mit den zugrundeliegenden Bibliotheken PySide6 und LayerShellQt.