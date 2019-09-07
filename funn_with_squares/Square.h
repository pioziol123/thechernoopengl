//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_SQUARE_H
#define OPENGLTUT_SQUARE_H

#include <Texture.h>
#include "Renderer.h"
#include "../src/VertexBuffer.h"

namespace square {
    class Square {
    private:
        IndexBuffer *ib;
        VertexArray* va;
        Shader* shader;
        VertexBuffer* vb;
        VertexBufferLayout* layout;
        Texture *texture;
    public:
        Square(IndexBuffer* ib, VertexBuffer* vb, VertexArray* va, VertexBufferLayout* layout, Shader* shader);
        ~Square();
        void Draw(const Renderer& renderer) const;
        Shader* GetShader();
        void BindTexture(Texture* pTexture);
        void Unbind();
    };
}



#endif //OPENGLTUT_SQUARE_H
