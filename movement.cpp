#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    unsigned int xSize = 800;
    unsigned int ySize = 600;

    // Configuracoes
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({xSize, ySize}), "RPG Game", sf::Style::Default, settings);

    // Carregar os arquivos
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player carregado com sucesso" << std::endl;
        playerSprite.setTexture(playerTexture);

        int pxUnit = 96;
        int xIndex = 0;
        int yIndex = 0;

        // Pegar um pedaço do spritesheet
        // (xIndex, yIndex, largura, altura)
        playerSprite.setTextureRect(sf::IntRect(pxUnit * xIndex, pxUnit * yIndex, pxUnit, pxUnit));
        playerSprite.scale(sf::Vector2f(2, 2));
    }
    else
    {
        std::cout << "Erro ao carregar o player" << std::endl;
    }

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimento
        sf::Vector2f position = playerSprite.getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        
        // Draw
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        
        window.display();
    }

    return 0;
}