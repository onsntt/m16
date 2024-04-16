#include <iostream>
#include <vector>
int main() {
    int decimal;
    while(true)
    {
      std::cout << "Enter your decimal value: ";
      std::cin >>decimal;
         if (decimal == -1) return 0;
           else
             {
                std::vector<int> vec(0);
                int result;
                    do {
                         result = decimal%2;
                         vec.push_back(result);
                         decimal = decimal/2;
                       }
                        while (decimal > 0);


                            for (int i = vec.size() -1; i >= 0; i--)
                                {
                                     std::cout << vec[i] << " ";
                                }
                                     std::cout << "\n";
            }
    }









}