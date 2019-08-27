//
// Created by pioziol on 15.08.2019.
//

#ifndef OPENGLTUT_VERTEXARRAY_H
#define OPENGLTUT_VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
private:
    unsigned int m_RendererID;
public:
    VertexArray();

    ~VertexArray();

     void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    void Bind() const;

    void Unbind() const;

};


#endif //OPENGLTUT_VERTEXARRAY_H
