#include <iostream>
#include <vector>
#include <limits>
#include <string_view>
#include <string>

int calculateLCM(std::vector<int> factors);
int getInput(std::string_view prompt);

int main() {

    std::vector<int> factors {};
    int factorsAmt { getInput("Enter the amount of factors you will put in: ") };

    for (int i = 1; i <= factorsAmt; i++) {
        factors.push_back(getInput("Enter #" + std::to_string(i) + ": "));
    }

    int lcm = calculateLCM(factors);

    if (lcm == 0)  
        std::cout << "No LCM found" << "\n";
    else
        std::cout << "LCM: " << lcm << "\n";

    return 0;
}

int calculateLCM(std::vector<int> factors) {
    bool lcmFound { true }; 

    for (int i = 1; i <= 1000000; i++) {
        for (int factor : factors) {
            if (i % factor != 0) 
                lcmFound = false;
        }

        if (lcmFound == true) return i;

        lcmFound = true;
    }

    return 0;
}

int getInput(std::string_view prompt) {
    int var{};

    while (true) {
        std::cout << prompt;
        std::cin >> var;

        if (std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input! Please enter a positive number under 1 million.\n";  
        
            continue;
        }

        if (var <= 0 || var > 1000000) {
            std::cout << "Invalid input! Please enter a positive number under 1 million.\n";  
            continue;
        }

        return var;
    }
}
