#include "Math.h"
#include <math.h>

/**
 * @brief Normaliza um vetor
 * 
 * @param vector Vetor a ser normalizado
 * * @return sf::Vector2f Vetor normalizado
 */
sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    
    sf::Vector2f normalizedVector = sf::Vector2f(vector.x / m, vector.y / m);

    return normalizedVector;
}

bool Math::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if(rect1.intersects(rect2))
        return true;
    return false;
}