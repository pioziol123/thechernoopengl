//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_TEST_H
#define OPENGLTUT_TEST_H

#include <functional>
#include <iostream>

namespace test {
    class Test {
    public:
        Test() {

        }
        virtual ~Test() {}

        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void OnImGuiRender() {}
    };
    class TestMenu : public Test {
    public:
        TestMenu() = default;
        explicit TestMenu(Test*& currentTestPointer);
        ~TestMenu() override = default;

        void OnImGuiRender() override;

        template<typename T>
        void RegisterTest(const std::string& name) {
            std::cout << "Registering test " << name << std::endl;
            m_Tests.push_back(std::make_pair(name, []() {return new T();}));
        }

    private:
        Test*& m_CurrentTest;
        std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;
    };
}

#endif //OPENGLTUT_TEST_H
