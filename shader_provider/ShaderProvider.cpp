//
// Created by pioziol on 11.08.2019.
//

#include <GL/glew.h>
#include "ShaderProvider.h"

ShaderProvider::ShaderProvider() {
    this->types[Shaders::BasicFragmentShader] = {GL_FRAGMENT_SHADER, "/home/pioziol/CLionProjects/OpenGLTut/src/shaders/FragmentShader.cpp"};
    this->types[Shaders::BasicVertexShader] = {GL_VERTEX_SHADER, "/home/pioziol/CLionProjects/OpenGLTut/src/shaders/VertexShader.cpp"};
}

ShaderSource* ShaderProvider::createShader(Shaders shaderType) {
    auto* shader = new ShaderSource(this->types[shaderType].type, this->types[shaderType].filePath);
    shader->loadSourceCode();
    shader->compile();
    return shader;
}