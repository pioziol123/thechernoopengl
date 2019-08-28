//
// Created by pioziol on 11.08.2019.
//

#ifndef OPENGLTUT_SHADERPROVIDER_H
#define OPENGLTUT_SHADERPROVIDER_H

#include <string>
#include "ShaderSource.h"

enum Shaders {
    BasicVertexShader, BasicFragmentShader, FunnyVertexShader, FunnyFragmentShader
};


struct ShaderType {
    int type;
    std::string filePath;
};

class ShaderProvider {
private:
    ShaderType types[4]{};
public:
    ShaderProvider();
    ShaderSource* createShader(Shaders shaderType);
};


#endif //OPENGLTUT_SHADERPROVIDER_H
