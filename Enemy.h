#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Texture texture;

public:
    sf::Sprite sprite;
    
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};