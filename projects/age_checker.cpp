#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <limits>

struct person {
    std::string name;
    int age;
};


std::string askForName(int personNum);
int askForAge(std::string_view personName);

std::string getOlderPerson(struct person person1, struct person person2);

int main() {
    std::array<struct person, 2> people {};

    for (int i = 0; i <= 1; i++) {
        people.at(i).name = askForName(i + 1);
        people.at(i).age = askForAge(people.at(i).name);
    }

    std::string olderPerson { getOlderPerson(people.at(0), people.at(1)) };

    if (olderPerson == "")
        std::cout << "Both " << people.at(0).name << " and " << people.at(1).name << " are the same age";
    
    else
        std::cout << olderPerson << " is oldest!" << "\n";

    return 0;
}

std::string askForName(int personNum) {
    std::string personName{};

    while (true) {
        std::cout << "Enter the name of #" << personNum << ": ";
        if (std::getline(std::cin >> std::ws, personName)) break;

        std::cin.clear();
        std::cout << "Invalid input. Please try again" << "\n";
    }

    return personName;
}

int askForAge(std::string_view personName) {
    int personAge{};

    while (true) {
        std::cout << "Enter the age of " << personName << ": ";
        std::cin >> personAge;

        if (!std::cin.fail()) break;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again" << "\n";
    }

    return personAge;
}

std::string getOlderPerson(struct person person1, struct person person2) {
    if (person1.age > person2.age) 
        return person1.name;
    else if (person1.age < person2.age)
        return person2.name;

    else 
        return "";
}
