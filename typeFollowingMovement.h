#ifndef TYPE_FOLLOWING_MOVEMENT_H
#define TYPE_FOLLOWING_MOVEMENT_H

#include "objectMovementTypeI.h"

class typeFollowingMovement : public objectMovementTypeI {
    public:
        typeFollowingMovement();
        void move(object* self, object* target) override;
        ~typeFollowingMovement();
};

typeFollowingMovement::typeFollowingMovement() {

}

void typeFollowingMovement::move(object* self, object* target) {
    self->setX(target->setX());
    self->setY(target->setY());
}

typeFollowingMovement::~typeFollowingMovement() {
    
}

#endif