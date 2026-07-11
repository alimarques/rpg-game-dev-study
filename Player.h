#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
    sf::Texture texture;

    float bulletSpeed = 0.8f;
    
public:
    sf::Sprite sprite;
    std::vector<sf::RectangleShape> bullets;

public:
    void Initialize();
    void Load();
    void Update(Enemy& enemy);
    void Draw(sf::RenderWindow& window);
};