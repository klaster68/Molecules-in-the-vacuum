#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//class Moleculs


//functions
void timer()
{
    sf::Clock clock;
    float time = 0;
    while (time < 1)
    {
        time = clock.getElapsedTime().asMilliseconds();
    }
}


//block main-----------------------------------------------------------------
int main()
{

    //random a number----------------------------------------------------------
    //sf::Window getWinSize;

    //shape. window and color---------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(10.f);
    


    shape.setFillColor(sf::Color::Green);

    //set random position
    sf::Vector2u getSizeWin = window.getSize();
    srand(time(0));

    int R = shape.getRadius();
    int randomPositionX[5];
    int randomPositionY[5];
    for (size_t i = 0; i < 5; i++)
    {
        randomPositionX[i] = rand() % getSizeWin.x - R;
        randomPositionY[i] = rand() % getSizeWin.y - R;
    }
    //shape.setPosition(randomPositionX, randomPositionY);

    int angle[5];
    for (size_t i = 0; i < 5; i++)
    {
        angle[i] = (rand() % 360) * 3.14 / 180;
    }

    float Vx[5];
    float Vy[5];
    for (size_t i = 0; i < 5; i++)
    {
        Vx[i] = sin(angle[i]);
        Vy[i] = cos(angle[i]);
    }
    
    //the massive of shape
    const int length = 5;
    sf::CircleShape moleculs[length];
    for (int i = 0; i < length; i++)
    {
        moleculs[i].setRadius(20);
        moleculs[i].setPosition(randomPositionX[i], randomPositionY[i]);
        moleculs[i].setFillColor(sf::Color::Cyan);
    }

    //cout << x << "  " << y << "   " << angle << endl;

    //main loop------------------------------------------------------------------
    while (window.isOpen())
    {
        //the loop for moleculs
        for (size_t i = 0; i < length; i++) {
            timer();
            moleculs[i].move(Vx[i], Vy[i]);

            //Проверяем положение молекулы
            if (moleculs[i].getPosition().x > getSizeWin.x - (2 * R))
            {
                Vx[i] = -Vx[i];
            }
            if (moleculs[i].getPosition().x < (R / 2))
            {
                Vx[i] = -Vx[i];
            }
            if (moleculs[i].getPosition().y > getSizeWin.y - (2 * R))
            {
                Vy[i] = -Vy[i];
            }
            if (moleculs[i].getPosition().y < (R / 2))
            {
                Vy[i] = -Vy[i];
            }
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (size_t i = 0; i < length; i++)
        {
            window.draw(moleculs[i]);
        }
        window.display();
    }

    return 0;
}