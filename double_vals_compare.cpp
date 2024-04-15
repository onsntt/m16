#include <iostream>
#include <cmath>

bool isRelativelyEqual(double lhs, double rhs, double epsilon)
{
    return std::abs(lhs - rhs) < epsilon;
}

int main()
{
    double lhs = 0.;
    double rhs = 0.;
    double epsilon = 0.;

    std::cin >> lhs >> rhs >> epsilon;
    std::cout << std::boolalpha << isRelativelyEqual(lhs, rhs, epsilon) << std::endl;
    return 0;
}