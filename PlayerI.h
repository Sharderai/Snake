#ifndef PLAYER_I_
#define PLAYER_I_

class PlayerI {
    public:
        /*
        * Method to change the direction a player is moving
        * @param WPARAM is a key entered by a user
        */
        virtual void changeDirection(WPARAM) = 0;

        
        //Method to return the current direction a player is going
        virtual char getDirection() = 0;

        //Method to get the last objection following a player
        virtual Object* getTail() = 0;

        //Method to determine if any objects are already following the player
        virtual bool firstPoint() = 0;

        //Method to add an object to those trailing the player
        virtual void collect(object*) = 0;

        //Method that updates the game state to lose
        virtual void lose() = 0;

        // Method that confirms if the player can move based on rules for the current play state.
        virtual bool canMove() = 0;

        virtual ~PlayerI(){};
}