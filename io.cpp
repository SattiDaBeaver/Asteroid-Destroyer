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

void IO::key_pressed(Player &player, sf::RenderWindow &window, float time){
    while (const std::optional event = window.pollEvent()){
        if (event->is<sf::Event::Closed>()){
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                player.update_velocity(-0.7071, -0.7071, time);
                player.update_ang_velocity(315, time);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                player.update_velocity(-0.7071, 0.7071, time);
                player.update_ang_velocity(225, time);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                player.update_velocity(0.7071, 0.7071, time);
                player.update_ang_velocity(135, time);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                player.update_velocity(0.7071, -0.7071, time);
                player.update_ang_velocity(45, time);
            }
            else{   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                    player.update_velocity(0, -1, time);
                    player.update_ang_velocity(360, time);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                    player.update_velocity(-1, 0, time);
                    player.update_ang_velocity(270, time);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
                    player.update_velocity(0, 1, time);
                    player.update_ang_velocity(180, time);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                    player.update_velocity(1, 0, time);
                    player.update_ang_velocity(90, time);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
                    std::cout << "Space is Pressed" << std::endl;
                }
            }     
        }
    }
}

float IO::delta_time(sf::Clock &clock){
    return clock.restart().asMilliseconds();
}
