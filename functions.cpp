#include <iostream>

// Foward declaration
void PrintHealth();
void CalculateHealthAfterDamage(int damage);
float PercentualHealth();
bool IsMore18OrMoreAge(int age);

// Variaveis globais
int health = 100;

int main()
{
    PrintHealth();
    CalculateHealthAfterDamage(20);
    CalculateHealthAfterDamage(4);
    CalculateHealthAfterDamage(10);
    
    std::cout << "Percentual de vida: " << PercentualHealth() << std::endl;

    std::cout << "Maior de idade: " << IsMore18OrMoreAge(19) << std::endl;
    std::cout << "Maior de idade: " << IsMore18OrMoreAge(17) << std::endl;

    return 0;
}

// Funções
void CalculateHealthAfterDamage(int damage = 10)
{
    health -= damage;
    PrintHealth();
}

void PrintHealth()
{
    std::cout << "Health: " << health << std::endl;
}

float PercentualHealth()
{
    return health/100.0f;
}

bool IsMore18OrMoreAge(int age)
{
    return age >= 18;
}
