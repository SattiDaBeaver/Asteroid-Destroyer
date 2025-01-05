#include "projectile.hpp"

#define PROJ_VEL 500
#define CONVERT 0.01745
#define R 75.f

Projectile::Projectile(float x_, float y_, float angle_) {
    sinA = std::sinf(angle * CONVERT);
    cosA = std::cosf(angle * CONVERT);

    x = x_ + R * cosA;
    y = y_ + R * sinA;

    angle = angle_;
}

Projectile::~Projectile() {}

void Projectile::draw(sf::RenderWindow &window){
    sf::Font font("inter.ttf");
    sf::Text text(font);

    text.setString("bruh");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setPosition({x, y});
    text.setRotation(sf::degrees(angle));

    window.draw(text);
}