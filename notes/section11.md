# Templates

A template is a way to define multiple datatypes as a parameter or return type.

Here is an example:

```cpp
template <typename T>
T max(T x, T y) {
    return (x > y ? x : y);
}
```

This uses a template datatype `T` to return the max
of two arguments.

Use this to add more functionality while keeping it concise. 
