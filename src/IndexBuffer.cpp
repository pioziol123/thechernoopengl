//
// Created by pioziol on 15.08.2019.
//
#include <GL/glew.h>
#include "Renderer.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
{
    GLCall(glGenBuffers(1, &this->m_RendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_RendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    m_Count = count;
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &this->m_RendererID));
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_RendererID));
}

void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount() const {
    return this->m_Count;
}
