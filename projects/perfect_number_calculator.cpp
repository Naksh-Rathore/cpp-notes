#include <iostream>
#include <string>
#include <vector>
#include <limits>

bool isPerfectNumber(int num);

int main() {

    int num{};

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        
        
        if (std::cin.fail()) { 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";  
            continue;
        }

        break;
    }

    std::string msg { isPerfectNumber(num) ? "DEFINITELY" : "NOT" };

    std::cout << num << " is " << msg << " a perfect number" << "\n";

    return 0;
}

bool isPerfectNumber(int num) {
    int sum{};

    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            sum += i;
    }
        
    return (sum == num);
}

