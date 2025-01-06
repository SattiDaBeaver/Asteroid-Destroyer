#include "projectile.hpp"

#define PROJ_VEL 700
#define CONVERT 0.01745
#define R 75.f
#define DISP 15
#define ANGLE_SHIFT -13

Projectile::Projectile(float x_, float y_, float angle_) {
    angle = angle_ - 90;
    sinA = std::sinf((angle + ANGLE_SHIFT) * CONVERT);
    cosA = std::cosf((angle + ANGLE_SHIFT) * CONVERT);

    x = x_ + (R + DISP) * SCALE_X * cosA;
    y = y_ + (R + DISP) * SCALE_Y * sinA;
}

Projectile::~Projectile() {}

void Projectile::draw(sf::RenderWindow &window){
    sf::Font font("inter.ttf");
    sf::Text text(font);

    text.setString("bruh");
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setPosition({x, y});
    text.setRotation(sf::degrees(angle));

    window.draw(text);
}

void Projectile::update(float time){
    x += PROJ_VEL * cosA * time;
    y += PROJ_VEL * sinA * time;
}