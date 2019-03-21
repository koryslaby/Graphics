cmake_minimum_required(VERSION 3.13)
project(graphics3_2 C CXX)

set(CMAKE_CXX_STANDARD 14)

link_directories(${CMAKE_SOURCE_DIR}/lib)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules" FORCE)

find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
find_package(GLFW3 REQUIRED)
MESSAGE(STATUS "GLFW3 included at ${GLFW3_INCLUDE_DIR}")
find_package(ASSIMP REQUIRED)
message(STATUS "ASSIMP included at ${ASSIMP_INCLUDE_DIR}")

if (WIN32)
    set(LIBS glfw3 opengl32 assimp)
elseif(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
    find_package(OpenGL REQUIRED)
    message(STATUS "OpenGL included at ${OpenGL_INCLUDE_DIR}")
    add_definitions(${OPENGL_DEFINITIONS})
    find_package(X11 REQUIRED)
    set(LIBS ${GLFW3_LIBRARY} X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread ${ASSIMP_LIBRARY})
    set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
else()
    set(LIBS)

endif (WIN32)

#may need to add
#configure_file(configuration/root_directory.h.in configuration/root_directory.h)
#include_directories(${CMAKE_BINARY_DIR}/configuration)

add_library(GLAD "src/glad.c" src/Cube.cpp src/Cube.h)
add_library(Shape "src/Shape.cpp")
set(LIBS ${LIBS} GLAD Shape)

macro(makeLink src dest target)
    add_custom_command(TARGET ${target} POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${src} ${dest} DEPENDS ${dest} COMMENT "mklink ${src} -> ${dest}")

endmacro()

set(SRCFILES
        src/shader.vs
        src/shader.fs
        src/shader.h
        src/Shape.h
)



foreach(SRCFILES ${SRCFILES})
    file(GLOB SOURCE
            "${SRCFILES}"
            )

endforeach(SRCFILES)

enable_language(CXX)
add_executable(graphics3_2 src/main.cpp ${SOURCE})
target_link_libraries(graphics3_2 ${LIBS})

include_directories(${CMAKE_SOURCE_DIR}/includes)


