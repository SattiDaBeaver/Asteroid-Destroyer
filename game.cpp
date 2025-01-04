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

    while (window.isOpen()){
        // Process all Tasks since the last frame
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }

        player.shape.rotate(sf::degrees(1.f));

        // Clear window
        window.clear(sf::Color(50, 50, 50, 255));

        // Do drawing stuff
        window.draw(player.shape);

        // Draw the Current Frame
        window.display();
    }
    return;
}