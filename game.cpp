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
    player.scale({0.4, 0.5});

    long i = 0;

    sf::Clock clock;

    window.setKeyRepeatEnabled(true);

    while (window.isOpen()){
        // Process all Tasks since the last frame
        float time = IO::delta_time(clock);

        IO::key_pressed(player, window, time);
        player.update(time);

        player.wrap(window);

        // Clear window
        window.clear(sf::Color(50, 50, 50, 255));

        // Do drawing stuff
        window.draw(player.shape);

        // Draw the Current Frame
        window.display();
    }
    return;
}