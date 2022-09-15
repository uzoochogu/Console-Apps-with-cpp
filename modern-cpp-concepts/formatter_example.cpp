#include <format>
#include <print.hpp>
#include <iostream>

import MixedFraction;

int main()
{
    int num1{0}, num2{0};
    print("Enter a fraction: \n1. numerator: ");
    std::cin  >> num1;
    print ("\n2. Denominator: ");
    std::cin >> num2;
    MixedFraction mf{ num1, num2 };

    print("\nThe numbers expressed as a mixed fraction is: {}", mf);

    return 0;
}
