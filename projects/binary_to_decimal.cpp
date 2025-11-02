#include <iostream>
#include <string>
#include <string_view>
#include <limits>
#include <cmath>

int binaryToDecimal(std::string_view binary);

int main() {

    std::string binary{};

    while (true) {
        std::cout << "Enter a binary number: ";
        std::cin >> binary;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a proper binary number.\n"; 
            
            continue;
        }

        if (binary.find_first_not_of("01") != std::string::npos) {
            std::cout << "Invalid input! Please enter a proper binary number.\n"; 
            continue;
        }

        break;
    }

    int decimal { binaryToDecimal(binary) };

    std::cout << binary << " to decimal is " << decimal << "\n";

    return 0;
}

int binaryToDecimal(std::string_view binary) {
    int decimal { 0 };
    int power { 0 };

    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary.at(i) == '1')
            decimal += static_cast<int>(pow(2, power));
        
        power++;
    }

    return decimal;
}
