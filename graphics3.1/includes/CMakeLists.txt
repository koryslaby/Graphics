add_library(GLAD
        glad/glad.h)

set_target_properties(GLAD PROPERTIES LINKER_LANGUAGE C)

add_library(GL
        GL/glew.h
        GL/glxew.h
        GL/wglew.h)

set_target_properties(GL PROPERTIES LINKER_LANGUAGE CXX)

add_library(GLFW
        GLFW/glfw3.h
        GLFW/glfw3native.h)

set_target_properties(GLFW PROPERTIES LINKER_LANGUAGE C)

add_library(Shaders
        shaders/shader.h)

target_link_libraries(Shaders PRIVATE GLAD)

set_target_properties(Shaders PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Shaders PRIVATE GLAD)

add_library(Shape
        shape/Shape.cpp
        shape/Shape.h)

target_link_libraries(Shape PRIVATE Shaders)



include_directories(${CMAKE_SOURCE_DIR}/includes)
message("cmake_source_dir is:" ${CMAKE_SOURCE_DIR}/includes)
