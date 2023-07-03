#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Ball
{
public:
	Ball(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();

	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void hitBottom();
	void clear();
	void update();
private:
	Vector2f position;
	RectangleShape ballShape;

	float xVelocity = 0.25f;
	float yVelocity = 0.25f;
};