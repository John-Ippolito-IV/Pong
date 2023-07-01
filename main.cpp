#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include "SFML/Graphics.hpp"

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 1);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }

        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
        }

        if (ball.getPosition().top > windowHeight)
        {
            ball.hitBottom();
            
        }

        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
        {
            ball.reboundSides();
        }

        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
        }

        ball.update();
        bat.update();

        window.clear(Color(0, 0, 0));
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
}