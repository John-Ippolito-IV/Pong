#include "ComOpp.h"

ComOpp::ComOpp(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	possesssedBat.setPosition(position);
};

void ComOpp::setTargetX(float tx)
{
	targetX = tx;
}
void ComOpp::moveTowardsTarget()
{
	if (targetX > position.x)
	{
		possesssedBat.moveRight();
		position.x += 3.0f;
	}
	if (targetX < position.x)
	{
		possesssedBat.moveLeft();
		position.x -= 3.0f;
	}
}
RectangleShape ComOpp::getShape()
{
	return possesssedBat.getShape();
}
FloatRect ComOpp::getBounds()
{
	return possesssedBat.getPosition();
}
void ComOpp::update()
{
	moveTowardsTarget();
	possesssedBat.update();
}