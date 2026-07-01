#include <iostream>

int main()
{
    float health = 100;
    float damage = 15;
    int result = health/damage;
    float resultFloat = health/damage;

    std::cout << "Resultado final inteiro: " << result << std::endl;
    std::cout << "Resultado final com float: " << resultFloat << std::endl;

    // Pra atualizar a propria variavel
    health -= damage;

    std::cout << "Health: " << health << std::endl;

    return 0;
}