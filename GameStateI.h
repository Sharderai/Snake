#ifndef GAME_STATE_
#define GAME_STATE_

class GameStateI {
    public:
        // Method to let player know if state is an active type (true) or inactive type (false)
        virtual bool getPlayState() = 0;

        // Returns movement rule associated with the current state
        virtual bool canMove() = 0;

        //returns object color associated with the current state
        virtual COLORREF getColor() = 0;
};

#endif