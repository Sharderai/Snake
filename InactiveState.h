#ifndef INACTIVE_STATE_
#define INACTIVE_STATE_

#include "GameStateI.h"

class InactiveState : public GameStateI {
    public:
        InactiveState() : color(RGB(150,50,10)){}
        ~InactiveState(){}

        bool getPlayState(){return false;}
        bool canMove(){return false;}
        COLORREF getColor(){return color;}
    private:
        COLORREF color; 
};

#endif