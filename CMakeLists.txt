cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2
find_package(SDL2 REQUIRED)

# Include directories
include_directories(src ${SDL2_INCLUDE_DIRS})

# Add executables
add_executable(GameEngine src/main.cpp)
add_executable(Blocks src/main_blocks.cpp)
add_executable(Parachutes src/main_parachutes.cpp)

# Link SDL2
target_link_libraries(GameEngine ${SDL2_LIBRARIES})
target_link_libraries(Blocks ${SDL2_LIBRARIES})
target_link_libraries(Parachutes ${SDL2_LIBRARIES})

# Compiler flags for optimization
if(MSVC)
    target_compile_options(GameEngine PRIVATE /W4 /O2)
    target_compile_options(Blocks PRIVATE /W4 /O2)
    target_compile_options(Parachutes PRIVATE /W4 /O2)
else()
    target_compile_options(GameEngine PRIVATE -Wall -Wextra -O2)
    target_compile_options(Blocks PRIVATE -Wall -Wextra -O2)
    target_compile_options(Parachutes PRIVATE -Wall -Wextra -O2)
endif()
