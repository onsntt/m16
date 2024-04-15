#include <iostream>
#include <vector>
int main()
{
    bool sign = 0;
    float decimal;
    int integer;
    float xvost;
    while (true)
    {
        std::cout << "Enter your decimal value: ";
        std::cin >> decimal;
        if (decimal < 0)
        {
            sign = true;
            decimal = -decimal;
        }
        integer = int(decimal);
        xvost = (decimal - integer);
        /*
            do{
               inter = inter * 10;
              } while (int(inter) != inter);
            xvost = inter;
        */
        std::cout << integer << " " << xvost << "\n";

        std::vector<int> vecD(0);
        if (decimal == -1)
            return 0;
        else
        {
            std::vector<int> vec(0);
            int result;
            do
            {
                result = integer % 2;
                vec.push_back(result);
                integer = integer / 2;
            } while (integer > 0);

            if (sign)
                std::cout << "-";

            for (int i = vec.size() - 1; i >= 0; i--)
            {
                std::cout << vec[i] << " ";
            }

            // let's begin double part
            if (xvost != 0)
            {
                std::cout << ".";
                float res = xvost;
                do
                {
                    res *= 2;
                    if (res < 1)
                    {
                        vecD.push_back(0);
                    }
                    if (res > 1)
                    {
                        vecD.push_back(1);
                        res = res - 1;
                    }

                    if (res == 1)
                        vecD.push_back(1);

                } while (res != 1);
            }
            for (int i = 0; i < vecD.size(); i++)
            {
                std::cout << vecD[i] << " ";
            }
        }
        sign = false;
        std::cout << "\n";
    }
}
