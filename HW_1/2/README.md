# HW1 - Modifiable Integer Function

This project implements a Modifiable Integer Function class that allows modifying and operating on 16-bit integer functions. The class supports various modifications, arithmetic and composition operations, and advanced analysis of functions.

### Modifications
- **Set specific output for a given input**: Override the original function result for a specific input value.
- **Disable a point**: Make the function partial by marking certain inputs as undefined. Accessing the function at these points will signal an error or indicate that the output is undefined.

### Operators and Function Manipulations
- **Addition/Subtraction of functions**: Supports element-wise addition and subtraction.
- **Function composition**: Compose two functions (`f(g(x))`). If any function is undefined for an input, the result is undefined.
- **Comparison operators**: Compare functions by their outputs for all possible inputs:
  - Undefined inputs are treated as having the lowest value.
- **Check if functions are parallel**: Determine if the outputs of two functions are proportional across all inputs.
- **Exponentiation operator `^`**: Apply a function repeatedly (`f^k(x) = f(f(...f(x)))`).
- **Inverse function generation**: Generate `f^-1` if the function is invertible.
  - `f^-1(x)` is defined only where `f(x)` is defined.

- **Check injectivity, surjectivity, and bijectivity**.
- **Serialization/Deserialization**: Save/load the function to/from a binary file.
- **Plotting function points**: Draw points of the function on a 20x20 grid for a given `[x1 ... x2]` and `[y1 ... y2]` range.
