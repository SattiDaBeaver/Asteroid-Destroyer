#include "game.hpp"
#include "io.hpp"
#include "player.hpp"
#include "projectile.hpp"
#include "obstacle.hpp"

#define NEW_OBS_TIME 2000
#define MARGIN 50
#define MAX_VEL_OBS 100
#define MAX_OBSTACLES 10

//void update_obstacles(std::vector<std::unique_ptr<Obstacle>> &obstacles, float time, Player player);

void Game::game_loop(int argc, char* argv[]){
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "SATTI DESTROYER!!!");

    sf::Clock game_clock;

    Player player(WIDTH/2, HEIGHT/2, 90);

    std::vector<std::unique_ptr<Obstacle>> obstacles;
    float obstacle_time = 0;

    // Random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std:: uniform_int_distribution dis_t(1, 2);
    std:: uniform_int_distribution dis_x(MARGIN, WIDTH - MARGIN);
    std:: uniform_int_distribution dis_y(MARGIN, HEIGHT- MARGIN);
    std:: uniform_int_distribution dis_v(-MAX_VEL_OBS, MAX_VEL_OBS);

    int score = 0;
    int count = 0;
    float fps = 0;

    //window.setFramerateLimit(240);
    //window.setVerticalSyncEnabled(true);
    IO::set_fps(window, argc, argv);

    sf::Texture texture_player("bhaiya_flipped.png", false, sf::IntRect({0, 0}, {150, 150}));
    sf::Texture texture_satti1("Satti1.png");
    sf::Texture texture_satti2("Satti2.png");

    texture_player.setSmooth(true);
    texture_satti1.setSmooth(true);
    texture_satti2.setSmooth(true);

    player.texture(texture_player);
    player.scale({SCALE_X, SCALE_Y});

    window.setKeyRepeatEnabled(false);

    // TEST
    obstacles.push_back(std::make_unique<Obstacle>(1, 200, 200, 50, 20, texture_satti1, texture_satti2));
    obstacles.push_back(std::make_unique<Obstacle>(2, 700, 200, -50, 20, texture_satti1, texture_satti2));
    // ~TEST

    while (window.isOpen()){
        // Process all Tasks since the last frame
        float time = IO::delta_time(game_clock) / 1000;

        player.update_projectile_time(time);

        // Get Key Presses
        IO::key_pressed(player, window, time);

        // Update Player
        player.update(time);
        player.wrap(window);

        // Update Obstacles
        
        for (int i = 0; i < obstacles.size(); i++){
            obstacles[i]->update(time);
            float x = obstacles[i]->x;
            float y = obstacles[i]->y;

            if (x > window.getSize().x){
            obstacles[i]->x = 0;
            obstacles[i]->shape.setPosition({x, y});
            }
            else if (x < 0){
                obstacles[i]->x = window.getSize().x;
                obstacles[i]->shape.setPosition({x, y});
            }

            if (y > window.getSize().y){
                obstacles[i]->y = 0;
                obstacles[i]->shape.setPosition({x, y});
            }
            else if (y < 0){
                obstacles[i]->y = window.getSize().y;
                obstacles[i]->shape.setPosition({x, y});
    }
            else if (obstacles[i]->collision(player)){
                score++;
                if (obstacles[i]->type == 1){
                    float vel_x = obstacles[i]->vel_x;
                    float vel_y = obstacles[i]->vel_y;
                    obstacles.erase(obstacles.begin() + i);

                    obstacles.push_back(std::make_unique<Obstacle>(2, x + vel_y, y + vel_x, vel_y, vel_x, texture_satti1, texture_satti2));
                    obstacles.push_back(std::make_unique<Obstacle>(2, x - vel_y, y - vel_x, -vel_y, -vel_x, texture_satti1, texture_satti2));
                }
                else{
                    obstacles.erase(obstacles.begin() + i);
                }
            }
        }

        //update_obstacles(obstacles, time, player);

        // New Obstacles
        obstacle_time += time;
        if (obstacle_time > NEW_OBS_TIME){
            obstacle_time = 0;
            if (obstacles.size() < MAX_OBSTACLES){
                int t = dis_t(gen);
                float rx = dis_x(gen);
                float ry = dis_y(gen);
                float vx = dis_v(gen);
                float vy = dis_v(gen);
                obstacles.push_back(std::make_unique<Obstacle>(t, rx, ry, vx, vy, texture_satti1, texture_satti2));
            }
        }

        // Clear window
        window.clear(sf::Color(50, 50, 50, 255));

        // Do drawing stuff  
        for (int i = 0; i < obstacles.size(); i++){
            window.draw(obstacles[i]->shape);
        }

        player.draw(window);

        IO::display_score(score, window);

        if (count > 10){
            count = 0;
            fps = 1000.f / time;
        }
        else{
            count++;
        }
        IO::display_fps(fps, window);

        // Draw the Current Frame
        window.display();

        // Debug
        //std::cout << obstacles.size() << std::endl;
    }
    return;
}

// void update_obstacles(std::vector<std::unique_ptr<Obstacle>> &obstacles, float time, Player player){
//     for (int i = 0; i < obstacles.size(); i++){
//         obstacles[i]->update(time);
//         float x = obstacles[i]->x;
//         float y = obstacles[i]->y;

//         if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT){
//             obstacles.erase(obstacles.begin() + i);
//         }

//         else if (obstacles[i]->collision(player)){
//             if (obstacles[i]->type == 1){
//                 float vel_x = obstacles[i]->vel_x;
//                 float vel_y = obstacles[i]->vel_y;
//                 obstacles.erase(obstacles.begin() + i);

//                 obstacles.push_back(std::make_unique<Obstacle>(2, x + vel_x, y + vel_y, vel_x, vel_y));
//                 obstacles.push_back(std::make_unique<Obstacle>(2, x - vel_x, y - vel_y, -vel_x, -vel_y));
//             }
//             else{
//                 obstacles.erase(obstacles.begin() + i);
//             }
//         }
//     }
// }