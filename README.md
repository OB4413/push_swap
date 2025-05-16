# 🧮 push_swap

> A sorting algorithm visualized through a stack-based puzzle. Developed as part of the 1337 curriculum.

## 📌 Description

The **push_swap** project requires sorting a stack of integers using a limited set of instructions and two stacks: `A` and `B`. The goal is to produce the **fewest number of operations possible** to complete the sorting.

## 🎯 Objective

Sort integers with the following constraints:
- Only use predefined operations (`sa`, `pb`, `ra`, etc.)
- No built-in sorting functions
- Optimize for the smallest number of moves

## 🛠️ Allowed Instructions

| Operation | Description                  |
|----------:|------------------------------|
| `sa`      | swap top two of stack A      |
| `sb`      | swap top two of stack B      |
| `ss`      | `sa` and `sb` at the same time |
| `pa`      | push top of B onto A         |
| `pb`      | push top of A onto B         |
| `ra`      | rotate A (top to bottom)     |
| `rb`      | rotate B                     |
| `rr`      | `ra` and `rb` simultaneously |
| `rra`     | reverse rotate A             |
| `rrb`     | reverse rotate B             |
| `rrr`     | `rra` and `rrb` simultaneously |

## ⚙️ How It Works

- Parse integers from the command line
- Validate input and check for duplicates
- Choose algorithm based on input size:
  - Simple sort for 3–5 numbers
  - Radix sort or other for larger input
- Print optimized list of operations to stdout

## 🧪 Example

```bash
$ ./push_swap 4 2 3 1
pb
pb
sa
pa
pa

push_swap/
├── src/               # Sorting and operation logic
├── includes/          # Header files
├── libft/             # Custom C library (reused from Libft)
├── Makefile
├── push_swap.c
└── README.md
