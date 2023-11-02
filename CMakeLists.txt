cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
project(display)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

add_subdirectory(extern/pybind11)
pybind11_add_module(display main.cpp
        Window.h
        Core.h
        Abstracts/Drawable.h
        Components/Simple/Square.h
        Components/Simple/Line.h
        Structures/Color.h
        Structures/Vec2.h
        Views/FilePicker.h
        Abstracts/View.h
        Components/Simple/Text.h
        Components/Simple/Rectangle.h
        Components/Complex/Button.h)

target_compile_definitions(display PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

add_dependencies(display OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS} )

target_link_libraries(display PRIVATE OpenGL::OpenGL GLUT::GLUT)