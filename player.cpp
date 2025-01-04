#include "player.hpp"
#include "game.hpp"

Player::Player(float x_, float y_, float angle_){
    shape = sf::CircleShape(R, 3);
    x = x_;
    y = y_;
    angle = angle_;

    shape.setOrigin({R, R});

    shape.setRotation(sf::degrees(angle_));

    shape.setPosition({x_, y_});

    //shape.setFillColor(sf::Color(255,100,100,255));
}

void Player::draw(sf::RenderWindow &window){
    window.draw(shape);
}

void Player::texture(sf::Texture &texture){
    shape.setTexture(&texture);
}

void Player::update(){
    shape.setRotation(sf::degrees(90));
}