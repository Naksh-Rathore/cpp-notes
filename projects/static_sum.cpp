#include <iostream>

int accumulate(int x) {
    static int sum = 0;
    sum += x;

    return sum;
}

int main() {

    for (int i = 1; i <= 100; i++)
        std::cout << "x: " << i << "\n" << "Sum: " << accumulate(i) << "\n";

    return 0;
}
