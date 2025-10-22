#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class player : public object {
    public:
        player();
        player(int, int);

        void move(int, int) override;
        void changeDirection(WPARAM);

        object* getTail();
        bool firstPoint();
        void collect(object*);
        void lose();
        bool checkPlayState();
    private:
        COLORREF playerColor = RGB(200, 130, 20);
        object* tail = nullptr;
        char direction = '>';
        bool playState = true;
        int score = 0;
};

player::player() {
    setColor(playerColor);
    ID = 1;
}


player::player(int x, int y) : object(x, y) {
    setColor(playerColor);
    ID = 1;
}


void player::move(int limitX, int limitY) {
    if ((locX == 0 && direction == '<') || (locX == (limitX - 1) && direction == '>') || (locY == 0 && direction == '^') || (locY == (limitY - 1) && direction == 'v')) {
        lose();
    }

    if (direction == '<' && locX > 0) {
        locX--;
    }
    else if (direction == '>' && locX < (limitX - 1)) {
        locX++;
    }
    else if (direction == '^' && locY > 0) {
        locY--;
    }
    else if (direction == 'v' && locY < (limitY - 1)) {
        locY++;
    }
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