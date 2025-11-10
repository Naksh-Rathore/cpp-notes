#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <cctype>
#include <limits>
#include <algorithm>
#include <cmath>

bool isHex(std::string_view hexVal, std::unordered_map<char, int>& alphaHex);
int hexToDecimal(std::string_view hexVal, std::unordered_map<char, int>& alphaHex);

int main() {

    std::string hexVal{};
    std::unordered_map<char, int> alphaHex { { 'a', 10 }, { 'b', 11 }, { 'c', 12 }, { 'd', 13 }, { 'e', 14 }, { 'f', 15 }  };

    while (true) {
        std::cout << "Enter your hexadecimal number (excluding 0x prefix): ";
        std::cin >> hexVal;

        if (std::cin.fail() || !isHex(hexVal, alphaHex)) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input! Please enter a hex number.\n";
            
            continue;
        }

        std::transform(hexVal.begin(), hexVal.end(), hexVal.begin(),
        [](unsigned char c){ return std::tolower(c); });

        break;
    }

    std::cout << hexToDecimal(hexVal, alphaHex) << "\n";

    return 0;
}

bool isHex(std::string_view hexVal, std::unordered_map<char, int>& alphaHex) {
    for (char hexDigit : hexVal) {
        if (std::isdigit(hexDigit)) continue;
        if (alphaHex.find(hexDigit) == alphaHex.end()) return false;
    }

    return true;
}

int hexToDecimal(std::string_view hexVal, std::unordered_map<char, int>& alphaHex) {
    int decimalVal { 0 };
    int power { 0 };

    for (int i = hexVal.length() - 1; i >= 0; i--) {
        if (std::isdigit(hexVal.at(i))) {
            decimalVal += pow(16, power) * static_cast<int>(hexVal.at(i) - '0'); 
            power++;

            continue;
        }
        
        for (auto pair : alphaHex) {
            if (pair.first == hexVal.at(i)) {
                decimalVal += pow(16, power) * pair.second; 
                power++;
            }
        }
    }

    return decimalVal;
}
