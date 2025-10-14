# Printing

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World" << "\n";
}
```

Output: `Hello World`


`std::cout` means character output and it **prints whatever is given** to it by the angle brackets (insertion operators)

By default, `std::cout` doesn't print a newline, so you need to manually add `<< "\n"` to the end of *almost* every print statement.

# Variables

A variable is a region in memory where a value is stored. It could be numbers, text, binary, and more. Here are some examples:

```cpp
#include <iostream>

int main() {
    int age {12};
    std::string name {"Bob"};
    char grade {'A'};
}
```

This is called uniform initialization, and it’s the **most modern and safe** form of initializing variables. (There are a few detailed reasons why, but the short version is: it helps prevent unexpected narrowing or type conversion.)

## Initializations

```cpp
#include <iostream>

int main() {
    int x(5);
    int x = 5;
    int x {5};
}
```

All of these are setting the variable `x` to `5`, but in different ways.

1. **Direct Initialization**: When the constructor is directly called to initialize a variable

2. **Copy Initalization**: When a value is directly copied to a variable, somewhat unsafe

3. **Uniform Initialization**: When a variable is set with curly braces, like a list. **Most safe and modern option**.

# User Input

## std::cin

So now we can make variables, and print to the console. Let's learn how to get user input!

For getting user input via `stdin`, we use the `std::cin` function. It stands for **character input**, and is used to get **user input** from `stdin`

The syntax of it is this:

```cpp
std::cin >> var;
```

Where  `var` is any variable that the user input is moved to.

Also, remember that for `std::cout`, `<<` is used but for `std::cin`, `>>` is used.

Here is an example of a program that echoes back something you put into a variable, `x`.

```cpp
#include <iostream>

int main() {

    int x {};

    std::cout << "Enter a value for X: ";
    std::cin >> x;
    
    std::cout << "You entered this for X: " << x << "\n";

    return 0;
}
```

Example workflow:

```bash
$ g++ main.cpp -o main
$ ls
main.c main

$ ./main
Enter a value for X: 12
You entered this for X: 12
$ ./main
Enter a value for X: 2
You entered this for X: 2
$
```


Note: `std::cin` doesn’t print a newline — it just waits for you to press Enter. The newline you see comes from your input, not from the program.

```
Enter a number: 2
Thanks!
```

Use this:

```cpp
int x {};

std::cout << "Enter a number";
std::cin >> x;
```

If `std::cin` fails, you can send a message like this:

```cpp
#include <limits>
#include <iostream>

int main() {
    int x{};

    std::cin >> x;

    if (std::cin.fail()) { 
            std::cin.clear();  // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input
            std::cout << "Invalid input! Please enter a number.\n";  

            return 1; // Returns exit code of 1 (error)
    }
}
```

If the error handling is in a function, pass the variable (in this case `x`) by reference, not by value so it can be reset properly.

## std::getline

For strings, `std::cin` stops at the first space, like `scanf()` in C. To get around that, we can use the `std::getline` function.

**NOTE:** `std::getline` **is only viable on strings. Integers and other datatypes cannot be resolved with this**

Syntax:

```cpp
#include <iostream>

std::getline(std::cin, buffer);
```

It returns false on an error, so that can be used to failure-check.

We do not need the `std::cin.ignore` part, so this is what a robust check looks like:

```cpp
while (true) {
    std::cout << prompt;

    if (!std::getline(std::cin, buffer)) {
        std::cin.clear();
        std::cout << "Bad input. Try again.\n";
        continue;
    }

    break;
}
```

If the error handling is in a function, pass the variable (in this case `x`) by reference, not by value so it can be reset properly.

## IMPORTANT NOTE

Use `std::getline()` only when you need a space in user input since you have to clear the buffer before using it.

Here is an example:

```cpp
#include <iostream>
#include <limits>
#include <string>

int main() {
    
    int x{};
    std::string y {}; 

    std::cin >> x;

    // Clear the buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::getline(std::cin, y);

    return 0;
}
```

# Unintialized variables and undefined behaviour

Remember, values such as `int x;` when defined with no value, can have garbage values. Keep in mind to always try and make define values like `int x{};` or `int x = 0;` so there will be no garbage value.
