cmake_minimum_required(VERSION 3.15)
project(FluidSimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# raylib path
set(RAYLIB_DIR "./libs/raylib/raylib-5.5_win64_msvc16")
include_directories(${RAYLIB_DIR}/include)
link_directories(${RAYLIB_DIR}/lib)

# src files
add_executable(fluid_sim src/main.cpp)

# link the stuff
target_link_libraries(fluid_sim PRIVATE raylib opengl32 gdi32 winmm)