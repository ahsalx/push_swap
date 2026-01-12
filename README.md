## 🧩 Project Description

The **push_swap** project is an algorithmic sorting challenge from the 42 curriculum.  
You are given a set of integer values, two stacks, and a limited instruction set that can manipulate both stacks.  
The goal is to sort the data using the fewest possible operations.

---

## 🛠 Programs

This project consists of **two programs**, both written in **C**:

- **checker**  
  Takes integer arguments and reads instructions from standard input.  
  After executing the instructions, it outputs:
  - `OK` if the integers end up sorted
  - `KO` otherwise

- **push_swap**  
  Takes integer arguments and outputs the smallest possible program (sequence of operations) that sorts them in ascending order using the push_swap instruction set.

---

## 🎯 Goal

Sort all numbers in **ascending order** in stack `A` using stack `B` as an auxiliary workspace.

---

## 🧱 Allowed Operations

sa - swap first two elements of A
sb - swap first two elements of B
ss - sa and sb simultaneously

pa - push top element of B to A
pb - push top element of A to B

ra - rotate A (shift all elements up by 1)
rb - rotate B
rr - ra and rb simultaneously

rra - reverse rotate A (shift all elements down by 1)
rrb - reverse rotate B
rrr - rra and rrb simultaneously


---

## 🧩 Data Structures

Stacks and instructions are implemented using a **linked list** structure.

---

## 🧠 Algorithmic Approach

Different input sizes require different strategies.  
This project uses **three algorithms** depending on the number of integers:

### **1. `sort_three`**
Sorts three values in fewer than 3 moves.  
Simple because only `3 × 2` permutations exist.

---

### **2. `sort_five`**
Sorts five values typically in fewer than 11 moves.  
Best case: **7 moves**.  
Process:
1. Find and push the smallest values to stack `B`
2. Sort the remaining three values in stack `A` using `sort_three`
3. Push smallest values back from `B` → `A` in correct order

---

### **3. `big_sort`**
Used for larger input sizes.  
This approach divides stack `A` into **chunks**:

- ≤ 100 numbers → **5 chunks**
- > 100 numbers → **10 chunks**

Steps:
1. Values are sorted into an array to determine chunk boundaries
2. Chunks are pushed from `A` → `B`, smallest chunks first
3. Once all values are in `B`, the largest elements are pushed back to `A`
4. This continues until `B` is empty and `A` is fully sorted

To optimize pushes back from `B` → `A`, a helper routine determines whether it's shorter to rotate using `rb` or reverse rotate using `rrb` to bring a target element to the top.

---
