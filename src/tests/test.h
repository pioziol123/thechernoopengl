//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_TEST_H
#define OPENGLTUT_TEST_H

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
}

#endif //OPENGLTUT_TEST_H
