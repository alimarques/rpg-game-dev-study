#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
    sf::Texture texture;

    float bulletSpeed = 0.8f;
    std::vector<sf::RectangleShape> bullets;
    
public:
    sf::Sprite sprite;

    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    void Initialize();
    void Load();
    void Update(Enemy& enemy);
    void Draw(sf::RenderWindow& window);
};