# Intro to containers & arrays

In general programming, a container is a data type that provides storage for a collection of unnamed objects (called elements).

While the container object itself typically has a name (otherwise how would we use it?), the elements of a container are unnamed. This is so that we can put as many elements in our container as we desire, without having to give each element a unique name! This lack of named elements is important, and is what distinguishes containers from other types of data structures. It is why plain structs typically aren’t considered containers -- their data members require unique names.

In programming, the number of elements in a container is often called it’s length (or sometimes count).

# Intro to std::vector

`std::vector` is one of the container classes in the C++ standard containers library that implements an array. `std::vector` is defined in the `<vector>` header as a class template, with a template type parameter that defines the type of the elements. Thus, `std::vector<int>` declares a `std::vector` whose elements are of type int.

Example:

```cpp
#include <vector>

int main() {
	// Value initialization (uses default constructor)
	std::vector<int> empty{}; // vector containing 0 int elements

	return 0;
}
```

To add an element use `vector.push_back(new_element)`.
If you need to prepend, use `std::deque`.

# Intro to std::array

`std::array` is a powerful datatype in C++, which is basically a non-resizable vector. It is mainly used in constant arrays and where memory usage is low and performance needs to be fast.

Example:

```cpp
#include <iostream>
#include <array> // for std::array and its functions

int main() {

    std::array<int, 5> arr { 1, 2, 3, 4, 5 };

    for (int element : arr) 
        std::cout << element << " ";

    return 0;   
}
```
Output:

```bash
$ g++ main.cpp -o main
$ ./main
1 2 3 4 5 
$
```


