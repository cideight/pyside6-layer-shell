# Build

## Voraussetzungen

Arch Linux

```bash
sudo pacman -S \
    cmake \
    ninja \
    gcc \
    qt6-base \
    layer-shell-qt \
    pybind11
```

Python

```bash
python -m venv .venv

source .venv/bin/activate

pip install PySide6
```

---

## Build

```bash
mkdir build

cd build

cmake ..

cmake --build .
```

---

## Ergebnis

Es werden erzeugt:

```
layer-shell-test

layer_shell_native.so
```

---

## Test

```bash
./layer-shell-test
```

oder

```python
import layer_shell_native
```