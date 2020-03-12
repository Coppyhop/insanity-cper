cmake_minimum_required(VERSION 3.17)
project(iSweep)
set(CMAKE_CXX_FLAGS "-mwindows")
set(TARGET_H
    engine.h
)
set(TARGET_SRC
    WindowManager.cpp
)
add_executable(iSweep src/main.cpp src/WindowManager.cpp)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw-3.3.2)
find_package(OpenGL REQUIRED)
target_link_libraries(iSweep glfw)
target_link_libraries(iSweep OpenGL::GL)