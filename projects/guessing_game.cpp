#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

bool checkWin(int userGuess, int answer, int &attempts);
bool validateUserInput(int &userGuess);

int main() {
    srand(time(0)); // Seed for random number which based on time (somewhat predictable?)

    int answer {(rand() % 100) + 1}; // Generates a random number between 1-100 inclusive
    int attempts {0}; 
    int userGuess{};

    while (true) {
        std::cout << "Enter your guess between 1 and 100: ";
        std::cin >> userGuess;

        if (validateUserInput(userGuess)) {
            continue;
        }

        if (checkWin(userGuess, answer, attempts)) {
            break;
        }
    }
}

bool checkWin(int userGuess, int answer, int &attempts) {
    attempts++;

    if (userGuess == answer) {
        std::cout << "Hooray! You got the correct answer, " << answer << " in " << attempts << " attempt(s)!" << "\n";
        return true;
    }

    else if (userGuess > answer) {
        std::cout << "Too high! Attempts: " << attempts << "\n";
    }

    else {
        std::cout << "Too low! Attempts: " << attempts << "\n";
    }

    return false;
}

// Returns false if continue isn't needed and true if it is needed
bool validateUserInput(int &userGuess) {
    if (std::cin.fail()) { 
            std::cin.clear();  // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input
            std::cout << "Invalid input! Please enter a number.\n";  
            
            return true;
    }

    if (userGuess > 100) {
        std::cout << "Your was too high out of range! Give guesses that are 1-100" << "\n";
        return true;
    }

    else if (userGuess < 1) {
        std::cout << "Your was too low out of range! Give guesses that are 1-100" << "\n";
        return true;
    }
    
    return false;
}
