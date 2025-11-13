# Pointers & references to different inheritance levels

First of all, when you create a derived class, it is composed of multiple parts: one part for each inherited class, and a part for itself.

However, since derived class has a a base part, a more interesting question is whether C++ will let us set a base pointer or reference to a derived object. It turns out, we can!

```cpp
class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    std::string_view getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }
};

#include <iostream>

int main()
{
    Derived derived{ 5 };

    // These are both legal!
    Base& rBase{ derived }; // rBase is an lvalue reference (not an rvalue reference)
    Base* pBase{ &derived };

    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

    return 0;
}
```

Output:

```
derived is a Derived and has value 5
rBase is a Base and has value 5
pBase is a Base and has value 5
```

This output probably differs from what you predicted!

The reason is because it turns out that because `rBase` and `pBase` are a `Base` reference and pointer, they can only see members of `Base` (or any classes that `Base` inherited). So even though `Derived::getName()` shadows (hides) `Base::getName()` for `Derived` objects, the `Base` pointer/reference can not see `Derived::getName()`. Consequently, they call `Base::getName()`, which is why `rBase` and `pBase` report that they are a `Base` rather than a `Derived`.

# Virtual functions

A virtual function is a special type of member function that, when called, resolves to the most-derived version of the function for the actual type of the object being referenced or pointed to.

A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides.

Syntax:

```cpp
virtual funcName(params) { 
    code 
};
```
Before:

```cpp
#include <iostream>
#include <string_view>

class Base
{
public:
    std::string_view getName() const { return "Base"; }
};

class Derived: public Base
{
public:
    std::string_view getName() const { return "Derived"; }
};

int main()
{
    Derived derived {};
    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}
```

Output:

```
rBase is a Base
```

After:

```cpp
#include <iostream>
#include <string_view>

class Base
{
public:
    virtual std::string_view getName() const { return "Base"; } // note addition of virtual keyword
};

class Derived: public Base
{
public:
    virtual std::string_view getName() const { return "Derived"; }
};

int main()
{
    Derived derived {};
    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}
```

Output:

```
rBase is a Derived
```

# Polymorphism 

In programming, polymorphism refers to the ability of an entity to have multiple forms (the term “polymorphism” literally means “many forms”). For example, consider the following two function declarations:

```cpp
int add(int, int);
double add(double, double);
```
