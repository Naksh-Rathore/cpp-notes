# Code coverage

Code coverage is the process of testing functions or classes by
giving them inputs that make the entire source code execute.

Example:

```cpp
bool isEven(int num) {
    if (num % 2 == 0) return true;
    return false;
}
```
To ensure that this code doesn't have any logic errors, we need to
make sure that **all branches run**.

Test #1 for branch #1:

```cpp
isEven(1); // Odd
```

Test #2 for branch #2:

```cpp
isEven(2); // Even
```

If one of these tests result in the wrong answer, then we can pinpoint the root error faster and keep our code good.

Always aim for **100% code coverage**.

# Handling & Detecting Errors

We covered many types of common C++ semantic errors that new C++ programmers run into with the language. If an error is the result of a misused language feature or logic error, the error can simply be corrected.

But most errors in a program don’t occur as the result of inadvertently misusing language features but rather, most errors occur due to faulty assumptions made by the programmer and/or a lack of proper error detection/handling.

Many programming write code and then only test the positive path, which is the path where all cases result in no errors. However, you must always test for errors by including things that you may have overlooked.

For example, if a king was building a wall around his castle, he might have checked it by trying to break it, and if it passed the tests, the wall was considered impenetrable. Although, the king overlooked the little gap at the back which was only allowed for the soldiers to pass through. The next week he got raided by the enemy kingdom.

This is why we need to find issues **before they become problems**.

## Handling errors in functions

Function can fail for a large number of reasons. When this happens, you can use some tactics to fix it. 

Here are 4 general strategies that can be used:

* Handle the error within the function
* Pass the error back to the caller to deal with
* Halt the program
* Throw an exception
