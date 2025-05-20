# 🛠️ push_swap

> A sorting algorithm project designed to sort data on a stack with a limited set of operations. Part of the 1337 curriculum.

## 📌 Description

The **push_swap** project requires implementing a program that sorts integers using two stacks (stack A and stack B) and a limited set of operations. The goal is to sort the stack with the least number of moves possible.

## ⚙️ Program Overview

- Input: a list of integers (from command line arguments).
- Output: sequence of operations to sort the stack.
- Allowed operations:
  - `sa` (swap a): swap the first two elements at the top of stack A.
  - `sb` (swap b): swap the first two elements at the top of stack B.
  - `ss`: `sa` and `sb` at the same time.
  - `pa` (push a): take the first element at the top of B and put it at the top of A.
  - `pb` (push b): take the first element at the top of A and put it at the top of B.
  - `ra` (rotate a): shift up all elements of stack A by 1.
  - `rb` (rotate b): shift up all elements of stack B by 1.
  - `rr`: `ra` and `rb` at the same time.
  - `rra` (reverse rotate a): shift down all elements of stack A by 1.
  - `rrb` (reverse rotate b): shift down all elements of stack B by 1.
  - `rrr`: `rra` and `rrb` at the same time.

## 📁 File Structure

```
push_swap/
├── push_swap.c
├── operations.c
├── utils.c
├── push_swap.h
├── Makefile
├── README.md
└── main.c            # Optional testing file
```

## 🧪 Usage Example

```bash
$ ./push_swap 3 2 1 6 5
pb
pb
sa
pa
pa
```

## 🔧 Compilation

```bash
make
gcc -Wall -Wextra -Werror push_swap.c operations.c utils.c main.c
./push_swap 3 2 1 6 5
```

## ✅ Features

- Efficient sorting using minimal operations.
- Handles errors and invalid inputs.
- Supports large input sizes.
- Norm compliant (1337).

## 👨‍💻 Author

- GitHub: [OB4413](https://github.com/OB4413)
