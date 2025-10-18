# Compound Statements

A compound statement (also called a block) is a group of zero or more
statements that is treated by the compiler if it was a single statement.

A block begins with `{` and ends with `}`, with the statements to be executed being placed in between. No semicolon is needed at the end of
a block. In C++ indentation doesn't matter with blocks, but be sure
to indent if you are in a block since it makes it easier to read.

An example of a block is a function body:

```cpp
int add(int x, int y)
{ // start block
    return x + y;
} // end block (no semicolon)

int main()
{ // start block

    // multiple statements
    int value {}; // this is initialization, not a block
    add(3, 4);

    return 0;

} // end block (no semicolon)
```

Blocks can also be nested inside other blocks (not functions though).

Here is an example demonstrating this:

```cpp
int add(int x, int y)
{ // block
    return x + y;
} // end block

int main()
{ // outer block

    // multiple statements
    int value {};

    { // inner/nested block
        add(3, 4);
    } // end inner/nested block

    return 0;

} // end outer block
```

You can nest blocks inside blocks however many times you want, but
make sure to *never* go beyond 3 nesting levels since it highly decreases readability and changing code is a headache.

If you need to go 3+ levels deep, consider refactoring code to
use helper/sub functions to keep the logic same but more readable.

# User-defined namespaces and the scope resolution operator (::)

C++ allows us to create user-defined namespaces via the `namespace` keyword. Namespaces that you create in your own programs are casually called user-defined namespaces.

Syntax:

```cpp
namespace identifier {
    // content goes here
}
```

User-defined namespaces should have be capitalized to avoid colliding with system namespaces since system namespaces are all lowercase.

Here is an example of a namespace that has functions for exponents:

```cpp
namespace Exponents {
    int square(int num) {
        return (num * num);
    }

    int cube(int num) {
        return (num * num * num);
    }

    int power(int num, int power) {
        int result{};

        for (int i = 1; i <= power; i++)
            result *= i;

        return result;
    }
}
```

We use a function or variable in the namespace by doing `namespaceIdentifier::functionOrVariable`.

