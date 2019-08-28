//
// Created by pioziol on 27.08.2019.
//

#include "SmallSquareFactory.h"
#include "../../shader_provider/ShaderProvider.h"

namespace square {
    Square SmallSquareFactory::create() {
        VertexArray va;

        float positions[] = {
                0.50f, 0.50f,
                -0.50f, -0.50f,
                -0.50f, 0.50f,
                0.50f, -0.50f,
        };
        VertexBuffer vb(positions, sizeof(float) * 2 * 4);
        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        unsigned int indices[6] = {0, 1, 2, 0, 1, 3};
        IndexBuffer ib(indices, 6);
        Shader shader;
        ShaderProvider shaderProvider;
        shader.addShader(*shaderProvider.createShader(Shaders::FunnyVertexShader));
        shader.addShader(*shaderProvider.createShader(Shaders::FunnyFragmentShader));
        shader.CreateShader();
        shader.Bind();
        return Square(ib, vb, va, layout, shader);
    }
}