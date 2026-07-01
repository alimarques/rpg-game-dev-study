#include <iostream>

int main()
{
    // Comentários simples
    std::cout << "Hello C++!" << std::endl;
    std::cout << "Start programing in this language" << std::endl;
    std::cout << "Encadeando múltiplas strings. " << "Seems fine :)" << std::endl;

    /*
        Comentários
        em múltiplas linhas

    */
    std::cout << "Print com números: " << 20 << std::endl;

    // Variaveis
    int saude = 100;
    float damage = 5.4;
    std::string nome = "Ali";
    bool isDead = false;
    float velocidade = 10.5f;
    char primeiraLetra = 'A';

    std::cout << "Dano: " << damage << std::endl;
    std::cout << "Velocidade: " << velocidade << std::endl;

    return 0;
}