#ifndef COLLISIONCOMMAND_H
#define COLLISIONCOMMAND_H

#include "ICommand.h"
#include "player.h"
#include "points.h"
#include "field.h"

//part of temporary cpp redefinition error fix
#include "typeNoMovement.h"


class CollisionCommand : public ICommand
{
	private:
		player& character;
		points& activePoint;
		field& gameField;

	public:
		CollisionCommand(player& c, points& p, field& gf);
    	void execute() override;
};

//copied below methods from cpp file temporarily until all files are refactored into
//separate h and cpp files, as it caused a redefinition error with both formats used

CollisionCommand::CollisionCommand(player& c, points& p, field& gf) : character(c), activePoint(p), gameField(gf) {
}

void CollisionCommand::execute()
{
    if (character.getPosition()->getX() == activePoint.getX() &&
        character.getPosition()->getY() == activePoint.getY() &&
        !activePoint.checkFollowing())
    {
        points* tailSeg = new points(activePoint.getX(), activePoint.getY(), std::make_shared<typeNoMovement>(typeNoMovement()), nullptr);
        ObjectI* head = character.getPosition();
        activePoint.collect(nullptr);

        if (!character.firstPoint()) 
        {
            tailSeg->collect(character.getTail());
            gameField.updateTile(
                tailSeg->getX(), tailSeg->getY(), 
                tailSeg->getColor(), gameField.getID()
            );
        } 
        else 
        {
            tailSeg->collect(head);
        }

        character.collect(tailSeg);
    }
}

#endif


