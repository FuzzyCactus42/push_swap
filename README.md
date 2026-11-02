*This activity has been created as part of the 42 curriculum by hhailat, sallawne.*

# push_swap

## Description

A C program that sorts unique integers using two stacks, A and B. It prints the instructions needed to leave A sorted from smallest to largest, with B empty.

It supports Simple, Medium, Complex, and Adaptive strategies, plus optional benchmark statistics.

## Instructions

You need Make, a C compiler, and a Unix-like system. No external libraries are required.

```sh
make
./push_swap 3 2 1
./push_swap "8 3 -2 7 0 4"
./push_swap --medium 8 3 -2 7 0 4
```

The program prints operations such as `pb`, `pa`, and `ra`, one per line.

| Command | Purpose |
| --- | --- |
| `make` | Build the program. |
| `make clean` | Remove object files. |
| `make fclean` | Remove objects and executable. |
| `make re` | Rebuild everything. |

### Options

Put options before the numbers. Use one strategy option and, optionally, `--bench`.

| Option | Strategy |
| --- | --- |
| `--simple` | Minimum extraction. |
| `--medium` | Chunk sorting. |
| `--complex` | Binary radix sort. |
| `--adaptive` | Select by disorder; the default. |
| `--bench` | Show disorder, strategy, and operation counts on standard error. |

Numbers must be unique integers between `-2147483648` and `2147483647`. Negative numbers and quoted lists separated by spaces are accepted. Invalid numbers, duplicates, empty arguments, and invalid or repeated options produce `Error` on standard error and a nonzero exit status.

Sorted input produces no operations. Running without arguments produces no output.

**Current limitation:** inputs of five or fewer numbers always use Simple. This overrides explicit strategy flags and conflicts with the subject's requirement that selectors work at every size.

### Benchmark and checker

```sh
# Save instructions and statistics separately
./push_swap --bench 3 2 1 > operations.txt 2> benchmark.txt

# Check that the instructions sort the input
./push_swap 3 2 1 | ./checker/checker_os 3 2 1
# Expected: OK
```

The included checkers are Linux x86-64 binaries. `checker/ubuntu_checker` is another available option.

## Algorithms

Complexity below counts **printed stack operations**, as required by the subject. Here, `n` is the number of values. All strategies share `O(n)` storage for stack nodes.

### Simple — `O(n²)`

Find the smallest value in A, rotate it to the top using the shorter direction, and push it to B. Repeat, then push everything back to A.

This is an easy baseline: successive minima build B in descending order, so returning them sorts A. Each extraction needs at most half the remaining stack's size in rotations. Summing these costs gives `O(n²)` operations, including the `2n` pushes.

### Medium — `O(n√n)`

Replace values with ranks from `0` to `n - 1`. Push ranks to B in groups of `k = floor(sqrt(n))`, then return the largest remaining rank to A each time.

Chunks reduce repeated scans while keeping each rank group together. Distribution costs `O(n²/k)`. During recovery, the highest remaining group stays together in circular stack order, so its next maximum needs at most `k` rotations. Recovery costs `O(nk)`. Choosing `k` near `sqrt(n)` balances the two costs, giving `O(n√n)` operations.

### Complex — `O(n log n)`

Sort the ranks one binary bit at a time, starting with the lowest bit. Push zero-bit ranks to B, rotate one-bit ranks in A, then push B back.

Each pass preserves the order within both groups, so sorting successive bits eventually sorts all ranks. There are `ceil(log2(n))` passes, each using at most `2n` operations. This gives a predictable `O(n log n)` bound.

### Adaptive

Disorder is the fraction of pairs where a larger value appears before a smaller one:

```text
disorder = out-of-order pairs / (n * (n - 1) / 2)
```

For fewer than two values, disorder is zero.

| Disorder | Action |
| --- | --- |
| 0% | No sorting. |
| Above 0% and below 20% | Simple — `O(n²)` |
| 20% to below 50% | Medium — `O(n√n)` |
| 50% and above | Complex — `O(n log n)` |

The 20% and 50% thresholds follow the subject's required regimes. Adaptive adds no stack operations, so it inherits the selected method's bound. The small-input override described above takes priority.

Input checks, disorder calculation, and ranking use quadratic comparisons. Reverse rotation also traverses the linked list. These affect execution time separately from the printed-operation count.

## Contributors

Contributions overlap; this summary follows the source headers and Git history.

| Learner | Main contributions |
| --- | --- |
| `hhailat` | Input and flag parsing, validation, program flow, chunk sorting, Makefile, and integration. |
| `sallawne` | Stack utilities and operations, initial Simple and radix algorithms, ranking, disorder, benchmarks, and output helpers. |

## Resources

- **42 Push_swap subject:** project rules, disorder thresholds, and evaluation requirements.
- [MIT Introduction to Algorithms — lecture notes](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/pages/lecture-notes/): data structures, sorting, and complexity.
- **Introduction to Algorithms, by Cormen, Leiserson, Rivest, and Stein:** sorting and algorithm analysis.
- [42 Norminette](https://github.com/42School/norminette): coding-style checker and documentation.

### AI use

AI helped improve code for Norminette and test edge cases, including invalid input, integer limits, duplicates, and sorting. AI also helped write and simplify this README and check it against the subject.
