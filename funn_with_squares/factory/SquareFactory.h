//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_SQUAREFACTORY_H
#define OPENGLTUT_SQUAREFACTORY_H

#include "../Square.h"
namespace square {
    class SquareFactory {
    public:
        virtual Square create() = 0;
    };
}


#endif //OPENGLTUT_SQUAREFACTORY_H
