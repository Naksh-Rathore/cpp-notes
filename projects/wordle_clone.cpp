#include <iostream>
#include <string>
#include <random>
#include <array>
#include <string_view>
#include <limits>
#include <cctype>
#include <algorithm>

int getRandomNumber(int start, int endInclusive);

class Board {
    private:
        std::string m_word{};
        std::string m_userGuess{};
        std::array<int, 5> m_colors{};

        static constexpr std::array<std::string_view, 20> m_wordlist {
            "apple", "bread", "chair", "dream", "flame",
            "grape", "house", "knife", "light", "money",
            "ocean", "plant", "queen", "river", "stone",
            "table", "tiger", "water", "world", "zebra"
        };

    public:
        Board()
        : m_word { m_wordlist.at( getRandomNumber(0, static_cast<int>(m_wordlist.size() - 1)) ) }
        {    
        }

        bool checkWin() {
            for (int i = 0; i < 5; i++) {
                if (m_userGuess.at(i) == m_word.at(i))
                    m_colors.at(i) = 0;
                
                else if (m_word.find(m_userGuess.at(i)) != std::string::npos)
                    m_colors.at(i) = 1;
                
                else
                    m_colors.at(i) = 2;
            }

            for (int color : m_colors)
                if (color != 0) return false;

            return true;
        }

        std::string word() { return m_word; }
        std::array<int, 5> colors() { return m_colors; }

        std::string userGuess() { return m_userGuess; }
        void setUserGuess(std::string_view userGuess) { m_userGuess = userGuess; }
};

void getUserInput(std::string& var, std::string_view prompt);
bool isAlphaString(std::string_view str);
void printUserGuess(Board &board);

int main() {

    Board board{};
    std::string tempUserGuess{};

    while (true) {
        std::cout << "[DEBUG]: " << board.word() << "\n";

        getUserInput(tempUserGuess, "Enter your guess: ");
        board.setUserGuess(tempUserGuess);

        if (board.checkWin()) {
            printUserGuess(board);
            std::cout << "Hooray! You won!" << "\n";
            break;
        }

        printUserGuess(board);
    }

    return 0;
}

int getRandomNumber(int start, int endInclusive) {
    std::mt19937 mt{ std::random_device{}() }; 
    std::uniform_int_distribution<int> randNum{ start, endInclusive };

    return randNum(mt);
}

void getUserInput(std::string& var, std::string_view prompt) {
    while (true) {
        std::cout << prompt;
        std::cin >> var;

        if (std::cin.fail() || var.length() != 5 || !isAlphaString(var)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a 5 letter word.\n";

            continue;
        }

        break;
    }

    std::transform(var.begin(), var.end(), var.begin(),
               [](unsigned char c){ return std::tolower(c); });
}

bool isAlphaString(std::string_view str) {
    if (str.empty()) return false;

    for (unsigned int character : str)
        if (!std::isalpha(character)) return false;

    return true;
}

void printUserGuess(Board& board) {
    std::cout << board.userGuess() << "\n";

    for (int color : board.colors()) {
        if (color == 0)
            std::cout << "G";
        
        else if (color == 1)
            std::cout << "Y";
        
        else
            std::cout << "R";
    }

    std::cout << "\n";
}
