#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerI.h"
#include "ObjectI.h"
#include "object.h"
#include "GameStateI.h"
#include "ActiveState.h"
#include "InactiveState.h"

class player : public PlayerI {
    public:
        player();
        player(int, int);
        ~player();

        void changeDirection(WPARAM) override;
        char getDirection() override;

        ObjectI* getPosition() const;

        ObjectI* getTail() override;
        bool firstPoint() override;
        void collect(object*) override;

        void lose() override;
        void setGameState(GameStateI*);
        bool canMove() override;

    private:
        ObjectI* position;
        ObjectI* tail = nullptr;
        char direction = '>';
        GameStateI* gameState;
};

player::player() {
    gameState = new ActiveState();

    //ObjectI* default will use object
    position = new object();
    position->setX(0);
    position->setY(0);
    position->setID(1); //legacy code 1 = player
    position->setColor(gameState->getColor());

    
}


player::player(int x, int y) {
    gameState = new ActiveState();

    //ObjectI* default will use object
    position = new object();
    position->setX(x);
    position->setY(y);
    position->setID(1); //legacy code 1 = player
    position->setColor(gameState->getColor());
}

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


ObjectI* player::getTail() {
    return tail;
}


bool player::firstPoint() {
    return tail == nullptr;
}


void player::collect(object* collected) {
    tail = collected;
}

bool player::canMove() {
    return gameState->canMove();
}

void player::lose() {
    setGameState(new InactiveState());
    position->setColor(gameState->getColor());
}

void player::setGameState(GameStateI* newGameState){
    delete gameState;
    gameState = newGameState;
    position->setColor(gameState->getColor());
}

#endif