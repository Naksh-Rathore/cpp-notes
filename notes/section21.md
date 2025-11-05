# Operator Overloading

Operator overloading is a feature which provides a mechanism to create and resolve function calls to multiple functions with the same name, so long as each function has a unique function prototype. This allows you to create variations of a function to work with different data types, without having to think up a unique name for each variant.

Example:

```cpp
int x { 2 };
int y { 3 };
std::cout << x + y << '\n';
```

The compiler comes with a built-in version of the plus operator (`+`) for integer operands -- this function adds integers `x` and `y` together and returns an integer result. When you see the expression `x + y`, you can translate this in your head to the function call `operator+(x, y)` (where `operator+` is the name of the function).

## Overloading Operators using friend functions

Some of the most commonly used operators in C++ are the arithmetic operators -- that is, the plus operator (+), minus operator (-), multiplication operator (*), and division operator (/). Note that all of the arithmetic operators are binary operators -- meaning they take two operands -- one on each side of the operator. All four of these operators are overloaded in the exact same way.

Example:

```cpp
#include <iostream>

class Cents
{
private:
	int m_cents {};

public:
	Cents(int cents) : m_cents{ cents } { }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2);

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + c2.m_cents;
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}
```
