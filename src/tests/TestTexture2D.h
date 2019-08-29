//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_TESTTEXTURE2D_H
#define OPENGLTUT_TESTTEXTURE2D_H

#include <memory>
#include "test.h"
namespace test {

    class TestTexture2D : public Test {
    public:
        TestTexture2D();
        ~TestTexture2D() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;

    private:
        glm::vec3 m_TranslationA, m_TranslationB;
        glm::mat4 m_Proj, m_View;
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<Texture> m_Texture;
    };
}


#endif //OPENGLTUT_TESTTEXTURE2D_H
