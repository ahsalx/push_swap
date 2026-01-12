# Push_Swap

**Push_Swap** is a sorting project from the 42 curriculum focused on designing an efficient, constraint-based sorting algorithm.  
The goal is to sort a list of integers using only a limited set of stack operations while minimizing the total number of moves.

This repository includes diagrams, visual call trees, and a Python visualizer to help understand what happens after each function call.

---

## 🚀 Implementation Overview

- **Language:** C
- **Algorithms:**
  - Radix sort for large inputs
  - Small sort (`sort_small`) for input sizes ≤ 5
- **Stacks Used:**  
  - **A** (initial data)  
  - **B** (auxiliary)

---

## 🧠 Visualizer

A **Python visualizer** was created to show how stack operations transform both stacks during sorting.  
A recorded run will be provided as a **GIF demo** for quick viewing without installing the visualizer.

---

## 🛠 Build

```bash
git clone <repo>
cd push_swap
make
