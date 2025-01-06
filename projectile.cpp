#include "projectile.hpp"

#define PROJ_VEL 700
#define CONVERT 0.01745
#define R 75.f
#define DISP 15
#define ANGLE_SHIFT -8

#define FONT_SIZE 16
#define FONT_ADJUST 2

Projectile::Projectile(float x_, float y_, float angle_) {
    angle = angle_ - 90;
    sinA = std::sinf((angle) * CONVERT);
    cosA = std::cosf((angle) * CONVERT);

    x = x_ + (R + DISP) * SCALE_X * cosA;
    y = y_ + (R + DISP) * SCALE_Y * sinA;
}

Projectile::~Projectile() {}

void Projectile::draw(sf::RenderWindow &window){
    sf::Font font("inter.ttf");
    sf::Text text(font);

    text.setString("bruh");
    text.setCharacterSize(FONT_SIZE);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOrigin({0, FONT_SIZE / 2 + FONT_ADJUST});
    text.setPosition({x, y});
    text.setRotation(sf::degrees(angle));

    window.draw(text);
}

void Projectile::update(float time){
    x += PROJ_VEL * cosA * time;
    y += PROJ_VEL * sinA * time;
}