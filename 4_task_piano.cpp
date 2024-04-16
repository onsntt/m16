#include <iostream>
#include <cmath>
enum class note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main()
{
    std::string notes;
    std::cout << "Enter notes: ";
    std::cin >> notes;
    int accord = 0;
    for (int i = 0; i < notes.length(); i++)
    {
        int power = (notes[i] - '0') -1;
         accord += pow(2,power);
        
    }
    std::cout << accord << "\n";
    if (accord & static_cast<int>(note::DO))
    {

        std::cout << "DO ";
    }
    if (accord & static_cast<int>(note::RE))
    {
        std::cout << "RE ";
    }
    if (accord & static_cast<int>(note::MI))
    {
        std::cout << "MI ";
    }
    if (accord & static_cast<int>(note::FA))
    {
        std::cout << "FA ";
    }
    if (accord & static_cast<int>(note::SOL))
    {
        std::cout << static_cast<int>(note::SOL) << " ";
        std::cout << "SOL ";
    }
    if (accord & static_cast<int>(note::LA))
    {
        std::cout << "LA ";
    }
    if (accord & static_cast<int>(note::SI))
    {
        std::cout <<static_cast<int>(note::SI);
        std::cout << "SI ";
    }
}