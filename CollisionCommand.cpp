#include "CollisionCommand.h"

void CollisionCommand::execute()
{
    if (character.getX() == activePoint.getX() &&
        character.getY() == activePoint.getY() &&
        !activePoint.checkFollowing())
    {
        points* tailSeg = new points(activePoint.getX(), activePoint.getY());
        object* head = &character;
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
        createPoint(activePoint, gameField.getX(), gameField.getY());
    }
}

