#ifndef I_MOVEMENT_TYPE_H
#define I_MOVEMENT_TYPE_H

#include "ObjectI.h"

class I_MovementType {
    public:
        virtual void move(ObjectI* self, ObjectI* target) = 0;
};

#endif