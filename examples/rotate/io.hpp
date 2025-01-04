#ifndef IO_HPP
#define IO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

class IO{
    public:
        static void set_fps(sf::RenderWindow &window, int argc, char* argv[]);
};


#endif