#include <iostream>
#include <cmath>

int main()
{

    std::string str = "137";
    int val = 0;
    
    for (int i = 0; i < str.length(); i++)
    {

        int power = ((str[i] - '0') - 1);  // нам нужна степень двойки числа, указывающего номер ноты. Но это у нас оно первое, а в реале - нулевое, вычитаем единицу
        val += pow(2, power);

       
    }
    
    std::cout << val << "\n";

   if (val & 8 ) std::cout << "Yes";
    else std::cout << "No";
    //std::cout << val << "\n";
}