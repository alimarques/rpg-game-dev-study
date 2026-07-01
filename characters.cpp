#include <iostream>

class Enemy
{
private:
    int health = 0;
    int damage = 0;
    std::string name = "";

public:
    std::string getName()
    {
        return this->name;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    int getHealth()
    {
        return this->health;
    }

    void setHealth(int health)
    {
        this->health = health;
    }

    int getDamage()
    {
        return this->damage;
    }

    void setDamage(int damage)
    {
        this->damage = damage;
    }

    void Kill()
    {
        std::cout << "Kill the enemy" << std::endl;
    }

    void Heal()
    {
        health += 15;
        std::cout << "" << name << " new health: " << health << std::endl;
    }

    void Walk()
    {
        std::cout << "Walk any direction" << std::endl;
    }
};

int main()
{
    Enemy enemy;
    enemy.setHealth(100);
    enemy.setDamage(20);
    enemy.setName("Skeleton");

    Enemy boss;
    boss.setHealth(500);
    boss.setDamage(100);
    boss.setName("Kalendria");

    enemy.Heal();

    boss.Heal();


    return 0;
}