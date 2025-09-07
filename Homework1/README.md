# HW1 - Multiset

This task implements a memory-efficient MultiSet data structure that stores numbers in a range `[0, n]`. The MultiSet is optimized for memory by using a fixed number of bits to store the count of each number.

## Features

The `MultiSet` class supports the following functionalities:

- **Initialization**:
  - `n`: Maximum number in the set.
  - `k`: Number of bits to store the count of each number (1 ≤ k ≤ 8).  
    - Each number can occur at most `2^k - 1` times.


## Memory Efficiency

- Each number uses exactly `k` bits to store its count.
- This ensures optimal memory usage while allowing multiple occurrences.

## Operations Supported

- **Addition:** Add numbers to the MultiSet.
- **Count:** Check the frequency of a number.
- **Intersection:** Returns a MultiSet containing elements common to both sets (minimum counts).
- **Difference:** Returns a MultiSet subtracting counts of another set.
- **Complement:** Returns a MultiSet with counts inverted with respect to `2^k - 1`.
- **Serialization:** Save/load the MultiSet in binary format.
- **Display Memory:** Visual representation of how data is stored in memory.

