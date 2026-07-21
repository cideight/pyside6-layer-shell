# Changelog

## v.0.1.1

### Hinzugefügt

- Installationsskript (`install.sh`) zum automatischen Erstellen einer Python-Virtual-Environment und Kompilieren des Projekts.
- `requirements.txt` zur Verwaltung der Python-Abhängigkeiten.
- Installationsanleitung in der `README.md` ergänzt.
- Kleiner Fix: alias "initialize_from_address" in module.cpp ergänzt.

## v0.1.0

### Hinzugefügt

- Erste Referenzimplementierung der Bibliothek.
- LayerShellAdapter implementiert.
- LayerShellConfig implementiert.
- pybind11-Binding erstellt.
- Python-API für LayerShellConfig und LayerShellAdapter.
- Unterstützung für Layer, Anchors, Margins, Größe und Exclusive Zone.
- Brücke zwischen PySide6 und LayerShellQt über Shiboken6.
- Referenzbeispiele für C++ und Python.
- Dokumentation und Build-Anleitung.