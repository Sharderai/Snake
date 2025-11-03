/* TODO: uncomment this file after refactoring other files to use split h and cpp files format.
#include "CollisionCommand.h"
#include "typeNoMovement.h"

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
*/
