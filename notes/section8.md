# If statements

Same as C, Java, JavaScript, C#. Don't really need overcomplicate.

Simple one-liner:

```cpp
if (condition) expression;
```

Braces aren't always needed but should be used when
more than one line executes in a function.

Example:

```cpp
if (condition)
    expression;
```

## Constexpr if statments


Normally, the conditional of an if-statement is evaluated at runtime.

However, consider the case where the conditional is a constant expression, such as in the following example:

```cpp
#include <iostream>

int main()
{
	constexpr double gravity{ 9.8 };

	// reminder: low-precision floating point literals of the same type can be tested for equality
	if (gravity == 9.8) // constant expression, always true
		std::cout << "Gravity is normal.\n";   // will always be executed
	else
		std::cout << "We are not on Earth.\n"; // will never be executed

	return 0;
}
``` 

Example using `constexpr`:

```cpp
#include <iostream>

int main()
{
	constexpr double gravity{ 9.8 };

	if constexpr (gravity == 9.8) // now using constexpr if
		std::cout << "Gravity is normal.\n";
	else
		std::cout << "We are not on Earth.\n";

	return 0;
}
```

The `constexpr` statement in the `if` tells the compiler to check this
statement at compile-time, not runtime. This can lead to better performance since the compiler can just check it once and run it faster
every other time.

# Switch statement

Same as C.

Syntax:

```cpp
switch(var) {
    case check:
        break;
    default:
        break;
}
```

You **cannot put conditions in the cases**, unlike JavaScript.
