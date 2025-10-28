#ifndef ACTIVE_STATE_
#define ACTIVE_STATE_

#include "GameStateI.h"

class ActiveState : public GameStateI {
    public:
        ActiveState() : gameState(true){}
        ~ActiveState(){}

        void lose(PlayerI* player);
        bool getPlayState(){return gameState;}
    private:
        bool gameState; 
};

void ActiveState::lose(PlayerI* player){
    gameState = false;
    player->getPosition()->setColor(RGB(150,50,10));
    player->setGameState(new InactiveState());
}

#endif