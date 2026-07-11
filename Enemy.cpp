#include <iostream>
#include "Enemy.h"

void Enemy::Initialize()
{
    
}

void Enemy::Load()
{
    if(texture.loadFromFile("Assets/Enemy/Textures/spritesheet.png"))
    {
        std::cout << "Enemy carregado com sucesso" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(400, 200));

        int pxUnit = 64;
        int xIndex = 0;
        int yIndex = 0;
        sf::Vector2f scale = sf::Vector2f(2, 2);

        // Pegar um pedaço do spritesheet
        // (xIndex, yIndex, largura, altura)
        sprite.setTextureRect(sf::IntRect(pxUnit * xIndex, pxUnit * yIndex, pxUnit, pxUnit));
        sprite.scale(scale);
    }
    else
    {
        std::cout << "Erro ao carregar Enemy" << std::endl;
    }
}

void Enemy::Update()
{
    
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}