#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#define R 75.f
#define WIDTH 800
#define HEIGHT 600

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
}