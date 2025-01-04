#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#define R 80.f

class Player{
    public:
        sf::CircleShape shape;
        float x, y;
        float angle;

        Player(float x_, float y_, float angle_);
        void draw(sf::RenderWindow &window);
        void update();

};

#endif