#ifndef TYPE_NO_MOVEMENT_H
#define TYPE_NO_MOVEMENT_H

#include "I_MovementType.h"

class typeNoMovement : public I_MovementType {
    public:
        typeNoMovement();
        void move(object* self, object* target) override;
        ~typeNoMovement();
};

typeNoMovement::typeNoMovement() {

}

void typeNoMovement::move(object* self, object* target) {
    return;
}

typeNoMovement::~typeNoMovement() {
    
}

#endif