#ifndef PLAYER_MOVE_COMMAND_
#define PLAYER_MOVE_COMMAND_

#include "MoveCommandI.h"
#include "PlayerI.h"
#include "MoveActionI.h"

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

bool PlayerMoveCommand::canMove(int x, int y, char direction) {
    return player->checkPlayState()
        || ((x > 0) && (direction == '<'))
        || ((x < xLimit -1) && (direction == '>')) //TODO: set up global xLimit & yLimit
        || ((y > 0) && (direction == '^'))
        || ((y < yLimit -1) && (direction == 'v'));
}

void PlayerMoveCommand::move() {
    int x = player->getPosition()->getX();
    int y = player->getPosition()->getY();
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
