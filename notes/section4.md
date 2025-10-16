# Data types

Because all data on a computer is just a sequence of bits, we use a data type (often called a type for short) to tell the compiler how to interpret the contents of memory in some meaningful way. You have already seen one example of a data type: the integer. When we declare a variable as an integer, we are telling the compiler “the piece of memory that this variable uses is going to be interpreted as an integer value”.

When you give an object a value, the compiler and CPU take care of encoding your value into the appropriate sequence of bits for that data type, which are then stored in memory (remember: memory can only store bits). For example, if you assign an integer object the value `65`, that value is converted to the sequence of bits `0100 0001` and stored in the memory assigned to the object.

Conversely, when the object is evaluated to produce a value, that sequence of bits is reconstituted back into the original value. Meaning that `0100 0001` is converted back into the value `65`.

Fortunately, the compiler and CPU do all the hard work here, so you generally don’t need to worry about how values get converted into bit sequences and back.


## Primitive Types

Here are all of the primitive datatypes (basic datatypes) in C++:

* `float`
* `int`
* `double`
* `char`
* `short`
* `bool`
* `long`
* `std::nullptr_t` (C++11)
* `void`

And any combination or specification of these types such as `long int` also work.

## Compound datatypes intro

Compound datatypes are more complex and allow for the creation of user-define datatypes. Mainly used in bigger programs and mroe feature-packed ones. Highly useful when primitives are too basic for you needs.

# Void

Void is the easiest of the data types to explain. Basically, void means **no type**!

Void is our first example of an incomplete type. An incomplete type is a type that has been declared but not yet defined. The compiler knows about the existence of such types, but does not have enough information to determine how much memory to allocate for objects of that type. void is intentionally incomplete since it represents the lack of a type, and thus cannot be defined.

It is used as a return type for functions that don't return anything:

```cpp
void writeValue(int x) // void here means no return value
{
    std::cout << "The value of x is: " << x << '\n';
    // no return statement, because this function doesn't return a value
}
```

It can also be used as a void pointer. More info will be given in other sections.

# Datatype sizes

Datatypes take up a set number of bytes which are usually a power of 2.
Here are some datatypes and their byte sizes:

| Category        | Type           | Typical Size | 64-bit System Size |
|-----------------|----------------|---------------|--------------------|
| Boolean         | bool           | 1 byte        | 1 byte             |
| Character       | char           | 1 byte        | 1 byte             |
|                 | wchar_t        | 1 byte        | 2 or 4 bytes       |
|                 | char8_t        | 1 byte        | 1 byte             |
|                 | char16_t       | 2 bytes       | 2 bytes            |
|                 | char32_t       | 4 bytes       | 4 bytes            |
| Integral        | short          | 2 bytes       | 2 bytes            |
|                 | int            | 2 bytes       | 4 bytes            |
|                 | long           | 4 bytes       | 4 or 8 bytes       |
|                 | long long      | 8 bytes       | 8 bytes            |
| Floating point  | float          | 4 bytes       | 4 bytes            |
|                 | double         | 8 bytes       | 8 bytes            |
|                 | long double    | 8 bytes       | 8, 12, or 16 bytes |
| Pointer         | std::nullptr_t | 4 bytes       | 4 or 8 bytes       |

## sizeof in C++

You can use the `sizeof()` operator to determine the size of your data types and variables. Here is an example:


```cpp
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}
```

Here's the output from that program (bytes may vary):

```
bool:           1 bytes
char:           1 bytes
short:          2 bytes
int:            4 bytes
long:           4 bytes
long long:      8 bytes
float:          4 bytes
double:         8 bytes
long double:    8 bytes
```

Using `sizeof` on an incomplete type like `void` will result in an error/segfault.

# Scientific Notation

To write really big numbers, **scientific notation** is used. It can compact massive numbers into writeable and human readable sizes. Of course the compiler doesn't really care about which is given, but when reading code it does matter. 

Examples:

`123 x 10^5 = 12 300 000`
`6.741 x 10^8 = 674 100 000`

# Casting

Signed integral values can be converted to unsigned integral values, and vice-versa, using a static cast.

If the value being converted can be represented in the destination type, the converted value will remain unchanged (only the type will change). For example:

```cpp
#include <iostream>

int main()
{
    unsigned int u1 { 5 };
    // Convert value of u1 to a signed int
    int s1 { static_cast<int>(u1) };
    std::cout << s1 << '\n'; // prints 5

    int s2 { 5 };
    // Convert value of s2 to an unsigned int
    unsigned int u2 { static_cast<unsigned int>(s2) };
    std::cout << u2 << '\n'; // prints 5

    return 0;
}
```

Output:

```
5
5
```

Since the value 5 is in the range of both a signed int and an unsigned int, the value 5 can be converted to either type without issue.

If the value being converted cannot be represented in the destination type:

* If the destination type is unsigned, the value will be modulo wrapped. 
* If the destination type is signed, the value is implementation-defined prior to C++20, and will be modulo wrapped as of C++20.

Here’s an example of converting two values that are not representable in the destination type (assuming 32-bit integers):

```cpp
#include <iostream>

int main()
{
    int s { -1 };
    std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

    unsigned int u { 4294967295 }; // largest 32-bit unsigned int
    std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20

    return 0;
}
```
Output:

```
4294967295
-1
```

## Casting with `static_cast`:

Syntax:

```cpp
static_cast<end_type>(var_to_cast);
```
