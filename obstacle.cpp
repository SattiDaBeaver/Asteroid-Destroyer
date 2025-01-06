#include "obstacle.hpp"

#define RAD_1 100
#define RAD_2 30

#define TOLERANCE 5

Obstacle::Obstacle(int type_, float x_, float y_, float vel_x_, float vel_y_){
    type = type_;
    x = x_; y = y_;
    vel_x = vel_x_; vel_y= vel_y_;

    switch (type){
        case 1: 
            shape = sf::CircleShape(RAD_1);
            shape.setOrigin({RAD_1, RAD_1});
            shape.setPosition({x, y});
            shape.setFillColor(sf::Color(50, 50, 50, 255));
            shape.setOutlineThickness(4);
            //sf::Texture texture("Satti1.png");
            //shape.setTexture(&texture);
            break;
        case 2:
            shape = sf::CircleShape(RAD_2);
            shape.setOrigin({RAD_2, RAD_2});
            shape.setPosition({x, y});
            shape.setFillColor(sf::Color(50, 50, 50, 255));
            shape.setOutlineThickness(4);
            //sf::Texture texture("Satti1.png");
            //shape.setTexture(&texture);
            break;
        default: break;
    }
}

bool Obstacle::collision(Player &player){
    float r;
    switch (type){
        case 1: 
            r = RAD_1;
            break;
        case 2:
            r = RAD_2;
            break;
        default: break;
    }

    for (int i = 0; i < player.projectiles.size(); i++){
        float dx = player.projectiles[i]->x - x;
        float dy = player.projectiles[i]->y - y;
        if (std::sqrt(dx*dx + dy*dy) < r + TOLERANCE){
            return true;
        }
    }

    return false;
}

void Obstacle::update(float time){
    time /= 1000;
    x += vel_x * time;
    y += vel_y * time;
    shape.setPosition({x, y});
}