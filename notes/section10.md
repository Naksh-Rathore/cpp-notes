# Implicit Type Conversion

In C++, the compiler can automatically change types (type cast) for us when it is needed.

Example:

```cpp
double x;

x = 1; // Implicitly type casts to 1.0
```

Brace initialization prohibits this behavior, so copy initialization is needed to demonstrate this.


# Typedefs

To condense big types, use `typedef` (read end of section).

Syntax:

```cpp
typedef long_type short_name;
```

Example:

```cpp
typedef std::string string; 
```

**Try not to use typedefs since they can pollute the global namespace and make code harder to scale and read unless the pros clearly are better than the cons**.

# Auto

You can use `auto` keyword in C++ instead of a type to let the compiler deduce the type at compile-time. (read end of section)

Example:

```cpp
int x { 5 };
auto y = { 5 }; // Compiler swaps it with int when compiling
```

**Only use auto if the type is easily readable by a human and try not to use it at all unless it has a clear benefit**.