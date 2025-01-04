#include "player.hpp"

Player::Player(float x_, float y_, float angle_){
    shape = sf::CircleShape(R, 3);
    x = x_;
    y = y_;
    angle = angle_;
}

void Player::draw(sf::RenderWindow &window){
    window.draw(shape);
}

void Player::update(){
    
}