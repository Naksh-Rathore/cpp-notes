#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <array>
#include <limits>
#include <cctype>
#include <algorithm>

struct GameBoard {
    std::vector<char> word{};
    std::vector<char> userGuess{};
};

GameBoard gameInit();
char getUserGuess(int triesLeft);
bool correctLetterCheck(GameBoard& game, char guess);
void printVector(std::vector<char> &vec);

int main() {

    GameBoard game { gameInit() };
    int triesLeft { 7 };
    char guess{};

    while (true) {
        if (triesLeft <= 0) {
            std::cout << "\n" << "You lost! The word was: ";
            printVector(game.word);
            break;
        }

        printVector(game.userGuess);
        guess = getUserGuess(triesLeft);

        if (correctLetterCheck(game, guess)) {
            std::cout << "Hooray! You got it right! Tries left: " << triesLeft << "\n";
        }

        else {
            triesLeft--;
            std::cout << "Try again! Tries left: " << triesLeft << "\n";
        }

        bool isWon { std::find(game.userGuess.begin(), game.userGuess.end(), '_') == game.userGuess.end() };
        
        if (isWon) {
            printVector(game.userGuess);
            std::cout << "\n" << "You won the game!" << "\n";
            break;
        }
    }

    return 0;
}

GameBoard gameInit() {
    const std::array<std::string, 20> words { "apple", "banana", "computer", "dragon", "elephant",
                                        "fantasy", "garden", "harmony", "island", "journey",
                                        "kangaroo", "lighthouse", "mountain", "notebook", "ocean",
                                        "penguin", "quantum", "rainbow", "sunshine", "telescope" };

    // Get random word from wordlist
    std::random_device rd;
    std::mt19937 mt{ rd() }; 
    std::uniform_int_distribution<size_t> die6{ 0, words.size() - 1};

    std::string word { words[die6(mt)] };

    //std::string word { "banana" }; // DEBUG
    //std::cout << word << "\n"; // DEBUG

    GameBoard game{};

    for (auto character : word) {
        game.userGuess.push_back('_');
        game.word.push_back(character);
    }

    return game;
}

char getUserGuess(int triesLeft) {
    
    char guess{};
    
    while (true) {
        std::cout << "Enter your guess (" << triesLeft <<  " tries left): ";
        std::cin >> guess;

        if (std::cin.fail()) { 
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input! Please enter a letter (case-insensitive).\n";  

            continue;
        }

        if (!isalpha(guess)) {
            std::cout << "Invalid input! Please enter a letter (case-insensitive).\n";  
            continue;
        }

        break;
    }

    return tolower(guess);
}

bool correctLetterCheck(GameBoard& game, char guess) {
    bool isFound { false };
    
    for (int i = 0; i < game.userGuess.size(); i++) {
        if (game.word.at(i) == guess && game.userGuess.at(i) != guess) {
            isFound = true;
            game.userGuess.at(i) = game.word.at(i);
        }
    }

    return isFound;
}

void printVector(std::vector<char> &vec) {
    for (auto character : vec) {
        std::cout << character << " ";
    }

    std::cout << "\n";
}
