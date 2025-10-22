#ifndef POINTS_H
#define POINTS_H

#include "object.h"

class points : public object {
    public:
        points();
        points(int, int);
        points& operator=(const points&);
        void move(int, int) override;
        void collect(object*);
        bool checkFollowing();
        void resetIdentity();
    private:
        COLORREF color = RGB(200, 180, 20);
        bool isFollowing = false;
};

points::points() {
    setColor(color);
    ID = 3;
}


points::points(int x, int y) : object(x, y) {
    setColor(color);
    ID = 3;
}


points& points::operator=(const points& other) {
    locX = other.locX;
    locY = other.locY;
    isFollowing = false;
    return *this;
}


void points::move(int limitX, int limitY) {
    if (isFollowing) {
        locX = following->getX();
        locY = following->getY();
    }
}


void points::collect(object* pointAhead) {
    isFollowing = true;
    following = pointAhead;
    ID = 2;
}


bool points::checkFollowing() {
    return isFollowing;
}


void points::resetIdentity() {
    ID = 3;
}

#endif