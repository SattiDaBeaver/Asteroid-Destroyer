#include "game.hpp"
#include "io.hpp"
#include "player.hpp"
#include "projectile.hpp"


void Game::game_loop(){
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Damn Bruh!");

    sf::Keyboard::Scancode key;
    bool released = true;

    sf::Clock clock;

    Player player(WIDTH/2, HEIGHT/2, 90);

    window.setFramerateLimit(60);
    //IO::set_fps(window, argc, argv);

    sf::Texture texture_player("bhaiya_flipped.png", false, sf::IntRect({0, 0}, {150, 150}));

    player.texture(texture_player);
    player.scale({0.4, 0.5});

    window.setKeyRepeatEnabled(false);

    // TEST
    Projectile p(100, 100, 50);

    // ~TEST

    while (window.isOpen()){
        // Process all Tasks since the last frame
        float time = IO::delta_time(clock);

        // Get Key Presses
        IO::key_pressed(player, window, time);

        // Update Player
        player.update(time);
        player.wrap(window);

        // Clear window
        window.clear(sf::Color(50, 50, 50, 255));

        // Do drawing stuff
        window.draw(player.shape);
        p.draw(window);
        // for (int i = 0; i < player.num; i++){
        //     if (player.projectiles[i] != nullptr){
        //         window.draw(player.projectiles[i]->text);
        //     }
        // }

        // Draw the Current Frame
        window.display();
    }
    return;
}