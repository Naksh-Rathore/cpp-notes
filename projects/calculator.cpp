#include <iostream>
#include <string>
#include <array>
#include <limits>

double doArithmetic(char op, double num1, double num2);

template <typename T>
void getUserInput(std::string prompt, T &var);

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

double doArithmetic(char op, double num1, double num2) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0.0;
    }
}

template <typename T>
void getUserInput(std::string prompt, T &var) {
    while (true) {
        std::cout << prompt;
        std::cin >> var;

        if (!std::cin.fail()) break;

        std::cin.clear();  // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input
        std::cout << "Invalid input! Please try again.\n";  
    }
}
