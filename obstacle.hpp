#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <string>

#include "player.hpp"

class Obstacle{
    public:
        sf::CircleShape shape;
        int type;
        float x, y;
        float vel_x, vel_y;

        Obstacle(int type_, float x_, float y_, float vel_x_, float vel_y_);
        bool collision(Player &player);
        void update(float time);
};

#endif