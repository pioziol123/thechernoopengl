//
// Created by pioziol on 15.08.2019.
//

#ifndef OPENGLTUT_VERTEXBUFFER_H
#define OPENGLTUT_VERTEXBUFFER_H


class VertexBuffer
{
private:
    unsigned int m_RendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};


#endif //OPENGLTUT_VERTEXBUFFER_H
