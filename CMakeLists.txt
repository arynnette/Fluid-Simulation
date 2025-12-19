cmake_minimum_required(VERSION 3.15)
project(FluidSimulation)

set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find libraries
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/shader.cpp
)

# Create executable
add_executable(fluid_sim ${SOURCES})

# Link libraries
target_link_libraries(fluid_sim PRIVATE 
    glfw 
    GLEW::GLEW 
    glm::glm
    imgui::imgui
)

# Copy shaders to build directory
file(COPY ${CMAKE_SOURCE_DIR}/shaders DESTINATION ${CMAKE_BINARY_DIR})