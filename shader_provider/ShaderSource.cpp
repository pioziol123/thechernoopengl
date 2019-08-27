//
// Created by pioziol on 11.08.2019.
//
#include "../src/Renderer.h"
#include "ShaderSource.h"

    ShaderSource::ShaderSource(int type, std::string filePath) {
        this->filePath = filePath;
        this->type = type;
    }

    void ShaderSource::loadSourceCode() {
        std::ifstream stream(this->filePath);
        std::string line;
        std::stringstream source;
        while (getline(stream, line)) {
            source << line << "\n";
        }
        this->sourceCode = source.str();
    }

    void ShaderSource::compile() {
        GLCall(this->id = glCreateShader(this->type));
        if (this->sourceCode.empty()) {
            throw "Source code has to be read before compilation!";
        }
        const char *src = this->sourceCode.c_str();
        GLCall(glShaderSource(this->id, 1, &src, nullptr));
        GLCall(glCompileShader(this->id));
        int result;
        GLCall(glGetShaderiv(this->id, GL_COMPILE_STATUS, &result));
        if (result == GL_FALSE) {
            int length;
            GLCall(glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &length));
            char *message = (char *) alloca(length * sizeof(char));
            GLCall(glGetShaderInfoLog(this->id, length, &length, message));
            std::cout << "Failed to compile a " << (this->type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                      << " shader!" << std::endl;
            std::cout << message << std::endl;
            GLCall(glDeleteShader(this->id));
            throw "ShaderSource didn't compile!";
        }
    }

    void ShaderSource::remove() {
        GLCall(glDeleteShader(this->id));
    }
