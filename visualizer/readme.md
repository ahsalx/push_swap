## 🎥 Push_Swap Visualizer

This visualizer shows how `push_swap` operations move values between Stack A and Stack B in real-time with animation, colors, and evaluation.

---

### 📌 Usage

Pipe the output of `push_swap` into the visualizer:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./visualizer $ARG
```

---

### ⏱ Delay

You can adjust the animation speed using:

```bash
-d <seconds>
```

Example:

```bash
./push_swap 4 1 9 3 | ./visualizer -d 0.05
```

(Default delay = `0.12` seconds)

---

### 🎲 Examples

Random 30 numbers:

```bash
ARG=$(shuf -i 0-9999 -n 30 | tr '\n' ' ')
./push_swap $ARG | ./visualizer $ARG
```

Random 30 numbers (faster delay):

```bash
ARG=$(shuf -i 0-9999 -n 30 | tr '\n' ' ')
./push_swap $ARG | ./visualizer -d 0.05 $ARG
```

Random 500 numbers:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./visualizer $ARG
```

---

### 📝 Notes

- expects `push_swap` operations on `stdin`
- stack values must be passed again on `argv`
- evaluation uses 42 push_swap scoring rules (100 & 500 numbers)
- exit with `Ctrl + C`
- `Error` means invalid instruction
- `0 operations` may also mean the input was already sorted
