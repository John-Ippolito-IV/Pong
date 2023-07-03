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


    enum GameState
    {
        Playing,
        Dead
    };

    GameState currentSate = Playing;

    int ballDropped = 0;

    Font Font;
    Font.loadFromFile("fonts/CaviarDreams.ttf");
    Text deadText("Restart the app to try again", Font, 32);
    deadText.setFillColor(sf::Color::White);
    deadText.setPosition(250, windowHeight / 2);

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 1);

    while (window.isOpen())
    {
        window.clear(Color(0, 0, 0));
        Event event;
        switch (currentSate)
        {
        case GameState::Playing:
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                bat.moveLeft();
            }
            else if (Keyboard::isKeyPressed(Keyboard::D))
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
                ballDropped++;
            }

            if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
            {
                ball.reboundSides();
            }

            if (ball.getPosition().intersects(bat.getPosition()))
            {
                ball.reboundBatOrTop();
            }
            if (ballDropped == 3) {
                ball.clear();
                ballDropped == 0;
                currentSate = Dead;
            }
            break;

        case GameState::Dead:
            window.draw(deadText);

            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            break;
        }

        ball.update();
        bat.update();

        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
}