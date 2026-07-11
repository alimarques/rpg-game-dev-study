#include <iostream>
#include "Enemy.h"

void Enemy::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    
    size = sf::Vector2i(64, 64);
}

void Enemy::Load()
{
    if(texture.loadFromFile("Assets/Enemy/Textures/spritesheet.png"))
    {
        std::cout << "Enemy carregado com sucesso" << std::endl;
        sprite.setTexture(texture);

        int xIndex = 0;
        int yIndex = 0;

        // Pegar um pedaço do spritesheet
        // (xIndex, yIndex, largura, altura)
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(400, 200));

        sprite.scale(sf::Vector2f(2, 2));
        
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Erro ao carregar Enemy" << std::endl;
    }
}

void Enemy::Update()
{
    boundingRectangle.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}