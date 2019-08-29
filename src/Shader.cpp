//
// Created by pioziol on 16.08.2019.
//
#include "Shader.h"
#include "Renderer.h"

Shader::Shader() {
    GLCall(m_RendererID = glCreateProgram());
}

Shader::~Shader() {
    GLCall(glDeleteProgram(m_RendererID))
}

void Shader::Bind() const {
    GLCall(glUseProgram(m_RendererID))
}

void Shader::Unbind() const {
    GLCall(glUseProgram(0))
}

int Shader::GetUniformLocation(const std::string &name) {
    if (this->m_UniformLocationCache.find(name) != this->m_UniformLocationCache.end()) {
        return this->m_UniformLocationCache[name];
    }
    GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()))
    if (location == -1) {
        std::cout << "Warning! Uniform '" << name << "' doesn't exist!" << std::endl;
    }
    this->m_UniformLocationCache[name] = location;
    return location;
}

void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
    GLCall(glUniform4f(this->GetUniformLocation(name), v0, v1, v2, v3))
}
void Shader::SetUniform1i(const std::string &name, int value) {
    GLCall(glUniform1i(this->GetUniformLocation(name), value))
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix ) {
    GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]))
}

unsigned int Shader::CreateShader() {
    for (const ShaderSource &shader : shaders) {
        GLCall(glAttachShader(m_RendererID, shader.id))
    }
    GLCall(glLinkProgram(m_RendererID))
    GLCall(glValidateProgram(m_RendererID))
    for (ShaderSource shader : shaders) {
        shader.remove();
    }
    return m_RendererID;
}

void Shader::addShader(const ShaderSource &shader) {
    shaders.push_back(shader);
}