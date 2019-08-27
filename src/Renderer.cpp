//
// Created by pioziol on 15.08.2019.
//
#include "Renderer.h"

void GL_ClearLogs() {
    while(glGetError());
}

bool GL_GetLog(const std::string& function, const std::string& file) {
    if (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error occurred] Error: " << error << " function: " << function << " file: " << file << std::endl;
        return false;
    }
    return true;
}

void error_callback(int error, const char *description) {
    std::cout << "error: " << error <<" description: " << description << std::endl;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        GLCall(glfwSetWindowShouldClose(window, GL_TRUE))
}

void Renderer::Draw(const IndexBuffer &ib, const VertexArray &va, const Shader &shader) const{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT))

}
