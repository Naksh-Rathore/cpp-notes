# Const vs Constexpr


In C++, both `const` and `constexpr` are used to indicate immutability, but they differ in when that immutability is guaranteed and how they can be used.

`const`:

Runtime or Compile-time evaluation: A const variable's value can be determined either at compile time or at runtime. Once initialized, its value cannot be changed.

Purpose: Primarily ensures that a variable or object remains unchanged after its initial assignment, preventing accidental modification.

Usage: Can be applied to variables, pointers, references, and member functions (to indicate that the function does not modify the object's state).

`constexpr`:

Compile-time evaluation: A constexpr variable or function must be evaluable at compile time. This means its value is known and fixed during the compilation process.

Purpose: Enables compile-time computations, leading to potential performance benefits (no runtime overhead for calculation) and allowing the use of the result in contexts requiring constant expressions (e.g., array sizes, template arguments).

Usage: Can be applied to variables, functions, and constructors. constexpr variables implicitly imply const. 

# Intro to std::string_view

When passing `std::strings` as function arguments, you should not use 
passing by value since the copy is **really expensive** in terms of memory usage.

To address this issue, C++17 introduced `std::string_view` (in the `<string_view>` header). `std::string_view` provides read-only access to an existing string (a C-style string, a `std::string`, or another `std::string_view`) without making a copy. Read-only means that we can access and use the value being viewed, but we can not modify it.

**Bad** Example:

```cpp
#include <iostream>
#include <string>

void printStr(std::string prompt) {
    std::cout << prompt << "\n";
}

int main() {

    std::string prompt { "Hello World!" };
    printStr(prompt);

    return 0;
}
```
**Good** Example:

```cpp
#include <iostream>
#include <string>
#include <string_view>

// Now takes in a std::string_view
void printStr(std::string_view prompt) {
    std::cout << prompt << "\n";
}

int main() {

    std::string prompt { "Hello World!" };
    printStr(prompt);

    return 0;
}
```
