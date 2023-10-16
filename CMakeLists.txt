cmake_minimum_required(VERSION 3.10)

project(display)
add_executable(display main.cpp
        Window.h
        Core.h
        Drawable.h
        Components/Square.h)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

add_dependencies(display OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS} )


target_link_libraries(display OpenGL::OpenGL GLUT::GLUT)