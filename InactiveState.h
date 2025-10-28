#ifndef INACTIVE_STATE_
#define INACTIVE_STATE_

#include "GameStateI.h"

class InactiveState : public GameStateI {
    public:
        InactiveState() : gameState(false){}
        ~InactiveState(){}

        void lose(PlayerI* player){}
        bool getPlayState(){return gameState;}
    private:
        bool gameState; 
};

#endif