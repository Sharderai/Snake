#ifndef POINTS_H
#define POINTS_H

#include <memory>

#include "object.h"
#include "I_MovementType.h"
#include "typeFollowingMovement.h"

class points : public object {
    public:
        points(int, int, std::shared_ptr<I_MovementType>, object*);
        points& operator=(const points&);
        void move(int, int) override;
        void collect(object*);
        bool checkFollowing();
        void resetIdentity();
        ~points();
    private:
        COLORREF color = RGB(200, 180, 20);
        std::shared_ptr<I_MovementType> movement;
        bool isFollowing = false;
};

points::points(int x, int y, std::shared_ptr<I_MovementType> startingMovement, object* initialTarget) : object(x, y) {
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


void points::move(int limitX, int limitY) {
    movement->move(this, following);

    //checks for keeping points in bounds while moving
    //TODO: make limits global so that these can be checked only when actually relevant
    if (locX < 0) {
        locX = 0;
    }
    else if (locX >= limitX) {
        locX = limitX - 1;
    }

    if (locY < 0) {
        locY = 0;
    }
    else if (locY >= limitY) {
        locY = limitY-1;
    }
}


void points::collect(object* pointAhead) {
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