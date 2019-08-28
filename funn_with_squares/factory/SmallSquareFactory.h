//
// Created by pioziol on 27.08.2019.
//

#ifndef OPENGLTUT_SMALLSQUAREFACTORY_H
#define OPENGLTUT_SMALLSQUAREFACTORY_H

#include "SquareFactory.h"

namespace square {
    class SmallSquareFactory : public SquareFactory {
    public:
        Square create() override;
    };
}



#endif //OPENGLTUT_SMALLSQUAREFACTORY_H
