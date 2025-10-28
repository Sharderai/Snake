#ifndef ACTIVE_STATE_
#define ACTIVE_STATE_

#include "GameStateI.h"

class ActiveState : public GameStateI {
    public:
        ActiveState() : color(RGB(200, 130, 20)){}
        ~ActiveState(){}

        bool getPlayState(){return true;}
        bool canMove(){return true;}
        COLORREF getColor(){return color;}

    private:
        COLORREF color; 
};

#endif