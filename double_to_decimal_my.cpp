#include <iostream>
#include <cmath>
#include <vector>


int main() {
while (true)
{
std::cout << "Enter your double value ";

std::string doubleString = "";
std::cin >> doubleString;
int sum = 0;
std::vector<bool>vec(doubleString.length());

for (int i = 0; i < doubleString.length(); i++)
  {
   if (doubleString[i] == '1' )
   vec[i] = true;
   else if (doubleString[i] == '0')  vec[i] = false;
   else
     {
       std::cout << "Incorrect input \n";
       return 0;
     } 
  }
 
for (int i = 0; i<vec.size(); i++)
  {
    if (vec[i] == true)
     {
       sum += pow(2,(vec.size()-1 - i));
     }

  }
std::cout << sum << "\n";

}
}