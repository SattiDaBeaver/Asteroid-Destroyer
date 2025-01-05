#include "io.hpp"

void IO::set_fps(sf::RenderWindow &window, int argc, char* argv[]){
    if (argc == 2){
        int fps = std::stoi(argv[1], 0, 10);
        std::cout << "FPS: " << fps << std::endl;
        window.setFramerateLimit(60);
    }
    else {
        std::cout << "VSync Enabled" << std::endl;
        window.setVerticalSyncEnabled(true);
    }
}

void IO::key_pressed(Player &player, sf::RenderWindow &window){
    while (const std::optional event = window.pollEvent()){
        if (event->is<sf::Event::Closed>()){
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
            switch (keyPressed->scancode){
                case (sf::Keyboard::Scancode::Escape):
                    window.close();
                    break;

                case (sf::Keyboard::Scancode::W):
                    std::cout << "W is Pressed" << std::endl;
                    break;

                case (sf::Keyboard::Scancode::A):
                    std::cout << "A is Pressed" << std::endl;
                    break;

                case (sf::Keyboard::Scancode::S):
                    std::cout << "S is Pressed" << std::endl;
                    break;

                case (sf::Keyboard::Scancode::D):
                    std::cout << "D is Pressed" << std::endl;
                    break;

                case (sf::Keyboard::Scancode::Space):
                    std::cout << "Space is Pressed" << std::endl;
                    break;
                    
                default: std::cout << "A key is Pressed" << std::endl;
            }
        }
    }
}

float IO::delta_time(sf::Clock &clock){
    return clock.restart().asMilliseconds();
}
