# Verwendung aus Python

## Import

```python
import layer_shell_native as ls
```

---

## Konfiguration

```python
cfg = ls.LayerShellConfig()

cfg.screen = 1

cfg.width = 400
cfg.height = 200

cfg.anchor_top = True
cfg.anchor_left = True
```

---

## Adapter

```python
adapter = ls.LayerShellAdapter()
```

---

## QWidget

```python
from PySide6.QtWidgets import QWidget

widget = QWidget()
```

---

## Nativen Zeiger lesen

```python
from shiboken6 import Shiboken

ptr = Shiboken.getCppPointer(widget)[0]
```

---

## Initialisierung

```python
adapter.initialize_from_address(
    ptr,
    cfg
)
```