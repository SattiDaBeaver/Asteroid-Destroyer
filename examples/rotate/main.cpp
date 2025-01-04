#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#include "io.hpp"
#include "game.hpp"

int main(int argc, char* argv[]){
    Game::game_loop();

    return 0;
}