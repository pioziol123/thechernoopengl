#include <iostream>
#include "src/Renderer.h"
#include "src/Shader.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/VertexArray.h"
#include "src/VertexBufferLayout.h"
#include "shader_provider/ShaderProvider.h"
#include "src/Texture.h"
#include "src/vendor/im_gui/imgui.h"
#include "src/vendor/im_gui/imgui_impl_glfw_gl3.h"
#include "src/tests/TestClearColor.h"
int main() {

    GLCall(glfwSwapInterval(1));
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    GLFWwindow *window = glfwCreateWindow(960, 540, "Simple example", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    if (glewInit() != GLEW_OK) {
        GLCall(glfwTerminate());
        std::cout << "Something went wrong!" << std::endl;
        exit(EXIT_FAILURE);
    }
    {
//        float positions[] = {
//                -0.5f, -0.5f,
//                0.5f, -0.5f,
//                0.5f, 0.5f,
//                -0.5f, 0.5f,
//        };
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

        VertexArray va;
        VertexBuffer vb(positions, sizeof(float) * 4 * 4);
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

        Shader shader;
        ShaderProvider shaderProvider;
        shader.addShader(*shaderProvider.createShader(Shaders::BasicVertexShader));
        shader.addShader(*shaderProvider.createShader(Shaders::BasicFragmentShader));
        shader.CreateShader();
        shader.Bind();

        Texture texture("/home/pioziol/CLionProjects/OpenGLTut/src/res/textures/flower.jpeg");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);

        shader.Unbind();
        va.Unbind();
        ib.Unbind();
        vb.Unbind();

        glm::vec3 translationA(200, 100, 0);
        glm::vec3 translationB(400, 400, 0);
        Renderer renderer;
        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(window, true);
        ImGui::StyleColorsDark();


        while (!glfwWindowShouldClose(window)) {
            renderer.Clear();
            ImGui_ImplGlfwGL3_NewFrame();
            shader.Bind();
            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
                glm::mat4 mvp = proj * view * model;
                shader.SetUniformMat4f("u_MVP", mvp);
                renderer.Draw(ib, va, shader);
            }
            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
                glm::mat4 mvp = proj * view * model;
                shader.SetUniformMat4f("u_MVP", mvp);
                renderer.Draw(ib, va, shader);
            }
            {
                ImGui::Text("Hello, world!");
                ImGui::SliderFloat3("TranslationA", &translationA.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("TranslationB", &translationB.x, 0.0f, 960.0f);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            }

            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}