//
// Created by pioziol on 27.08.2019.
//

#include <Texture.h>
#include "TestTexture2D.h"
#include "../Renderer.h"
#include "../vendor/im_gui/imgui.h"
#include "../../shader_provider/ShaderProvider.h"

namespace test {
    TestTexture2D::TestTexture2D()
    : m_TranslationA(200, 100, 0), m_TranslationB(400, 400, 0)
    , m_Proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f))
    , m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
    {
        float positions[] = {
                -50.0f, -50.0f, 0.0f, 0.0f,
                50.0f, -50.0f, 1.0f, 0.0f,
                50.0f, 50.0f, 1.0f, 1.0f,
                -50.0f, 50.0f, 0.0f, 1.0f

        };
        unsigned int indices[6] = {
                0, 1, 2,
                2, 3, 0
        };

        GLCall(glEnable(GL_BLEND))
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA))
        m_VAO = std::make_unique<VertexArray>();
        m_Shader = std::make_unique<Shader>();
        m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);

        VertexBuffer vb(positions, sizeof(float) * 4 * 4);
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        m_VAO->AddBuffer(vb, layout);

        ShaderProvider shaderProvider;
        m_Shader->addShader(*shaderProvider.createShader(Shaders::BasicVertexShader));
        m_Shader->addShader(*shaderProvider.createShader(Shaders::BasicFragmentShader));
        m_Shader->CreateShader();
        m_Shader->Bind();

        m_Texture = std::make_unique<Texture>("/home/pioziol/CLionProjects/OpenGLTut/src/res/textures/flower.jpeg");
        m_Shader->SetUniform1i("u_Texture", 0);

        m_Shader->Unbind();
        m_VAO->Unbind();
        m_IndexBuffer->Unbind();
        vb.Unbind();
    }
    TestTexture2D::~TestTexture2D(){}
    void TestTexture2D::OnUpdate(float deltaTime) {}
    void TestTexture2D::OnRender() {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f))
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        Renderer renderer;
        m_Texture->Bind();
        m_Shader->Bind();
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);
            glm::mat4 mvp = m_Proj * m_View * model;
            m_Shader->SetUniformMat4f("u_MVP", mvp);
            renderer.Draw(*m_IndexBuffer, *m_VAO, *m_Shader);
        }
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationB);
            glm::mat4 mvp = m_Proj * m_View * model;
            m_Shader->SetUniformMat4f("u_MVP", mvp);
            renderer.Draw(*m_IndexBuffer, *m_VAO, *m_Shader);
        }
    }
    void TestTexture2D::OnImGuiRender() {
        ImGui::SliderFloat3("TranslationA", &m_TranslationA.x, 0.0f, 960.0f);
        ImGui::SliderFloat3("TranslationB", &m_TranslationB.x, 0.0f, 960.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
}