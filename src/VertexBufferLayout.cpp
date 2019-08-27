//
// Created by pioziol on 16.08.2019.
//

#include "VertexBufferLayout.h"

template<>
void VertexBufferLayout::Push<float>(int count) {
    this->m_Elements.push_back({GL_FLOAT, count, false});
    this->m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
}

template<>
void VertexBufferLayout::Push<unsigned int>(int count) {
    this->m_Elements.push_back({GL_UNSIGNED_INT, count, false});
    this->m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
}

template<>
void VertexBufferLayout::Push<unsigned char>(int count) {
    this->m_Elements.push_back({GL_UNSIGNED_BYTE, count, false});
    this->m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
}