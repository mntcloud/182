# 182 
a transpiler for C++

## Why?
The goal is to write a small program, that sees this statement `namespace acme;`
and transforms into a regular C++ namespace declaration, that includes all declarations in the file:
```cpp
namespace acme {
    /* your declarations here */
}
```
So I've written a small S2S (Source-to-Source) compiler for this kind of task, 
right now it's a more dirty prototype actually, than a good-to-go program.

## What do we need to be good-to-go?
- [ ] clangd LSP wrapper for working inside IDEs or editors with IDE's like capabilities
- [ ] Rebuild parser's logic
- [ ] Keep room for the future transpiler features
