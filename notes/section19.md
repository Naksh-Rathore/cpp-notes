# New & Delete

Sometimes, we may want to use a string to hold someone’s name, but we do not know how long their name is until they enter it. Or we may want to read in a number of records from disk, but we don’t know in advance how many records there are. Or we may be creating a game, with a variable number of monsters (that changes over time as some monsters die and new ones are spawned) trying to kill the player.

If we have to declare the size of everything at compile time, the best we can do is try to make a guess the maximum size of variables we’ll need and hope that’s enough:

```cpp
char name[25]; // let's hope their name is less than 25 chars!
Record record[500]; // let's hope there are less than 500 records!
Monster monster[40]; // 40 monsters maximum
Polygon rendering[30000]; // this 3d rendering better not have more than 30,000 polygons!
```

This is a poor solution for at least four reasons:

First, it leads to wasted memory if the variables aren’t actually used. For example, if we allocate 25 chars for every name, but names on average are only 12 chars long, we’re using over twice what we really need. Or consider the rendering array above: if a rendering only uses 10,000 polygons, we have 20,000 Polygons worth of memory not being used!

Second, how do we tell which bits of memory are actually used? For strings, it’s easy: a string that starts with a \0 is clearly not being used. But what about `monster[24]`? Is it alive or dead right now? Has it even been initialized in the first place? That necessitates having some way to tell the status of each monster, which adds complexity and can use up additional memory.

Third, most normal variables (including fixed arrays) are allocated in a portion of memory called the stack. The amount of stack memory for a program is generally quite small -- many C/C++ editors defaults the stack size to 1MB. If you exceed this number, stack overflow will result, and the operating system will probably close down the program.

Fortunately, these problems are easily addressed via dynamic memory allocation. Dynamic memory allocation is a way for running programs to request memory from the operating system when needed. This memory does not come from the program’s limited stack memory -- instead, it is allocated from a much larger pool of memory managed by the operating system called the heap. On modern machines, the heap can be gigabytes in size.

## Allocating with `new`

```cpp
int* ptr{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later

*ptr = 7; // assign value of 7 to allocated memory
```
# Deleting Blocks

When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse. For single variables, this is done via the scalar (non-array) form of the `delete` operator:

```cpp
delete ptr;
ptr = nullptr; // so it isn't a garbage value
```
# Deleting with destructors

You can use the `delete` keyword on dynamically allocated objects to invoke the destructor:

```cpp
#include <iostream>

class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int main()
{
    // Allocate a Simple on the stack
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // Allocate a Simple dynamically
    Simple* pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pSimple;

    return 0;
} // simple goes out of scope here
```

# Void Pointers

The void pointer, also known as the generic pointer, is a special type of pointer that can be pointed at objects of any data type! A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type:

```cpp
int nValue {};
float fValue {};

struct Something
{
    int n;
    float f;
};

Something sValue {};

void* ptr {};
ptr = &nValue; // valid
ptr = &fValue; // valid
ptr = &sValue; // valid
```

However, because the void pointer does not know what type of object it is pointing to, dereferencing a void pointer is illegal. Instead, the void pointer must first be cast to another pointer type before the dereference can be performed.

```cpp
int value{ 5 };
void* voidPtr{ &value };

// std::cout << *voidPtr << '\n'; // illegal: dereference of void pointer

int* intPtr{ static_cast<int*>(voidPtr) }; // however, if we cast our void pointer to an int pointer...

std::cout << *intPtr << '\n'; // then we can dereference the result
```

# Intro to lambdas

Lambdas are anonymouse functions that can be easily embedded into code.

Syntax:

```cpp
[capture] (paramters) { code };
```
For example:

```cpp
int main() {
  auto message = []() {
    std::cout << "Hello World!\n";
  };

  message();
  return 0;
}
```

Passing parameters:

```cpp
#include <iostream>
using namespace std;

int main() {
  auto add = [](int a, int b) {
    return a + b;
  };

  std::cout << add(3, 4);
  return 0;
}
```

## Capture clause

You can use the `[ ]` brackets to give a lambda access to variables outside of it.
This is called the capture clause.

In this example, the lambda captures the variable `x` by value (a copy):

```cpp
int main() {
  int x = 10;
  auto show = [x]() {
    std::cout << x;
  };

  show();
  return 0;
}
```

Output:

```
10
```
