#include <SFML/Graphics.hpp>

int main()
{
    // ----------------- INITIALIZE SECTION ------------------------
    // Configuracoes
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "RPG Game", sf::Style::Default, settings);

    // Circulo
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color(210, 140, 190));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(350, 250));

    // Retangulo
    sf:: RectangleShape reactangle(sf::Vector2f(100,50));
    reactangle.setFillColor(sf::Color(56, 18, 200));
    reactangle.setOutlineThickness(5);
    reactangle.setOutlineColor(sf::Color::Black);
    reactangle.setPosition(sf::Vector2f(350, 250));
    reactangle.setOrigin(reactangle.getSize() / 2.f);
    reactangle.setRotation(45);

    // Triangulo
    sf::CircleShape triangle(50.0f, 3);
    triangle.setFillColor(sf::Color::Yellow);
    triangle.setPosition(sf::Vector2f(40, 210));

    // Heptagono
    sf::CircleShape hept(50.0f, 7);
    hept.setFillColor(sf::Color::Red);
    hept.setPosition(sf::Vector2f(400, 100));

    // Linhas
    sf::RectangleShape line(sf::Vector2f(300, 2));
    line.setPosition(sf::Vector2f(400, 500));
    // ----------------- ENDOF INITIALIZE SECTION ------------------
    
    while (window.isOpen())
    {
        // ----------------- UPDATE SECTION ------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        // ----------------- ENDOF UPDATE SECTION ------------------

        // ----------------- DRAW SECTION --------------------------
        window.clear(sf::Color::Black);

        window.draw(shape);
        window.draw(reactangle);
        window.draw(triangle);
        window.draw(hept);
        window.draw(line);
        
        window.display();
        // ----------------- ENDOF DRAW SECTION --------------------
    }

    return 0;
}