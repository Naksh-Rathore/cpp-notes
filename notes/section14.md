# What is OOP (Object Oriented Programming)?

OOP is creating programs with types (objects) that have special properties which allow it to do many things.

For example, a human could have a walk function, sleep function, eat function, and more! A human could also have properties like age, weight, height, name, gender, and more. This is the beauty of OOP, it promotes modularized code which can lead to scable codebases.

# Intro to Classes

## Defining a Class

Because a class is a program-defined data type, it must be defined before it can be used. Classes are defined similarly to structs, except we use the `class` keyword. For example, here is a definition for a simple employee class:

```cpp
class Employee
{
    int m_id {};
    int m_age {};
    double m_wage {};
};
```
# Member Functions (structs)

Say if we want to print the employee info, we could use an outer function, but **structs** allow us to use a function that is inside the class itself.

Example:

```cpp
struct Date
{
    int year {};
    int month {};
    int day {};

    void print()
    {
        std::cout << year << '/' << month << '/' << day;
    }

    void print(std::string_view prefix)
    {
        std::cout << prefix << year << '/' << month << '/' << day;
    }
};
```

# Constructors

Same as Java (NOTE AT BOTTOM).

**INITIALIZE LIKE THIS**:

```cpp
Foo(int x, int y)
    : m_x { x }
    , m_y { y }
{
}
```
**NEVER THIS**:

```cpp
Foo(int x, int y) {
    m_x = x;
    m_y = y
}
```
