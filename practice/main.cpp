#include <iostream>
#include <string>
#include <array>

#include "input_check.h"
#include "calculations.h"

int main() {
    std::array<double, 2> nums {};
    char op;

    for (int i = 0; i < 2; i++) 
        getUserInput("Enter #" + std::to_string(i + 1) + ": ", nums[i]);
    
    do 
        getUserInput("Enter a character (+, -, /, *): ", op);
    while (op != '+' && op != '-' && op != '/' && op != '*');

    double result { doArithmetic(op, nums[0], nums[1]) };

    std::cout << nums[0] << " " << op << " " << nums[1] << " = " << result;
}
