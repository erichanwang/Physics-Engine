cmake_minimum_required(VERSION 3.10)
project(GameEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src/math)
add_subdirectory(src/rendering)
add_subdirectory(src/objects)
add_subdirectory(src/physics)

# Add executables
add_executable(GameEngine src/main.cpp)
add_executable(Donut src/donut.c)
add_executable(Blocks src/main_blocks.cpp)
add_executable(Parachutes src/main_parachutes.cpp)

# Find SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(GameEngine PRIVATE SDL2::SDL2 Rendering Objects Physics)
target_link_libraries(Blocks PRIVATE Rendering Objects Physics)
target_link_libraries(Parachutes PRIVATE Rendering Objects Physics)
target_compile_definitions(GameEngine PRIVATE SDL_MAIN_HANDLED)

# Compiler flags for optimization
if(MSVC)
    target_compile_options(GameEngine PRIVATE /W4 /O2)
else()
    target_compile_options(GameEngine PRIVATE -Wall -Wextra -O2)
endif()
