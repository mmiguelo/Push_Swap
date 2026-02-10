<a id="readme-top"></a>

<div align="center">

![# PUSH_SWAP](https://github.com/mmiguelo/42-project-badges/blob/main/covers/cover-push_swap.png)

# 🔄 push_swap

**Sort a stack of integers using the fewest operations possible | 42 School Project**

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norm-OK-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)

---

*Given a set of integers, sort them using two stacks and a limited set of operations — in the fewest moves possible.*

</div>

---

## 📖 Table of Contents

- [About](#-about)
- [The Rules](#-the-rules)
- [Sorting Algorithms](#-sorting-algorithms)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#-usage)
- [Performance](#-performance)
- [Project Structure](#-project-structure)
- [Author](#-author)

---

## 🧠 About

**push_swap** is an algorithmic project from the 42 curriculum that challenges you to sort data on a stack using a restricted set of instructions, with the lowest possible number of operations.

You are given two stacks — **Stack A** (initially containing all numbers) and **Stack B** (initially empty) — and must use only the allowed operations to sort Stack A in ascending order.

This project strengthens core concepts in:

- **Algorithm design & optimization**
- **Sorting theory** and complexity analysis
- **Doubly linked list** manipulation
- **Bitwise operations** (radix sort)
- Input parsing and robust error handling

---

## 📜 The Rules

You have two stacks and the following operations:

<div align="center">

| Operation | Description |
|:---------:|:------------|
| `sa` | **Swap A** — Swap the first two elements of Stack A |
| `sb` | **Swap B** — Swap the first two elements of Stack B |
| `ss` | **Swap Both** — Execute `sa` and `sb` simultaneously |
| `pa` | **Push A** — Push the top element of Stack B onto Stack A |
| `pb` | **Push B** — Push the top element of Stack A onto Stack B |
| `ra` | **Rotate A** — Shift all elements of Stack A up by one (first becomes last) |
| `rb` | **Rotate B** — Shift all elements of Stack B up by one |
| `rr` | **Rotate Both** — Execute `ra` and `rb` simultaneously |
| `rra` | **Reverse Rotate A** — Shift all elements of Stack A down by one (last becomes first) |
| `rrb` | **Reverse Rotate B** — Shift all elements of Stack B down by one |
| `rrr` | **Reverse Rotate Both** — Execute `rra` and `rrb` simultaneously |

</div>

---

## ⚙️ Sorting Algorithms

The program chooses the best strategy based on the input size:

### Small Stacks (≤ 5 elements)

| Size | Strategy |
|:----:|:---------|
| **2** | Single `sa` if needed |
| **3** | Hardcoded comparisons — handles all 6 permutations optimally |
| **4** | Push smallest to B → sort 3 → push back |
| **5** | Push two smallest to B → sort 3 → push back |

### Large Stacks (> 5 elements) — Radix Sort (Bitwise)

For larger inputs, a **binary radix sort** is used:

1. Each number is **indexed** (ranked by value) to normalize the data
2. The algorithm iterates through each **bit position** (LSB → MSB)
3. For each bit: if the bit is `1` → `ra` (keep in A), if `0` → `pb` (move to B)
4. After processing each bit, all elements in B are pushed back to A
5. Repeat until all bits have been processed

> This approach guarantees **O(n log n)** operations, well within project benchmarks.

---

## 🚀 Getting Started

### Prerequisites

- **GCC** or **CC** compiler
- **Make**

### Installation

```bash
# Clone the repository
git clone https://github.com/mmiguelo/Push_Swap.git
cd Push_Swap

# Build the project
make
```

---

## 🎯 Usage

```bash
./push_swap <numbers>
```

The program outputs the list of operations needed to sort the numbers.

**Examples:**

```bash
# Pass numbers as separate arguments
./push_swap 4 67 3 87 23

# Pass numbers as a single string
./push_swap "4 67 3 87 23"

# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l

# Verify the result with the checker
./push_swap 4 67 3 87 23 | ./checker_OS 4 67 3 87 23
```

### Error Handling

The program prints `Error` to stderr and exits in these cases:

```
❌ Non-numeric arguments
❌ Numbers exceeding INT range (-2147483648 to 2147483647)
❌ Duplicate numbers
❌ Empty input
```

If the input is already sorted or only one number is given, the program outputs nothing.

---

## 📊 Performance

<div align="center">

| Input Size | Target (42 benchmarks) | Approximate Result |
|:----------:|:----------------------:|:------------------:|
| **3** | ≤ 3 ops | ✅ 2–3 |
| **5** | ≤ 12 ops | ✅ ≤ 12 |
| **100** | ≤ 700 ops | ✅ ~ 600 |
| **500** | ≤ 5500 ops | ✅ ~ 5000 |

</div>

> 💡 You can benchmark using:
> ```bash
> # Generate 100 random numbers and count operations
> ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
>
> # Verify correctness
> ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker_OS $ARG
> ```

---

## 📁 Project Structure

```
Push_Swap/
├── 📄 Makefile
├── 📖 README.md
├── 🔍 checker_OS              # Official checker binary (42)
├── main.c                     # Entry point, parsing & dispatch
├── commands/
│   ├── swap.c                 # sa, sb, ss
│   ├── push.c                 # pa, pb
│   ├── rotate.c               # ra, rb, rr
│   ├── reverse_rotate.c       # rra, rrb, rrr
│   └── sort.c                 # Sorting algorithms (3/4/5/radix)
├── includes/
│   └── push_swap.h            # Header with structs & prototypes
├── my_libft/                  # Custom C library (libft + ft_printf + GNL)
└── utils/
    ├── parsing.c              # Input validation (duplicates, sorted check)
    ├── parsing_utils.c        # Numeric checks & error handling
    ├── stacks.c               # Stack creation & linked list ops
    └── stack_utils.c          # Min/max helpers & indexing
```

---

## 🛠️ Makefile Targets

| Command | Description |
|:--------|:------------|
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | Full recompile |

---

## 🔍 Visual Example

```
Input:  5 3 1 4 2

Stack A: [5, 3, 1, 4, 2]    Stack B: []

After sorting operations...

Stack A: [1, 2, 3, 4, 5]    Stack B: []

Operations: pb, pb, sa, ra, pa, pa, ra
```

---

## 👤 Author

**mmiguelo** — 42 Student

[![GitHub](https://img.shields.io/badge/GitHub-mmiguelo-181717?style=for-the-badge&logo=github)](https://github.com/mmiguelo)

---

<div align="center">

*Made with ❤️ at 42*

<p>(<a href="#readme-top">⬆️ back to top</a>)</p>

</div>