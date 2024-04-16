#include <iostream>

int main() {

int operand1 ;   
int operand2 ;   
std::cin >>operand1 >> operand2;
int bitsResult;
std::cout << "Operand 1 = " << operand1 << ", operand 2 = " << operand2 << "\n";
 bitsResult = operand1 >> 1; //  operand2;
std::cout << bitsResult << " Right shift operand 1\n";

bitsResult = operand1 <<1;
std::cout << bitsResult << " Left shift operand 1\n";

bitsResult = operand1 & operand2;
std::cout << bitsResult << " AND (&)\n";

bitsResult = operand1 | operand2;
std::cout << bitsResult << " OR (|)\n";

bitsResult = operand1 ^ operand2;
std::cout << bitsResult << " Xor (&)\n";

bitsResult = ~operand1;
std::cout << bitsResult << " NOT operand1 (&)\n";
}