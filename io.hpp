#ifndef IO_HPP
#define IO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#include "player.hpp"

class IO{
    public:
        static void set_fps(sf::RenderWindow &window, int argc, char* argv[]);
        static void key_pressed(Player &player, sf::RenderWindow &window, float time);
        static void display_score(int score, sf::RenderWindow &window);
        static void display_fps(int fps, sf::RenderWindow &window);

        static float delta_time(sf::Clock &clock);
};


#endif