//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_TESTCLEARCOLOR_H
#define OPENGLTUT_TESTCLEARCOLOR_H

#include "test.h"
namespace test {

    class TestClearColor : public Test {
    public:
        TestClearColor();
        ~TestClearColor() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;

    private:
        float m_ClearColor[4];
    };
}


#endif //OPENGLTUT_TESTCLEARCOLOR_H
