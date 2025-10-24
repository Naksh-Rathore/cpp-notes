#include <iostream>
#include <limits>
#include <vector>

std::vector<int> getFibonacciSequence(int len);

int main() {
    
    int fibonacciLen{};

    while (true) {
        std::cout << "Enter how many numbers you want to generate: ";
        std::cin >> fibonacciLen;

        if (std::cin.fail()) { 
            std::cin.clear();  // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input
            std::cout << "Invalid input! Please enter a positive number under 48 (to avoid overflow).\n";  

            continue;
        }

        if (fibonacciLen <= 0 || fibonacciLen >= 48) {
            std::cout << "Invalid input! Please enter a positive number under 48 (to avoid overflow).\n";  
            continue;
        }

        break;
    }

    std::vector<int> fibonacciSeq { getFibonacciSequence(fibonacciLen) };

    for (int num : fibonacciSeq) {
        std::cout << num << " ";
    }

    std::cout << "\n";
    
    return 0;
}

std::vector<int> getFibonacciSequence(int len) {
    std::vector<int> fibonacciSeq {0, 1};
    int currentIndex { 1 };

    int nextNum{};

    for (int i = 0; i < len; i++) {
        nextNum = fibonacciSeq.at(currentIndex) + fibonacciSeq.at(currentIndex - 1);
        fibonacciSeq.push_back(nextNum);

        currentIndex++;
    }

    return fibonacciSeq;
}
