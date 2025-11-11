#include <iostream>
#include <array>
#include <limits>

template <size_t N>
int binarySearch(const std::array<int, N>& arr, int num, int high, int low);

int main() {

    const std::array<int, 11> arr { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int num{};

    while (true) {
        std::cout << "Enter the number to search for on a array of 0-10: ";
        std::cin >> num;

        if (std::cin.fail() || num < 0 || num > 10) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            
            std::cout << "Invalid input! Please enter a number from 0-10.\n";
            continue;  
        }

        break;
    }

    int foundIndex { binarySearch(arr, num, arr.size() - 1, 0) };
    std::cout << num << " found at index " << foundIndex << "\n";

    return 0;
}

template <size_t N>
int binarySearch(const std::array<int, N>& arr, int num, int high, int low) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr.at(mid) == num)
        return mid;
    else if (arr.at(mid) > num)
        return binarySearch(arr, num, mid - 1, low);
    else
        return binarySearch(arr, num, high, mid + 1);
}
