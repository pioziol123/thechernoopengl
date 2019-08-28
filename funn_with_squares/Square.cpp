//
// Created by pioziol on 27.08.2019.
//

#include "Square.h"

namespace square {
    Square::Square(const IndexBuffer& ib, const VertexBuffer& vb, const VertexArray& va, const VertexBufferLayout& layout, const Shader& shader) : ib(ib), vb(vb), va(va), layout(layout), shader(shader)
    {}

    Square::~Square() {

    }
    void Square::Unbind() {
        shader.Unbind();
        va.Unbind();
        ib.Unbind();
        vb.Unbind();
    }
    Shader* Square::GetShader() {
        return &this->shader;
    }

    void Square::Draw(const Renderer &renderer) const{
        renderer.Draw(ib, va, shader);
    }
}


