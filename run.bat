@echo off
REM Create build directory if it doesn't exist
if not exist build (
    mkdir build
)

REM Change to build directory
cd build

REM Run CMake configuration
cmake ..

REM Build the project
cmake --build . --config Release

REM Run the executable
GameEngine.exe

REM Pause to see output
pause
