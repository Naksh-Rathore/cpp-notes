#include <iostream>
#include <limits>
#include <vector>

std::vector<int> factorInt(int multiple);

int main() {
    
    int multiple{};

    while (true) {
        std::cout << "Enter a number to factor: ";
        std::cin >> multiple;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a positive integer.\n";
            continue;
        }

        if (multiple < 1) {
            std::cout << "Invalid input! Please enter a positive integer.\n";
            continue;
        }

        break;
    }

    std::cout << "\nFactors of " << multiple << ":" << "\n"; 
    std::vector<int> factors { factorInt(multiple) };

    for (int factor : factors) 
        std::cout << factor << " ";
    

    return 0;
}

std::vector<int> factorInt(int multiple) {
    std::vector<int> factors {};

    for (int i = 1; i <= multiple; i++) {
        if (multiple % i == 0) 
            factors.push_back(i);
    }

    return factors;
}
