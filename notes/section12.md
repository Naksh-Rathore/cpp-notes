# Compound Types

In C++, there are two types of data types, **primitive** and **compound** (also called reference or non-primitive).

Primitive data types are simple types like `int`, `char`, `long`, `short`, and more. They get stored perfectly normal on the stack.

On the other hand, compound data types like `std::string`, `std::array`, `std::vector`, `std::deque`, classes, structs, unions, and more are complex types which don't get stored normally, their memory address gets stored on the stack and they are actually accessed elsewhere (maybe on offsets or on the heap).

# Lvalues and Rvalues

## Lvalues

An lvalue is an expression that evaluates to an identifiable object or function.

An entity (such as an object or function) that has an identity can be differentiated from other similar entities (typically by comparing the addresses of the entity).

Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a lifetime longer than a single expression or statement.

Example: 

```cpp
int main()
{
    int x { 5 };
    int y { x }; // x is an lvalue expression

    return 0;
}
```

In this program, the expression `x` is an lvalue since it evaluates to variable `x` which has an identifier.

# Rvalues

An rvalue is an expression that is not an lvalue. Rvalue expressions evaluate to a a value.

Example:

```cpp
int return5()
{
    return 5;
}

int main()
{
    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

    return 0;
}
```

## Key Insight

**Lvalue expressions evaluate to an identifiable object.**
**Rvalue expressions evaluate to a value.**
