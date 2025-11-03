#ifndef MOVE_ACTION_I_
#define MOVE_ACTION_I_

#include "PlayerI.h"

class MoveActionI {
    public:
        /*
        * Methods to move a player in a give direction
        */
        virtual void moveLeft(PlayerI*) = 0;
        virtual void moveRight(PlayerI*) = 0;
        virtual void moveUp(PlayerI*) = 0;
        virtual void moveDown(PlayerI*) = 0;

        virtual ~MoveActionI() {}
};

#endif