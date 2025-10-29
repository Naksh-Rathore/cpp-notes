#include <iostream>
#include <vector>
#include <array>
#include <string_view>

#define _USE_MATH_DEFINES
#include <cmath>

std::vector<std::array<double, 2>> createCircle(double circleCenterX, double circleCenterY, double radius);
double getUserInput(std::string_view prompt);

int main() {

    double centerX { getUserInput("Enter X cord of the center of the circle: ") };
    double centerY { getUserInput("Enter Y cord of the center of the circle: ") };
    double radius { getUserInput("Enter radius of the circle: ") };

    std::vector<std::array<double, 2>> points { createCircle(centerX, centerY, radius) };

    for (int i = 0; i < points.size(); i++) {
        std::cout << i << ") X: " << points.at(i).at(0) << "\n";
        std::cout << i << ") Y: " << points.at(i).at(1) << "\n\n";
    }

    return 0;
}

std::vector<std::array<double, 2>> createCircle(double circleCenterX, double circleCenterY, double radius) {
    std::vector<std::array<double, 2>> points{};
    std::array<double, 2> cords{};

    for (double theta = 0; theta <= 2 * M_PI; theta += M_PI / 180) {
        cords.at(0) = circleCenterX + radius * cos(theta);
        cords.at(1) = circleCenterY + radius * sin(theta);

        points.push_back(cords);
    }

    return points;
}

double getUserInput(std::string_view prompt) {
    double input{};

    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (!std::cin.fail()) break;

        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid input! Please enter a number.\n";  
    }

    return input;
}
