# 182 
a transpiler for C++

## Why?
The goal is to write a small program, that sees this statement `namespace acme;`
and transforms into regular C++ namespace declaration, that includes all declarations in the file:
```cpp
namespace acme {
    /* your declarations here */
}
```
So I've written a small S2S (Source-to-Source) compiler for this kind of task, 
right now it's a more dirty prototype actually, than a good-to-go program.
