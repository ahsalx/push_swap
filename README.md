# 🚀 push_swap — 42 Project

This repository contains my implementation of the **push_swap** project from 42.

The goal is to sort a list of integers using only two stacks (`a` and `b`) and a limited set of operations, while producing as few moves as possible. The entire project is written in **C**.

To make the project easier to understand, I also created **visual guides** and a **visualizer tool** that show what happens internally during parsing, indexing, and sorting.

---

## 📂 Visual Guides (Overview)

To help readers understand the internal flow of the program, I added:

- function call trees
- step-by-step diagrams
- argument parsing & validation
- error handling logic
- small sort and radix sort stages
- visualizer playback

These visuals act as a small guide for anyone reading the code or learning how push_swap works.

---

## 🧾 Parsing & Initial Setup

Example input:

```bash
./push_swap 1 9 4
```

parse_args:

- validates input
- handles quoted input (ex: `"1 56 89"`)
- converts tokens to numbers (`atol_part1 → atol_part2`)
- allocates nodes
- stores nodes in **Stack A**

<p align="center">
  <img src="https://github.com/ahmedbsalah/push_swap/raw/main/SVG/pares_args.svg" width="900">
</p>

---

## ❗ Error Handling

If validation fails:

- invalid character
- overflow / underflow
- duplicate number
- empty token
- allocation failure

Program calls `error_exit` which frees memory and terminates with `"Error"`.

<p align="center">
  <img src="https://github.com/ahmedbsalah/push_swap/raw/main/SVG/pares_failed.svg" width="900">
</p>

---

## ✔ Already Sorted Case

If stack A is already sorted, program frees memory and exits.

<p align="center">
  <img src="https://github.com/ahmedbsalah/push_swap/raw/main/SVG/is_sroted.svg" width="900">
</p>

---

## 🧮 Indexing Stage

Values are converted into sorted indices `0..n-1` to simplify later sorting.

Example:

```
Input:   4  1  9
Sorted:  1  4  9
Index:   1  0  2
```

<p align="center">
  <img src="https://github.com/ahmedbsalah/push_swap/raw/main/SVG/indexing_the_stack.svg" width="900">
</p>

---

## 🧩 Small Input Strategy (≤ 5 numbers)

Used instead of radix for small stacks:

- `size == 2` → `sa`
- `size == 3` → `sort_three`
- `size == 4` → `push_min_to_b`, `sort_three`, `pa`
- `size == 5` → `push_min_to_b` x2, `sort_three`, `pa` x2

<p align="center">
  <img src="https://github.com/ahmedbsalah/push_swap/raw/main/SVG/sorting.svg" width="900">
</p>

---

## ⚙️ Larger Inputs (Radix Sort)

For large inputs, binary radix sort is used:

1. values converted to indices
2. process bits LSB → MSB
3. bit = `0` → `pb`
4. bit = `1` → `ra`
5. after each pass → `pa` all back
6. repeat until sorted

This provides a complexity of approximately `O(n log n)`.

For visual understanding, see resources below.

---

## 🎥 push_swap Visualizer

The visualizer simulates the operations produced by push_swap and displays how stacks evolve over time.

Features:

- reads push_swap operations
- executes them step-by-step
- shows both stacks
- displays final result
- GIF demo planned

Usage:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./visualizer $ARG
```

---

## 🔧 Building

Compile:

```bash
make
```

Run:

```bash
./push_swap [numbers...]
```

---

## 📚 Resources

Visual explanation tools & references:

- https://vscza.itch.io/push-swap
- https://www.youtube.com/watch?v=mVRHvZF8xtg
- https://www.youtube.com/watch?v=dPwAA7j-8o4
- https://en.wikipedia.org/wiki/Radix_sort
- https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
