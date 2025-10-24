#include <iostream>
#include <string>
#include <string_view>
#include <limits>

int doubleSecondDigit(std::string_view creditCardNum);

int main() {

    std::string creditCardNum{};

    while (true) {
        std::cout << "Enter a credit card number you would like to test: ";
        std::cin >> creditCardNum;

        if (std::cin.fail()) { 
            std::cin.clear();  // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input
            std::cout << "Invalid input! Please enter a number.\n";  

            continue;
        }

        if (creditCardNum.size() <= 0) {
            std::cout << "Invalid input! Please enter a number.\n";  
            continue;
        }

        break;
    }

    int sum { doubleSecondDigit(creditCardNum) };
    std::string endMsg { sum % 10 == 0 ? "It is a valid credit card number" : "It is NOT a valid credit card number"};

    std::cout << endMsg << "\n";

    return 0;
}

int doubleSecondDigit(std::string_view creditCardNum) {
    int sum { 0 } ;
    bool isSecond = false;

    for (int i = creditCardNum.length() - 1; i >= 0; i--) {
        int digit = creditCardNum.at(i) - '0';

        if (isSecond) {
            digit *= 2;
        }

        sum += (digit / 10) + (digit % 10);
        isSecond = !isSecond;
    }

    return sum;
}
