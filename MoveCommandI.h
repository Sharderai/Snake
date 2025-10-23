// Command Interface that manages move functionality

#ifndef MOVE_COMMAND_I_
#define MOVE_COMMAND_I_

class MoveCommandI {
    public:
        //method to control where pieces move in the field
        virtual void move() = 0;

        /*
        * method to determine if a move is legal
        * int is x coordinate of piece
        * int is y coordinate of piece
        * char is direction of movement
        */
        virtual bool canMove(int, int, char) = 0;

        virtual ~MoveCommandI() {}
};

#endif