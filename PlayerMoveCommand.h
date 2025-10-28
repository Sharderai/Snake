#ifndef PLAYER_MOVE_COMMAND_
#define PLAYER_MOVE_COMMAND_

#include "MoveCommandI.h"
#include "PlayerI.h"
#include "MoveActionI.h"

//New class manages movement decision logic following command design pattern
class PlayerMoveCommand : public MoveCommandI {
    public:
        PlayerMoveCommand(PlayerI*);
        ~PlayerMoveCommand();
        void move() override;
        bool canMove(int, int, char) override;

    private:
        PlayerI* player;
        MoveActionI* mover;
};

PlayerMoveCommand::PlayerMoveCommand(PlayerI* player)
    : player(player), mover(new MoveAction()) {}

PlayerMoveCommand::~PlayerMoveCommand() {
    delete mover;
}

//Separated from legacy move method. Added logic to stop movement if the player has lost.
bool PlayerMoveCommand::canMove(int x, int y, char direction) {
    return player->canMove() && 
        (
        ((x > 0) && (direction == '<'))
        || ((x < xLimit -1) && (direction == '>'))
        || ((y > 0) && (direction == '^'))
        || ((y < yLimit -1) && (direction == 'v'))
        );
}

//Method decides if/where the player should move
//TODO: eventually should refactor to eliminate hard coded directional values, possibly using enum class
void PlayerMoveCommand::move() {
    int x = player->getPosition()->getX(); //player gets its object which gets its x data
    int y = player->getPosition()->getY(); //player gets its object which gets its y data
    char direction = player->getDirection();

    if(!canMove(x, y, direction)){
        player->lose();
        return;
    }

    if(direction == '<') mover->moveLeft(player);
    if(direction == '>') mover->moveRight(player);
    if(direction == '^') mover->moveUp(player);
    if(direction == 'v') mover->moveDown(player);
}

#endif
