# HW_2 - Partial Function

This project implements an abstract base class `PartialFunction` for 32-bit integer functions, along with several concrete subclasses. The class allows handling **partially defined functions**, performing operations like maximum/minimum combination, and constructing functions from binary files.

## Features

The `PartialFunction` class represents functions from 32-bit integers to 32-bit integers with the following mandatory operations:

- **Check if a point is defined**: Determine whether the function is defined for a given input `x`.
- **Evaluate the function**: Calculate the result for a defined input `x`.

### Concrete Subclasses

1. **Partial Function by Criterion**
   - Constructed with a function or callable object that returns a pair:
     - Whether the function is defined for a given `x`.
     - The corresponding result if defined.

2. **Maximum of Partial Functions**
   - Constructed with multiple partial functions.
   - Defined at a point only if all constituent functions are defined there.
   - Returns the maximum value among all functions for a given `x`.

3. **Minimum of Partial Functions**
   - Constructed with multiple partial functions.
   - Defined at a point only if all constituent functions are defined there.
   - Returns the minimum value among all functions for a given `x`.

### Program Modes

1. **Range Evaluation**
   - Reads two integers `a` and `b` from standard input.
   - Outputs the function results for all defined points in the interval `[a, b]`.

2. **Sequential Generation**
   - Generates the next defined point on demand from the user.
