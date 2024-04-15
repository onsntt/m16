#include <iostream>

enum class Skills {drink, smoke, speak};

void printSkill(Skills skill)
// переменная skill принадлежит классу Skills
{
    if (skill == Skills::drink) std::cout << "Drink skill\n";
    else if (skill == Skills::smoke) std::cout << "Smoke skill\n";
    else if (skill == Skills::speak) std::cout << "Speak skill\n";
    else std::cout << "There is no skill\n";
}

Skills setNext(Skills actual)
{
    if (actual == Skills::drink) return Skills::smoke;
    else if (actual == Skills::smoke) return Skills::speak;
    else if (actual == Skills::speak) return Skills::drink;
     

}
int main()
{
    Skills actualMode = Skills::drink;
    //еще одна переменная класса Skills
    
    for (int i = 0; i < 9; i++)
    {
        printSkill(actualMode);
        actualMode = setNext(actualMode);
        
    }
}