#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <vector>
#include <memory>
#include <random>

#define WIDTH 1600
#define HEIGHT 900

class Game{
    public:
        static void game_loop(int argc, char* argv[]);
};

#endif