#include "game.hpp"
#include "io.hpp"
#include "player.hpp"

void Game::game_loop(){
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Damn Bruh!");

    window.setFramerateLimit(60);
    //IO::set_fps(window, argc, argv);

    Player player(WIDTH/2, HEIGHT/2, 90);

    sf::Texture texture_player("bhaiya_flipped.png", false, sf::IntRect({0, 0}, {150, 150}));

    player.texture(texture_player);

    long i = 0;

    sf::Clock clock;

    while (window.isOpen()){
        // Process all Tasks since the last frame
        IO::key_pressed(player, window);

        player.shape.rotate(sf::degrees(1.f));

        std::cout << IO::delta_time(clock) << std::endl;

        // Clear window
        window.clear(sf::Color(50, 50, 50, 255));

        // Do drawing stuff
        window.draw(player.shape);

        // Draw the Current Frame
        window.display();
    }
    return;
}