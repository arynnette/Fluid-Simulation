@echo off
cd /d "%~dp0"               :: the script directory
rmdir /s /q build           :: recursive deletion, quiet (so there's no freaking stupid confirmiation)
cmake -B build
cmake --build build
build\Debug\fluid_sim.exe