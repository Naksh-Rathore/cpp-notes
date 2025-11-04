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
