#include <cstddef>
#include <iostream>
#include <array>
#include <algorithm>
#include <utility>

template <std::size_t N>
void bubbleSort(std::array<int, N>& unsortedArray);

int main() {

    std::array<int, 5> array{7, 12, 9, 11, 3};
    bubbleSort(array);

    for (int num : array)
        std::cout << num << " ";

    std::cout << "\n";

    return 0;
}

template <std::size_t N>
void bubbleSort(std::array<int, N>& unsortedArray) {
    for (int i = 0; i < N; i++) {
        int currentIndex { 0 };

        for (int a = 0; a < N - 1; a++) {

            if (unsortedArray.at(currentIndex) > unsortedArray.at(currentIndex + 1))
                std::swap(unsortedArray.at(currentIndex), unsortedArray.at(currentIndex + 1));
        
            currentIndex++;
        }
    }
}
