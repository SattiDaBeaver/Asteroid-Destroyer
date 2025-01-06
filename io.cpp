#include "io.hpp"

#define OUTPUT_SIZE 24
#define TEXT_X 5
#define TEXT_Y 5

void IO::set_fps(sf::RenderWindow &window, int argc, char* argv[]){
    if (argc == 2){
        int fps = std::stoi(argv[1], 0, 10);
        std::cout << "FPS: " << fps << std::endl;
        window.setFramerateLimit(fps);
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
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
        player.make_projectile();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
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

    }     
}

void IO::display_score(int score, sf::RenderWindow &window){
    sf::Font font("inter.ttf");
    sf::Text text(font);
    text.setCharacterSize(OUTPUT_SIZE);
    text.setStyle(sf::Text::Bold);

    std::string s = "Score: " + std::to_string(score);

    text.setString(s);
    text.setPosition({WIDTH / 2.f - 40, TEXT_Y});
    window.draw(text);
}

void IO::display_fps(int fps, sf::RenderWindow &window){
    sf::Font font("inter.ttf");
    sf::Text text(font);
    text.setCharacterSize(OUTPUT_SIZE);
    text.setStyle(sf::Text::Bold);

    std::string s = "FPS: " + std::to_string(fps);

    text.setString(s);
    text.setPosition({TEXT_X, TEXT_Y});
    window.draw(text);
}

float IO::delta_time(sf::Clock &clock){
    return clock.restart().asMicroseconds();
}
