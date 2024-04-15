#include <iostream>

int main()
{
    std::cout << "Enter the string with to float numbers and arithmetic operations: ";
    std::string inputString;
    std::cin >> inputString;
    std::string number1, number2;
    float num1, num2;
    char operation;
    int yo = 0;
    while (inputString[yo] != '+' && inputString[yo] != '-' && inputString[yo] != '*' && inputString[yo] != '/')
    {
        number1 += inputString[yo];
        yo++;
    }
        operation = inputString[yo];
         yo++;
    while (inputString[yo] != '\0')
    {
        number2 += inputString[yo];
        yo++;
    }
    num1 = std::stof(number1);
    num2 = std::stof(number2);
    if (operation == '+')
    {
        std::cout << num1 + num2;
    }
    else if (operation == '-')
    {
        std::cout << num1 - num2;
    }
    else if (operation == '*')
    {
        std::cout << num1 * num2;
    }
    else if (operation == '/')
    {
        std::cout << num1 / num2;
    }
}