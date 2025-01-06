#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <optional>
#include <math.h>
#include <memory>
#include <vector>

#include "game.hpp"
#include "projectile.hpp"

#define R 75.f

class Player{
    public:
        sf::CircleShape shape;
        float x, y;
        float vel_x, vel_y;
        float angle;
        float ang_vel;
        std::vector<std::unique_ptr<Projectile>> projectiles;
        float projectile_time;

        Player(float x_, float y_, float angle_);
        ~Player();
        void texture(sf::Texture &texture);
        void draw(sf::RenderWindow &window);
        void scale(sf::Vector2f vec);
        void update(float time);

        void wrap(sf::RenderWindow &window);
        void update_velocity(float x_, float y_, float time);
        void update_ang_velocity(float target_angle, float time);
        void make_projectile();
        void update_projectile_time(float delta_time);
};

#endif