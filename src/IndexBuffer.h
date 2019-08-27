//
// Created by pioziol on 15.08.2019.
//

#ifndef OPENGLTUT_INDEXBUFFER_H
#define OPENGLTUT_INDEXBUFFER_H


class IndexBuffer {
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);

    ~IndexBuffer();

    void Bind() const;

    void Unbind() const;

    unsigned int GetCount() const;
};


#endif //OPENGLTUT_INDEXBUFFER_H
