#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <string>

#include "player.hpp"

#define RAD_1 100
#define RAD_2 30

class Obstacle{
    public:
        sf::CircleShape shape;
        int type;
        float x, y;
        float vel_x, vel_y;

        Obstacle(int type_, float x_, float y_, float vel_x_, float vel_y_, sf::Texture &texture_satti1, sf::Texture &texture_satti2);
        bool collision(Player &player);
        void update(float time);
};

#endif