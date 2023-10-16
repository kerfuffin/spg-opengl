cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(display VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(freeglut REQUIRED)
find_package(OpenGL REQUIRED)


add_executable(display main.cpp
        Window.h
        Core.h
        Drawable.h
        Components/Square.h)

target_link_libraries(display PRIVATE freeglut::freeglut)