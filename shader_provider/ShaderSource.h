//
// Created by pioziol on 11.08.2019.
//

#ifndef OPENGLTUT_SHADERSOURCE_H
#define OPENGLTUT_SHADERSOURCE_H

//#include "../src/Renderer.h"
#include "iostream"
#include "fstream"
#include "string"
#include "sstream"


    class ShaderSource {
    private:
        std::string filePath;
        std::string sourceCode;
    public:
        unsigned int id;
        int type;
        ShaderSource(int type, std::string filePath);

        void loadSourceCode();

        void compile();

        void remove();
    };


#endif //OPENGLTUT_SHADERSOURCE_H
