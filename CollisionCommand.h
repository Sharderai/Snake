#ifndef COLLISIONCOMMAND_H
#define COLLISIONCOMMAND_H

#include "ICommand.h"
#include "player.h"
#include "points.h"
#include "field.h"


class CollisionCommand : public ICommand
{
	Character& character;
	ActivePoint& activePoint;
	GameField& gameField;

	public:
	CollisionCommand(Character& c, ActivePoint& p, GameField& gf);
    void execute() override;
};

#endif


