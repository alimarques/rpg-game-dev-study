#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);
    
    size = sf::Vector2i(96, 96);    
}

void Player::Load()
{
    if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player carregado com sucesso" << std::endl;
        sprite.setTexture(texture);

        int xIndex = 0;
        int yIndex = 0;

        // Pegar um pedaço do spritesheet
        // (xIndex, yIndex, largura, altura)
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(0, 0));

        sprite.scale(sf::Vector2f(2, 2));
        
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
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
    {
        sprite.setPosition(position + sf::Vector2f(1, 0));
        boundingRectangle.setPosition(position + sf::Vector2f(1, 0));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.setPosition(position + sf::Vector2f(-1, 0));
        boundingRectangle.setPosition(position + sf::Vector2f(-1, 0));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.setPosition(position + sf::Vector2f(0, -1));
        boundingRectangle.setPosition(position + sf::Vector2f(0, -1));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.setPosition(position + sf::Vector2f(0, 1));
        boundingRectangle.setPosition(position + sf::Vector2f(0, 1));
    }

        
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

    boundingRectangle.setPosition(sprite.getPosition());

    if(Math::CheckRectCollision(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds()))
    {
        std::cout << "Colisao do player com inimigo" << std::endl;
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}