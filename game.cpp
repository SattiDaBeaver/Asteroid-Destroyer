#include "game.hpp"

void Game::game_loop(){
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Damn Bruh!");

    window.setFramerateLimit(60);
    //IO::set_fps(window, argc, argv);

    sf::CircleShape shape(R, 3);
    //shape.setFillColor(sf::Color(255,100,100,255));
    shape.setOrigin({R, R});
    shape.setPosition({WIDTH/2, HEIGHT/2});

    sf::Texture texture("bhaiya.png");

    shape.setTexture(&texture);
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

        // Clear window
        window.clear(sf::Color(50, 50, 50, 255));

        // Do drawing stuff
        window.draw(shape);

        // Draw the Current Frame
        window.display();
    }
    return;
}