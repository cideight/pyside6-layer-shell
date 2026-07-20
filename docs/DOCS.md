# FAQ

## Warum pybind11?

Die Bibliothek exportiert ausschließlich die eigene API.

Qt selbst wird nicht über pybind11 exportiert.

---

## Warum Shiboken?

PySide6 verwaltet bereits sämtliche Qt-Objekte.

Shiboken liefert den nativen QWidget-Zeiger.

---

## Warum nicht QWidget direkt exportieren?

Dadurch bliebe die Bibliothek an PySide6 gekoppelt.

Mit `initialize_from_address()` bleibt die C++-Bibliothek vollständig unabhängig von Python.

---

## Unterstützte Plattformen

Aktuell:

- Linux
- Wayland
- LayerShellQt

---

## Unterstützte Python-Versionen

Python 3.12+

---

## Unterstützte Qt-Versionen

Qt6