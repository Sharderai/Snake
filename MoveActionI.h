#ifndef MOVE_ACTION_I_
#define MOVE_ACTION_I_

class MoveActionI {
    public:
        /*
        * Methods to move an object in a give direction
        */
        virtual void moveLeft(Object*) = 0;
        virtual void moveRight(Object*) = 0;
        virtual void moveUp(Object*) = 0;
        virtual void moveDown(Object*) = 0;

        virtual ~MoveActionI() {}
};

#endif