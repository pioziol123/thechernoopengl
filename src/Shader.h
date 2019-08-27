//
// Created by pioziol on 16.08.2019.
//

#ifndef OPENGLTUT_SHADER_H
#define OPENGLTUT_SHADER_H

#include "../shader_provider/ShaderSource.h"
#include <string>
#include <unordered_map>
#include <vector>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Shader {
private:
    unsigned int m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;
    std::vector<ShaderSource> shaders;
public:
    Shader();

    ~Shader();
    void Bind() const;
    void Unbind() const;
    int GetUniformLocation(const std::string &name);
    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    void SetUniform1i(const std::string &name, int value);
    void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
    void addShader(const ShaderSource& shader);
    unsigned int CreateShader();
};


#endif //OPENGLTUT_SHADER_H
