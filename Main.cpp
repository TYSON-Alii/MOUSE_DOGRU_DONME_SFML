#include <iostream>

#include <cmath>

#include <SFML/Graphics.hpp>

#define PI 3.14

float mouse_x;

float mouse_y;

float konum_x;

float konum_y;

int uzunluk;

float yon;

int main()

{

    sf::RenderWindow window(sf::VideoMode(500,500), "SFML works!");

    sf::RectangleShape cubuk(sf::Vector2f(4 ,1));

    cubuk.setPosition(250 ,250);

    cubuk.setFillColor(sf::Color(155 , 70, 30));

    cubuk.setScale(1 ,1);

    while (window.isOpen())

    {

        sf::Event event;

        while (window.pollEvent(event))

        {

            if (event.type == sf::Event::Closed)

                window.close();

        }

        mouse_x = sf::Mouse::getPosition(window).x;

        mouse_y = sf::Mouse::getPosition(window).y;

        konum_x = cubuk.getPosition().x;

        konum_y = cubuk.getPosition().y;

        uzunluk = sqrt((mouse_x - konum_x) * (mouse_x - konum_x) + (mouse_y - konum_y) * (mouse_y - konum_y));

        yon = atan2((mouse_x - konum_x),(mouse_y - konum_y))*180/PI;

        cubuk.setScale(1 ,uzunluk);

        cubuk.setRotation(-yon);

        window.clear();

        window.draw(cubuk);

        window.display();

    }

    return 0;

}

