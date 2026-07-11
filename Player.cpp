#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Initialize()
{
    
}

void Player::Load()
{
    if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player carregado com sucesso" << std::endl;
        sprite.setTexture(texture);

        int pxUnit = 96;
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
        std::cout << "Erro ao carregar Player" << std::endl;
    }
}

void Player::Update(Enemy& enemy)
{
    sf::Vector2f position = sprite.getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1));

        
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        sf::Vector2f bulletPosition = bullets[i].getPosition();
        bullets[i].setPosition(bulletPosition + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}