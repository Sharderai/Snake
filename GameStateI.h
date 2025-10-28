#ifndef GAME_STATE_
#define GAME_STATE_

class GameState {
    /*
    * Method to update the play state if the player loses. 
    * Player color will be updated and play state will changed be false.
    */
    virtual void lose(PlayerI*) = 0;
    //returns the game state: true if active, false if otherwise
    virtual bool getPlayState() = 0;
    virtual ~GameState(){}
}