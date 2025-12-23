cmake_minimum_required(VERSION 3.15)
project(FluidSimulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# src files
add_executable(fluid_sim src/main.cpp)

if(WIN32)
    # raylib path
    set(RAYLIB_DIR "./libs/raylib/raylib-5.5_win64_msvc16")
    include_directories(${RAYLIB_DIR}/include)
    link_directories(${RAYLIB_DIR}/lib)
    # link the stuff
    target_link_libraries(fluid_sim PRIVATE raylib opengl32 gdi32 winmm)

elseif(APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(RAYLIB REQUIRED raylib)
    target_include_directories(fluid_sim PRIVATE ${RAYLIB_INCLUDE_DIRS})
    target_link_libraries(fluid_sim PRIVATE ${RAYLIB_LIBRARIES})
    target_link_directories(fluid_sim PRIVATE ${RAYLIB_LIBRARY_DIRS})

endif()