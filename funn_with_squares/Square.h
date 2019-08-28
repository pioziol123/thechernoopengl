//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_SQUARE_H
#define OPENGLTUT_SQUARE_H

#include "Renderer.h"
#include "../src/VertexBuffer.h"

namespace square {
    class Square {
    private:
        IndexBuffer ib;
        VertexArray va;
        Shader shader;
        VertexBuffer vb;
        VertexBufferLayout layout;

    public:
        Square(const IndexBuffer& ib, const VertexBuffer& vb, const VertexArray& va, const VertexBufferLayout& layout, const Shader& shader);
        ~Square();
        void Draw(const Renderer& renderer) const;
        Shader* GetShader();
        void Unbind();
    };
}



#endif //OPENGLTUT_SQUARE_H
