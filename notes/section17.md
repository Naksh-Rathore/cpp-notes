# std::reference_wrapper

In arrays, values/variables of any object type can be a valid element. This includes objects with fundamental types, or objects that are compound types, such as classes or STL datatypes.

However, because references are not objects, you cannot make an array of references. The elements of an array must also be assignable, and references can’t be reseated.

```cpp
#include <array>
#include <iostream>

int main() {
    int x { 1 };
    int y { 2 };

    [[maybe_unused]] std::array<int&, 2> refarr { x, y }; // compile error: cannot define array of references

    int& ref1 { x };
    int& ref2 { y };
    [[maybe_unused]] std::array valarr { ref1, ref2 }; // ok: this is actually a std::array<int, 2>, not an array of references

    return 0;
}
```
To fix this issue, `std::reference_wrapper` is a standard library class template that lives in the `<functional>` header. It takes a type template argument `T`, and then behaves like a modifiable lvalue reference to `T`.

Example:

```cpp
#include <array>
#include <functional> // for std::reference_wrapper
#include <iostream>

int main()
{
    int x { 1 };
    int y { 2 };
    int z { 3 };

    std::array<std::reference_wrapper<int>, 3> arr { x, y, z };

    arr[1].get() = 5; // modify the object in array element 1

    std::cout << arr[1] << y << '\n'; // show that we modified arr[1] and y, prints 55

    return 0;
}
```
