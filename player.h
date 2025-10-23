#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerI.h"
#include "ObjectI.h"
#include "object.h"

class player : public PlayerI {
    public:
        player();
        player(int, int);
        ~player();

        //TODO: seperate areas of concern
        void changeDirection(WPARAM);
        char getDirection();
        ObjectI* getPosition() const;

        object* getTail();
        bool firstPoint();
        void collect(object*);

        void lose();
        bool checkPlayState();
    private:
        COLORREF playerColor = RGB(200, 130, 20);
        ObjectI* tail = nullptr;
        char direction = '>';
        bool playState = true;

        /*
        * Refactored: Updating to composit design pattern by setting ObjectI* as a field
        * Using this to set/get x and y coordinates, rather than inheriting functionality from object class
        */
        ObjectI* position;
};

player::player() {
    //ObjectI* default will use object
    position = new object();
    position->setX(0);
    position->setY(0);
    setColor(playerColor);
    ID = 1;
}


player::player(int x, int y) {
    //ObjectI* default will use object
    position = new object();
    position->setX(x);
    position->setY(y);
    setColor(playerColor);
    ID = 1;
}

player::~player() {
    delete position;
}

void player::changeDirection(WPARAM wParam) {
    if (wParam == VK_LEFT && direction != '>') {
        direction = '<';
    }
    else if (wParam == VK_RIGHT && direction != '<') {
        direction = '>';
    }
    else if (wParam == VK_UP && direction != 'v') {
        direction = '^';
    }
    else if (wParam == VK_DOWN && direction != '^') {
        direction = 'v';
    }
}

char player::getDirection() { 
    return direction; 
}

ObjectI* player::getPosition() const {
    return position;
}


object* player::getTail() {
    return tail;
}


bool player::firstPoint() {
    return tail == nullptr;
}


void player::collect(object* collected) {
    tail = collected;
}


void player::lose() {
    playState = false;
    setColor(RGB(150,50,10));
}


bool player::checkPlayState() {
    return playState;
}

#endif