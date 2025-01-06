#include "player.hpp"

#define ACCEL 500 // pixels per sec^2
#define ANG_ACCEL 180 // degrees per sec^2

#define MAX_VEL 120
#define MIN_VEL 20

#define MAX_ANG_VEL 200
#define MIN_ANG_VEL 30

#define MIN_PROJ_TIME 300


// Player Functions

Player::Player(float x_, float y_, float angle_){
    shape = sf::CircleShape(R, 3);
    x = x_; y = y_;
    angle = angle_;
    vel_x = 0;
    vel_y = 0;
    ang_vel = 0;
    projectile_time = 0;

    shape.setOrigin({R, R});

    shape.setRotation(sf::degrees(angle_));

    shape.setPosition({x_, y_});

    //shape.setFillColor(sf::Color(255,100,100,255));
}

Player::~Player(){
    projectiles.clear();
}

void Player::draw(sf::RenderWindow &window){
    window.draw(shape);
    for (int i = 0; i < projectiles.size(); i++){
        projectiles[i]->draw(window);
    }
}

void Player::texture(sf::Texture &texture){
    shape.setTexture(&texture);
}

void Player::scale(sf::Vector2f vec){
    shape.scale(vec);
}

void Player::update(float time){
    time /= 1000;

    x += vel_x * time;
    y += vel_y * time;
    //angle += ang_vel * time;

    if (angle >= 360){
        angle -= 360;
    }
    else if (angle < 0){
        angle += 360;
    }

    shape.setRotation(sf::degrees(angle));
    shape.setPosition({x, y});

    for (int i = 0; i < projectiles.size(); i++){
        projectiles[i]->update(time);
    }

    //std::cout << angle << std::endl; // REMOVE
}

void Player::wrap(sf::RenderWindow &window){
    if (x > window.getSize().x){
            x = 0;
            shape.setPosition({x, y});
    }
    else if (x < 0){
        x = window.getSize().x;
        shape.setPosition({x, y});
    }

    if (y > window.getSize().y){
        y = 0;
        shape.setPosition({x, y});
    }
    else if (y < 0){
        y = window.getSize().y;
        shape.setPosition({x, y});
    }
}

void Player::update_velocity(float x_, float y_, float time){
    time /= 1000;

    vel_x += ACCEL * time * x_ ;
    vel_y += ACCEL * time * y_;

    if (vel_x > MAX_VEL){
        vel_x = MAX_VEL;
    }
    else if (vel_x < -MAX_VEL){
        vel_x = -MAX_VEL;
    }
    if (vel_y > MAX_VEL){
        vel_y = MAX_VEL;
    }
    else if (vel_y < -MAX_VEL){
        vel_y = -MAX_VEL;
    }

    if (std::abs(vel_x) < MIN_VEL){
        vel_x = MIN_VEL * x_;
    }
    if (std::abs(vel_y) < MIN_VEL){
        vel_y = MIN_VEL * y_;
    }

}

void Player::update_ang_velocity(float target_angle, float time){
    time /= 1000;

    if (angle != target_angle){
        float diff = target_angle - angle;
        if (diff > 180){
            diff -= 360;
        }
        else if (diff < -180){
            diff += 360;
        }

        float dir = diff / std::abs(diff);

        angle += ANG_ACCEL * time * diff / 180 + MIN_ANG_VEL * dir * time;
        if (std::abs(diff) < ANG_ACCEL * time){
            angle = target_angle;
            //ang_vel = 0;
        }
        //std::cout << target_angle << std::endl;
        // if (ang_vel > MAX_ANG_VEL){
        //     ang_vel = MAX_ANG_VEL;
        // }
        // else if (ang_vel < -MAX_ANG_VEL){
        //     ang_vel = -MAX_ANG_VEL;
        // }

        // if (std::abs(ang_vel) < MIN_ANG_VEL){
        //     ang_vel = MIN_ANG_VEL * dir;
        // }
    }
}

void Player::make_projectile(){
    if (projectile_time > MIN_PROJ_TIME){
        projectiles.push_back(std::make_unique<Projectile>(x, y, angle));
        projectile_time = 0;
    }
}

void Player::update_projectile_time(float delta_time){
    projectile_time += delta_time;
}









