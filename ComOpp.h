#pragma once
#include "Bat.h"


class ComOpp
{
public:
	ComOpp(float startX, float startY);
	FloatRect getBounds();
	RectangleShape getShape();

	void setTargetX(float tX);
	void moveTowardsTarget();
	void update();

	
private:
	Bat possesssedBat;
	Vector2f position;

	float targetX;
};