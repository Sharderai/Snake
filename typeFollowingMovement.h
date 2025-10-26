#ifndef TYPE_FOLLOWING_MOVEMENT_H
#define TYPE_FOLLOWING_MOVEMENT_H

#include "I_MovementType.h"

class typeFollowingMovement : public I_MovementType {
    public:
        typeFollowingMovement();
        void move(ObjectI* self, ObjectI* target) override;
        ~typeFollowingMovement();
};

typeFollowingMovement::typeFollowingMovement() {

}

void typeFollowingMovement::move(ObjectI* self, ObjectI* target) {
    self->setX(target->getX());
    self->setY(target->getY());
}

typeFollowingMovement::~typeFollowingMovement() {
    
}

#endif