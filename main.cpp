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
#include "funn_with_squares/factory/SmallSquareFactory.h"
#include "funn_with_squares/factory/SquareFactory.h"

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
        GLCall(glEnable(GL_BLEND))
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA))
//
        square::SmallSquareFactory smallSquareFactory;
        square::Square smallSquare = smallSquareFactory.create();
//        VertexArray va;
//
//        float positions[] = {
//                0.50f, 0.50f,
//                -0.50f, -0.50f,
//                -0.50f, 0.50f,
//                0.50f, -0.50f,
//        };
//        VertexBuffer vb(positions, sizeof(float) * 2 * 4);
//        VertexBufferLayout layout;
//        layout.Push<float>(2);
//        va.AddBuffer(vb, layout);
//        unsigned int indices[6] = {0, 1, 2, 0, 1, 3};
//        IndexBuffer ib(indices, 6);
//        Shader shader;
//        ShaderProvider shaderProvider;
//        shader.addShader(*shaderProvider.createShader(Shaders::FunnyVertexShader));
//        shader.addShader(*shaderProvider.createShader(Shaders::FunnyFragmentShader));
//        shader.CreateShader();
//        shader.Bind();
//
//        square::Square smallSquare(ib, vb, va, layout, shader);
//        Shader *shader = smallSquare.GetShade00r();
//        ShaderProvider shaderProvider;
//        shader->addShader(*shaderProvider.createShader(Shaders::FunnyVertexShader));
//        shader->addShader(*shaderProvider.createShader(Shaders::FunnyFragmentShader));
//        shader->CreateShader();

        smallSquare.Unbind();

//        va.Unbind();
//        vb.Unbind();
//        shader.Unbind();
//        ib.Unbind();
        Renderer renderer;
//        ImGui::CreateContext();
//        ImGui_ImplGlfwGL3_Init(window, true);
//        ImGui::StyleColorsDark();
        while (!glfwWindowShouldClose(window)) {
            renderer.Clear();
//            ImGui_ImplGlfwGL3_NewFrame();
            smallSquare.Draw(renderer);
//            renderer.Draw(ib, va, shader);
//            ImGui::Render();
//            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
//    ImGui_ImplGlfwGL3_Shutdown();
//    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}