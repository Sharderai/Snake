#ifndef I_MOVEMENT_TYPE_H
#define I_MOVEMENT_TYPE_H

#include "object.h"

class I_MovementType {
    public:
        virtual void move(object* self, object* target) = 0;
};

#endif