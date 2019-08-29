//
// Created by pioziol on 28.08.2019.
//

#include <vendor/im_gui/imgui.h>
#include "test.h"

namespace test {
    TestMenu::TestMenu(Test*& currentTestPointer) : m_CurrentTest(currentTestPointer){}

       void TestMenu::OnImGuiRender() {
        for (auto& test : m_Tests) {
            if (ImGui::Button(test.first.c_str())) {
                m_CurrentTest = test.second();
            }
        }
    }
}