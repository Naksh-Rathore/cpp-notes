# Prefix vs Postfix incrementing

In C++, both prefix (`++variable`) and postfix (`variable++`) increment operators increase the value of a variable by one. The fundamental difference lies in the timing of the increment relative to when the variable's value is used in an expression.

Prefix Increment (`++variable`)

Increments: the variable's value.
Returns: the new, incremented value.

Example:

```cpp
int x = 5;
int y = ++x; // x becomes 6, y is assigned 6
```

Postfix Increment (`variable++`):

Returns: the original value of the variable (before incrementing).
Increments: the variable's value.

Example:

```cpp
int x = 5;
int y = x++; // y is assigned 5, then x becomes 6
```

The same thing works with decrementation too.

# Ternary Operator

A short one-liner for simple if-else statements, useful for dynamic printing.

Syntax: 

```cpp
condition ? expression1 : expression2;
```

It is the same as this:

```cpp
if (condition)
    expression1;
else
    expression2;
```

Example:

```cpp
#include <iostream>

int main() {

    int x = 1;
    int y = 2;
    int max = ((x > y) ? x : y);

    std::cout << "Max number between " << x << " and " << y << " is " << max << "\n";

    return 0;
}
```
Output: `Max number between 1 and 2 is 2`
