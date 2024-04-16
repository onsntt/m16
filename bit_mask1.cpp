#include <iostream>

int main() {


[[maybe_unused]] const char bitMask0 = 0b00000001;
[[maybe_unused]] const char bitMask1 = 0b00000010;
[[maybe_unused]] const char bitMask2 = 0b00000100;
[[maybe_unused]] const char bitMask3 = 0b00001000;
[[maybe_unused]] const char bitMask4 = 0b00010000;
[[maybe_unused]] const char bitMask5 = 0b00100000;
[[maybe_unused]] const char bitMask6 = 0b01000000;
[[maybe_unused]] const char bitMask7 = 0b10000000;

int testVar = 0x09;

std::cout << "Bit 2 is " << (testVar & bitMask2 ? "on\n" : "off\n") << "\n";  
//типо testVar = testVar | bitMask1; - 
testVar |= bitMask1 | bitMask2 | bitMask5; //47 - 000101111 - включаем биты 1,2 и 5
std::cout << testVar << "\n";
const char bitMask8 = ~bitMask0; //для выключения нулевого бита сначала готовим маску, обратную той, где бит0 вкючен
testVar = testVar & bitMask8 & ~bitMask3;  // и применим ее через побитовое И к переменной. Первернутая маска через побитовое И выключает тот бит, который она хранила до переворота
std::cout << testVar << "\n";
testVar = testVar ^ bitMask0; //маска с включенным битом через ХОР вкючает выключенный бит
std::cout << testVar << "\n";
testVar = testVar ^ bitMask0; // или выключает включенный
std::cout << testVar << "\n";
testVar ^= (bitMask1 | bitMask2); // это же можем сделать и несколькими масками, указав их через ИЛИ (|)
std::cout << testVar << "\n";   //32
testVar ^= (bitMask1 | bitMask2); // и обратно включим
std::cout << testVar << "\n";     // 38
}
// https://www.youtube.com/watch?v=t-2yQM3gXMY
// https://www.youtube.com/watch?v=jTsFtuMJpu0