#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <array>

void computeWin(std::string userChoice, std::string computerChoice);
std::string getComputerGuess();
bool userWins(std::string user, std::string comp);

int main() {

    srand(time(0));

    std::string userGuess;
    std::string computerGuess;

    while (true) {
        computerGuess = getComputerGuess();


        std::cout << "Enter your choice (rock, paper, scissors): ";
        std::cin >> userGuess;

        if (std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input! Please try again.\n";  

            continue;
        }

        if (userGuess != "rock" && userGuess != "scissors" && userGuess != "paper") {
            std::cout << "Invalid input! Please try again.\n";  
            continue;
        }

        computeWin(userGuess, computerGuess);
    }

    return 0;
}

bool userWins(std::string user, std::string comp) {
    return (user == "rock" && comp == "scissors") ||
           (user == "paper" && comp == "rock") ||
           (user == "scissors" && comp == "paper");
}

void computeWin(std::string userChoice, std::string computerChoice) {
    std::cout << "Computer choice: " << computerChoice << "\n";

    if (userChoice == computerChoice)
        std::cout << "You tied!\n";
    else if (userWins(userChoice, computerChoice))
        std::cout << "You won!\n";
    else
        std::cout << "You lost!\n";
}

std::string getComputerGuess() {
    std::array<std::string, 3> choices {"rock", "paper", "scissors"};
    std::string computerChoice { choices[rand() % 3] };

    return computerChoice;
}
