#include <iostream>
#include <sstream>
// #include <cmath>

int main()
{
    // Строка, в которую заранее был скопирован пользовательский ввод
    std::string inputString = "Yob Anderson 55 62.7";
    std::stringstream temp_stream(inputString);
    float hs;
    int age;
    std::string firstName;
    std::string lastName;

    temp_stream >> firstName >> lastName >> age >> hs;

    std::cout << "firstName: " << firstName << '\n';
    std::cout << "lastName: " << lastName << '\n';
    std::cout << "age: " << age << '\n';
    std::cout << "hatsize: " << hs << "\n";
    // return 0;
}