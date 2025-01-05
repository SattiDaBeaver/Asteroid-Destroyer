#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <string>

class Projectile {
    public:
        float x, y;
        float sinA, cosA;
        float angle;

        Projectile(float x_, float y_, float angle_);
        ~Projectile();
        void draw(sf::RenderWindow &window);
};

#endif