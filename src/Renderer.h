//
// Created by pioziol on 15.08.2019.
//

#ifndef OPENGLTUT_RENDERER_H
#define OPENGLTUT_RENDERER_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"

#include <string>
#include <csignal>
#include <iostream>
#include "VertexArray.h"
#include "IndexBuffer.h"
#define ASSERT(x) if (!(x)) std::raise(SIGINT);

#define GLCall(x) GL_ClearLogs();\
    x;\
    ASSERT(GL_GetLog(#x, __FILE__))

void error_callback(int error, const char *description);

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

void GL_ClearLogs();

bool GL_GetLog(const std::string& function, const std::string& file);

class Renderer {
public:
    void Draw(const IndexBuffer& ib, const VertexArray& va, const Shader &shader) const;

    void Clear() const;
};
#endif //OPENGLTUT_RENDERER_H
