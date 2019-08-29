cmake_minimum_required(VERSION 3.14)
project(OpenGLTut)
include_directories(src/vendor/glm/glm/ src)
#include_directories(src/vendor/)
set(CMAKE_CXX_STANDARD 17)
set(SHADER_PROVIDER_SOURCES
        shader_provider/ShaderProvider.cpp
        shader_provider/ShaderProvider.h
        shader_provider/ShaderSource.cpp
        shader_provider/ShaderSource.h)
set(SRC_FILES
        src/Renderer.cpp
        src/Renderer.h
        src/IndexBuffer.cpp
        src/IndexBuffer.h
        src/VertexBuffer.cpp
        src/VertexBuffer.h
        src/VertexBufferLayout.h
        src/VertexBufferLayout.cpp
        src/VertexArray.h
        src/VertexArray.cpp
        src/Shader.h
        src/Shader.cpp
        src/Texture.cpp
        src/Texture.h
)
set (VENDORS
        src/vendor/stb_image/stb_image.cpp
        src/vendor/stb_image/stb_image.h
        src/vendor/im_gui/imgui.h
        src/vendor/im_gui/imgui.cpp
        src/vendor/im_gui/imgui_impl_glfw_gl3.cpp
        src/vendor/im_gui/imgui_impl_glfw_gl3.h
        src/vendor/im_gui/imconfig.h
        src/vendor/im_gui/imgui_internal.h
        src/vendor/im_gui/stb_rect_pack.h
        src/vendor/im_gui/stb_truetype.h
        src/vendor/im_gui/imgui_draw.cpp
        src/vendor/im_gui/imgui_demo.cpp
)

set (TESTS
        src/tests/test.h
        src/tests/test.cpp
        src/tests/TestClearColor.cpp
        src/tests/TestClearColor.h
        src/tests/TestTexture2D.cpp
        src/tests/TestTexture2D.h
        )
set(SOURCE_FILES main.cpp ${VENDORS}  ${SRC_FILES} ${SHADER_PROVIDER_SOURCES} ${TESTS})
add_executable(OpenGLTut ${SOURCE_FILES})

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(OpenGLTut glfw)
find_package(OpenGL REQUIRED)
target_include_directories(OpenGLTut PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(OpenGLTut ${OPENGL_LIBRARY})
find_package(GLEW REQUIRED)
target_include_directories(OpenGLTut PUBLIC ${GLEW_INCLUDE_DIR})
target_link_libraries(OpenGLTut ${GLEW_LIBRARY})
