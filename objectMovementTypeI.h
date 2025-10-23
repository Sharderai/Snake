#ifndef OBJECT_MOVEMENT_TYPE_I_H
#define OBJECT_MOVEMENT_TYPE_I_H

class objectMovementTypeI {
    public:
        virtual void move(object* self, object* target) = 0;
};

#endif