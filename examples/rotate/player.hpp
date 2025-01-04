#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <optional>

#define R 75.f

class Player{
    public:
        sf::CircleShape shape;
        float x, y;
        float angle;

        Player(float x_, float y_, float angle_);
        void texture(sf::Texture &texture);
        void draw(sf::RenderWindow &window);
        void update();

};

#endif