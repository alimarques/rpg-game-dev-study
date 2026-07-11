#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"

int main()
{
    // Configs
    unsigned int xSize = 1920;
    unsigned int ySize = 1080;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({xSize, ySize}), "RPG Game", sf::Style::Default, settings);

    Player player;
    Enemy enemy;

    player.Initialize();
    enemy.Initialize();

    player.Load();
    enemy.Load();
    
    // Main Loop
    while (window.isOpen())
    {
        // Event loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        enemy.Update();
        player.Update(enemy);
        
        // Draw
        window.clear(sf::Color::Black);

        player.Draw(window);
        enemy.Draw(window);
        
        window.display();
    }

    return 0;
}