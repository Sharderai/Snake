#ifndef MOVE_ACTION_I_
#define MOVE_ACTION_I_

#include "ObjectI.h"

class MoveActionI {
    public:
        /*
        * Methods to move an object in a give direction
        */
        virtual void moveLeft(ObjectI*) = 0;
        virtual void moveRight(ObjectI*) = 0;
        virtual void moveUp(ObjectI*) = 0;
        virtual void moveDown(ObjectI*) = 0;

        virtual ~MoveActionI() {}
};

#endif