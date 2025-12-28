cmake_minimum_required(VERSION 3.15)
project(FluidSimulation LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

# src files
add_executable(fluid_sim 
    src/main.cpp
    src/collision.cpp
)

if(WIN32)
    # raylib path
    set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/libs/raylib/raylib-5.5_win64_msvc16")
    
    target_include_directories(fluid_sim PRIVATE ${RAYLIB_DIR}/include)
    target_link_directories(fluid_sim PRIVATE ${RAYLIB_DIR}/lib)
    
    # link the stuff
    target_link_libraries(fluid_sim PRIVATE raylib opengl32 gdi32 winmm)
    
elseif(APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(RAYLIB REQUIRED raylib)
    target_include_directories(fluid_sim PRIVATE ${RAYLIB_INCLUDE_DIRS})
    target_link_libraries(fluid_sim PRIVATE ${RAYLIB_LIBRARIES})
    target_link_directories(fluid_sim PRIVATE ${RAYLIB_LIBRARY_DIRS})
else()
    message("Targeting an unknown system")
endif()