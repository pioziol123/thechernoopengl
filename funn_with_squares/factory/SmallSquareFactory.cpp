//
// Created by pioziol on 27.08.2019.
//

#include "SmallSquareFactory.h"
#include "../../shader_provider/ShaderProvider.h"

namespace square {
    Square SmallSquareFactory::create() {
        auto* va = new VertexArray;

        float positions[] = {
                0.50f, 0.50f,
                -0.50f, -0.50f,
                -0.50f, 0.50f,
                0.50f, -0.50f,
        };
        auto* vb = new VertexBuffer(positions, sizeof(float) * 2 * 4);
        auto *layout = new VertexBufferLayout;
        layout->Push<float>(2);
        va->AddBuffer(*vb, *layout);

        unsigned int indices[6] = {0, 1, 2, 0, 1, 3};
        auto* ib = new IndexBuffer(indices, 6);
        auto* shader  = new Shader;
        ShaderProvider shaderProvider;
        shader->addShader(*shaderProvider.createShader(Shaders::FunnyVertexShader));
        shader->addShader(*shaderProvider.createShader(Shaders::FunnyFragmentShader));
        shader->CreateShader();
        shader->Bind();
        return Square(ib, vb, va, layout, shader);
    }
}