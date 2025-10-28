#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerI.h"
#include "ObjectI.h"
#include "object.h"
#include "GameStateI.h"
#include "ActiveState.h"

class player : public PlayerI {
    public:
        player();
        player(int, int);
        ~player();

        void changeDirection(WPARAM);
        char getDirection();

        ObjectI* getPosition() const;

        object* getTail();
        bool firstPoint();
        void collect(object*);

        void lose();
        bool checkPlayState();

    private:
        ObjectI* position;
        ObjectI* tail = nullptr;
        char direction = '>';
        GameStateI* gameState;
};

player::player() {
    //ObjectI* default will use object
    position = new object();
    position->setX(0);
    position->setY(0);
    position->setColor(RGB(200, 130, 20));
    ID = 1; //legacy code 1 = player

    gameState = new ActiveState();
}


player::player(int x, int y) {
    //ObjectI* default will use object
    position = new object();
    position->setX(x);
    position->setY(y);
    position->setColor(RGB(200, 130, 20));
    ID = 1; //legacy code 1 = player

    gameState = new ActiveState();
}

//added to destroy the ObjectI object set as a field
player::~player() {
    delete position;
    delete gameState;
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
    gameState->lose(this);
}


bool player::checkPlayState() {
    return gameState->getPlayState();
}


void player::setGameState(GameStateI* newGameState){
    delete gameState;
    gameState = newGameState;
}

#endif