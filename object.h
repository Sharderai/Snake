#ifndef OBJECT_H
#define OBJECT_H

#include <windows.h>

class object {
    public:
        object();
        object(int, int);

        virtual void move(int, int)=0;

        int getX();
        int getY();
        void setX(int);
        void setY(int);

        void setColor(COLORREF);
        COLORREF getColor();
        int getID();

        object* following = nullptr;
    protected:
        int locX;
        int locY;
        int ID;
    private:
        COLORREF color = RGB(120,120,120);
};

object::object() {
    locX, locY = 0;
}


object::object(int x,int y) {
    locX = x;
    locY = y;
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


int object::getID() {
    return ID;
}

#endif