#ifndef PLAYER_MOVER
#define PLAYER_MOVER

#include "PlayerI.h"
#include "ObjectI.h"
#include "MoveActionI.h"

class PlayerMover : public MoveActionI {
    public:
        PlayerMover();
        ~PlayerMover();

        void moveLeft(PlayerI*) override;
        void moveRight(PlayerI*) override;
        void moveUp(PlayerI*) override;
        void moveDown(PlayerI*) override;
};

PlayerMover::PlayerMover() {}
PlayerMover::~PlayerMover() {}

void PlayerMover::moveLeft(PlayerI* player) {
    ObjectI* position = player->getPosition();
    position->setX(position->getX() - 1);
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