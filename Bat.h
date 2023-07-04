#pragma once
#include "SFML/Graphics.hpp"


using namespace sf;


class Bat
{
public:
	Bat();
	Bat(float startX, float startY);
	void setPosition(Vector2f pos);
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void update();

private:
	Vector2f position;
	RectangleShape batShape;

	float batSpeed = 1.0f;
};