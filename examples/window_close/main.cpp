#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#define R 150.f
#define WIDTH 640
#define HEIGHT 480

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Damn Bruh!");

    if (argc == 2){
        int fps = std::stoi(argv[1], 0, 10);
        std::cout << "FPS: " << fps << std::endl;
        window.setFramerateLimit(60);
    }
    else {
        std::cout << "VSync Enabled" << std::endl;
        window.setVerticalSyncEnabled(true);
    }

    sf::CircleShape shape(R);
    shape.setFillColor(sf::Color(255,100,100,255));
    shape.setOrigin({R, R});
    shape.setPosition({WIDTH/2, HEIGHT/2});
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is <sf::Event::Closed> ()){
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}