#!/usr/bin/env bash

# ============================================================
# PySide6 Layer Shell Installer
# ============================================================

# Bei einem Fehler das Skript sofort beenden
set -e

echo "========================================="
echo " PySide6 Layer Shell Installer"
echo "========================================="

# Benötigte Programme prüfen
for cmd in python3 cmake make g++; do
    if ! command -v "$cmd" >/dev/null 2>&1; then
        echo "Fehler: '$cmd' wurde nicht gefunden."
        echo "Bitte installiere das fehlende Programm und starte das Skript erneut."
        exit 1
    fi
done

# Prüfen, ob das Python-Modul 'venv' verfügbar ist
if ! python3 -m venv --help >/dev/null 2>&1; then
    echo "Fehler: Das Python-Modul 'venv' ist nicht verfügbar."
    echo "Bitte installiere das Paket 'python3-venv' und starte das Skript erneut."
    exit 1
fi

echo
echo "[1/6] Erstelle Python Virtual Environment..."

# Virtuelle Umgebung nur anlegen, wenn sie noch nicht existiert
if [ ! -d ".venv" ]; then
    python3 -m venv .venv
else
    echo "Virtuelle Umgebung existiert bereits."
fi

echo
echo "[2/6] Aktiviere Virtual Environment..."

# Virtuelle Umgebung aktivieren
source .venv/bin/activate

echo
echo "[3/6] Aktualisiere pip..."

# pip innerhalb der virtuellen Umgebung aktualisieren
python -m pip install --upgrade pip

echo
echo "[4/6] Installiere Python-Abhängigkeiten..."

# Python-Abhängigkeiten installieren
if [ -f "requirements.txt" ]; then
    python -m pip install -r requirements.txt
else
    echo "Warnung: Keine requirements.txt gefunden."
fi

echo
echo "[5/6] Konfiguriere und kompiliere das Projekt..."

# Build-Verzeichnis erstellen
mkdir -p build

# Projekt konfigurieren
cmake -S . -B build

# Projekt kompilieren
cmake --build build -j"$(nproc)"

echo
echo "[6/6] Installiere Python-Modul..."

# Zielverzeichnis der aktiven virtuellen Umgebung ermitteln
SITE_PACKAGES=$(python -c "import site; print(site.getsitepackages()[0])")

# Kompiliertes Python-Modul in die virtuelle Umgebung kopieren
MODULE=$(find build -maxdepth 1 -name "layer_shell_native*.so" | head -n 1)

if [ -z "$MODULE" ]; then
    echo "Fehler: Das Python-Modul 'layer_shell_native' wurde nicht gefunden."
    exit 1
fi

cp "$MODULE" "$SITE_PACKAGES/"

echo
echo "========================================="
echo " Installation erfolgreich abgeschlossen."
echo "========================================="

echo
echo "Das Python-Modul wurde installiert nach:"
echo "  $SITE_PACKAGES"

echo
echo "Führe nun folgende Befehle aus:"
echo
echo "    source .venv/bin/activate"
echo "    python examples/python/main.py"
echo