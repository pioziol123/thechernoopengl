//
// Created by pioziol on 15.08.2019.
//

#ifndef OPENGLTUT_VERTEXBUFFERLAYOUT_H
#define OPENGLTUT_VERTEXBUFFERLAYOUT_H

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement {
    unsigned int type;
    int count;
    bool normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:
            case GL_UNSIGNED_INT:
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
            default:
                return 0;
        }
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
public:
    VertexBufferLayout()
    : m_Stride(0)
    {}


    template<typename T>
    void Push(int count) {}

    inline const std::vector<VertexBufferElement> GetElements() const { return this->m_Elements; }

    inline unsigned int GetStride() const { return this->m_Stride; }
};

#endif //OPENGLTUT_VERTEXBUFFERLAYOUT_H
