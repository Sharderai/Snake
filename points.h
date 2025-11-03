#ifndef POINTS_H
#define POINTS_H

#include <memory>

#include "object.h"
#include "I_MovementType.h"
#include "typeFollowingMovement.h"

class points : public object {
    public:
        points(int, int, std::shared_ptr<I_MovementType>, ObjectI*);
        points& operator=(const points&);
        void move();
        void collect(ObjectI*);
        bool checkFollowing();
        void resetIdentity();
        ~points();
    private:
        COLORREF color = RGB(200, 180, 20);
        std::shared_ptr<I_MovementType> movement;
        bool isFollowing = false;
};

points::points(int x, int y, std::shared_ptr<I_MovementType> startingMovement, ObjectI* initialTarget) : object(x, y) {
    setColor(color);
    following = initialTarget;
    movement = startingMovement;
    ID = 3; //legacy code, ID for uncollected points
}


points& points::operator=(const points& other) {
    locX = other.locX;
    locY = other.locY;
    isFollowing = other.isFollowing;
    following = other.following;
    movement = other.movement;
    return *this;
}


void points::move() {
    movement->move(this, following);
}


void points::collect(ObjectI* pointAhead) {
    isFollowing = true;
    following = pointAhead;
    movement = std::make_shared<typeFollowingMovement>(typeFollowingMovement());
    ID = 2; //legacy code, ID for collected points
}


bool points::checkFollowing() {
    return isFollowing;
}


void points::resetIdentity() {
    ID = 3; //legacy code, ID for uncollected points
}


points::~points() {
}

#endif