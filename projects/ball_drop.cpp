#include <iostream>
#include <string>
#include <limits>

double calculateBallHeight(double towerHeight, int seconds);
double getTowerHeight();

int main() {

    double towerHeight{ getTowerHeight() };
    double ballHeight { towerHeight }; // Ball starts at tower height


    for (int i = 0; ; ++i) {
        std::cout << i << " seconds: ";

        ballHeight = calculateBallHeight(towerHeight, i);

        if (ballHeight <= 0) {
            std::cout << "Ball fell to the ground" << "\n";
            break;
        }

        std::cout << "Height is " << ballHeight << " meters" << "\n";
    }

    return 0;
}

double calculateBallHeight(double towerHeight, int seconds) {
    const double gravity { 9.8 };
    
    double fallDistance { gravity * (seconds * seconds) / 2.0 };
    double ballHeight { towerHeight - fallDistance };

    return ballHeight;
}

double getTowerHeight() {
    double towerHeight{};

    while (true) {
        std::cout << "Enter the tower height in meters: ";
        std::cin >> towerHeight;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a positive double.\n";
            continue;
        }

        if (towerHeight < 1) {
            std::cout << "Invalid input! Please enter a positive double.\n";
            continue;
        }

        break;
    }

    return towerHeight;
}
