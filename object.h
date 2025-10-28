#ifndef OBJECT_H
#define OBJECT_H

#include <windows.h>
#include "ObjectI.h"

class object : public ObjectI {
    public:
        object();
        object(int, int);

        int getX() override;
        int getY() override;
        void setX(int) override;
        void setY(int) override;

        void setColor(COLORREF) override;
        COLORREF getColor() override;
        
        void setID(int ID)
        int getID() override;

        object* following = nullptr;
    protected:
        int locX;
        int locY;
        int ID;
    private:
        COLORREF color;
};

object::object() {
    locX, locY = 0;
    color = RGB(120,120,120);
}


object::object(int x,int y) {
    locX = x;
    locY = y;
    color = RGB(120,120,120);
}


int object::getX() {
    return locX;
}


int object::getY() {
    return locY;
}


void object::setX(int x) {
    locX = x;
}


void object::setY(int y) {
    locY = y;
}


void object::setColor(COLORREF newColor) {
    color = newColor;
}


COLORREF object::getColor() {
    return color;
}

void object::setID(int ID) {
    this.ID = id;
}


int object::getID() {
    return ID;
}

#endif