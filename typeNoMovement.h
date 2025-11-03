#ifndef TYPE_NO_MOVEMENT_H
#define TYPE_NO_MOVEMENT_H

#include "I_MovementType.h"

class typeNoMovement : public I_MovementType {
    public:
        typeNoMovement();
        void move(ObjectI* self, ObjectI* target) override;
        ~typeNoMovement();
};

typeNoMovement::typeNoMovement() {

}

void typeNoMovement::move(ObjectI* self, ObjectI* target) {
    return;
}

typeNoMovement::~typeNoMovement() {
    
}

#endif