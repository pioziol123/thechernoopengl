#include <iostream>
#include "src/Renderer.h"
#include "src/VertexBufferLayout.h"
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
        square::SmallSquareFactory smallSquareFactory;
        square::Square smallSquare = smallSquareFactory.create();

        smallSquare.Unbind();
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