#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

/**
 * @brief Carrega o spritesheet de um personagem e configura o seu sprite inicial.
 * * Esta função localiza o arquivo de textura baseado no nome do personagem,
 * extrai o frame correto usando os índices informados e aplica a escala desejada.
 * * @param texture Referência para a textura onde a imagem será carregada na memória.
 * @param path Nome da pasta do personagem dentro do diretório Assets (ex: "Player", "Enemy").
 * @param pxUnit Tamanho em pixels de cada quadrado/grid do spritesheet (ex: 64, 96).
 * @param xIndex Coluna do frame desejado no spritesheet (começando em 0).
 * @param yIndex Linha do frame desejado no spritesheet (começando em 0).
 * @param scale Vetor contendo o fator de escala de redimensionamento (Padrão: 2x2).
 * * @return sf::Sprite O objeto sprite configurado e pronto para ser desenhado na tela.
 */
sf::Sprite LoadCharacter(sf::Texture& texture, std::string path, int pxUnit, int xIndex, int yIndex, sf::Vector2f scale = sf::Vector2f(2, 2))
{
    sf::Sprite sprite;

    if(texture.loadFromFile("Assets/" + path + "/Textures/spritesheet.png"))
    {
        std::cout << path + " carregado com sucesso" << std::endl;
        std::cout << "Assets/" + path + "/Textures/spritesheet.png" << std::endl;
        sprite.setTexture(texture);

        // Pegar um pedaço do spritesheet
        // (xIndex, yIndex, largura, altura)
        sprite.setTextureRect(sf::IntRect(pxUnit * xIndex, pxUnit * yIndex, pxUnit, pxUnit));
        sprite.scale(scale);
    }
    else
    {
        std::cout << "Erro ao carregar " + path << std::endl;
    }

    return sprite;
}

/**
 * @brief Normaliza um vetor
 * 
 * @param vector Vetor a ser normalizado
 * * @return sf::Vector2f Vetor normalizado
 */
sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    
    sf::Vector2f normalizedVector = sf::Vector2f(vector.x / m, vector.y / m);

    return normalizedVector;
}

int main()
{
    // Configs
    unsigned int xSize = 1920;
    unsigned int ySize = 1080;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({xSize, ySize}), "RPG Game", sf::Style::Default, settings);

    // Player
    sf::Texture playerTexture;
    sf::Sprite playerSprite = LoadCharacter(playerTexture, "Player", 96, 0, 0);
    playerSprite.setPosition(sf::Vector2f(1400, 800));

    // Enemy
    sf::Texture enemyTexture;
    sf::Sprite enemySprite = LoadCharacter(enemyTexture, "Enemy", 64, 0, 0);
    enemySprite.setPosition(sf::Vector2f(400, 200));

    // Bullets
    float bulletSpeed = 0.5f;
    sf::Vector2f bulletSize(sf::Vector2f(10, 5));
    std::vector<sf::RectangleShape> bullets;
    
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

        // Player movement
        sf::Vector2f position = playerSprite.getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        
        
        // Move bullets
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(bulletSize));

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizeVector(bulletDirection);
            sf::Vector2f bulletPosition = bullets[i].getPosition();
            bullets[i].setPosition(bulletPosition + bulletDirection * bulletSpeed);
        }
        
        // Draw
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(enemySprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        
        window.display();
    }

    return 0;
}