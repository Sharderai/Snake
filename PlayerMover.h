#ifndef PLAYER_MOVER
#define PLAYER_MOVER

#include "PlayerI.h"
#include "ObjectI.h"

//Handles movement action as called by the PlayerMoveCommand class
class PlayerMover : public MoveActionI {
    public:
        PlayerMover();
        ~PlayerMover();

        void moveLeft(PlayerI*);
        void moveRight(PlayerI*);
        void moveUp(PlayerI*);
        void moveDown(PlayerI*);
};

PlayerMover::PlayerMover() {}
PlayerMover::~PlayerMover() {}

//Method split into different directions and updated to use pointers now that it's a separate class
void PlayerMover::moveLeft(PlayerI* player) {
    ObjectI* position = player->getPosition();
    position->setX(position()->getX() - 1);
}

void PlayerMover::moveRight(PlayerI* player) {
    ObjectI* position = player->getPosition();
    position->setX(position->getX() + 1);
}

void PlayerMover::moveUp(PlayerI* player) {
    ObjectI* position = player->getPosition();
    position->setY(position->getY() - 1);
}

void PlayerMover::moveDown(PlayerI* player) {
    ObjectI* position = player->getPosition();
    position->setY(position->getY() + 1);
}

#endif