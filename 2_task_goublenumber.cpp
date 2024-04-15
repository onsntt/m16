#include <iostream>

int main()
{
    std::string integerNumber;
    std::string doubleNumber;
    std::string resultString;
    double realDoubleNumber;

    std::cout << "Enter an integer number: ";
    std::cin >> integerNumber;
    std::cout << "Enter a double number: ";
    std::cin >> doubleNumber;
    resultString = integerNumber + '.' + doubleNumber;
    std::cout << "Result STRING is: " << resultString << "\n";
    realDoubleNumber = std::stod(resultString);
    std::cout << "Real double number: " << realDoubleNumber << "\n";
}