#include <SFML/Graphics.hpp>
#include "Bat.h"

Bat::Bat()
{
    float width = 100;
    batShape.setSize(Vector2f(width, 10));
}

Bat::Bat(float startX, float startY)
{

    position.x = startX;
    position.y = startY;
    batShape.setSize(sf::Vector2f(100, 10));
    batShape.setPosition(position);

}

FloatRect Bat::getPosition()
{
    return batShape.getGlobalBounds();
}
void Bat::setPosition(Vector2f pos)
{
    position = pos;
}

RectangleShape Bat::getShape()
{
    return batShape;
}

void Bat::moveLeft()
{
    if (position.x > 0)
    {
        position.x -= batSpeed;
    }
}

void Bat::moveRight()
{
    if (position.x < 924)
    {
        position.x += batSpeed;
    }
}

void Bat::update()
{
    batShape.setPosition(position);
}