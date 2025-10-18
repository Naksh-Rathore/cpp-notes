#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <limits>

std::string getBinaryValue(int decimal);

int main() {

    int decimal{};

    while (true) {
        std::cout << "Enter the decimal to convert to binary: ";
        std::cin >> decimal;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cout << "Invalid input. Please enter a positive number.";
            continue;
        }

        if (decimal < 0) {
            std::cout << "Invalid input. Please enter a positive number.";
            continue;
        }

        break;
    }

    std::string binary { getBinaryValue(decimal) };

    std::cout << decimal << " to binary: " << binary << "\n";

}

std::string getBinaryValue(int decimal) {
    if (decimal == 0) return "0";

    std::string binary{};

    while (decimal > 0) {
        int lsb = decimal & 1;
        binary += std::to_string(lsb);

        decimal >>= 1;
    }

    std::reverse(binary.begin(), binary.end());

    return binary;
}
