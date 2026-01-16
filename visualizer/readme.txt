## 🎥 Push_Swap Visualizer

This visualizer shows how `push_swap` operations move values between Stack A and Stack B.

---

### 📌 Usage

Pipe the output of `push_swap` into the visualizer:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./visualizer $ARG
```

---

### ⏱ Delay

You can adjust the animation speed using:

```
--delay <seconds>
```

Example:

```bash
./push_swap 4 1 9 3 | ./visualizer 4 1 9 3 --delay 0.05
```

(Default delay = `0.3` seconds)

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
./push_swap $ARG | ./visualizer $ARG --delay 0.05
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
- score shown corresponds to 42 push_swap evaluation rules
- exit with `Ctrl + C`
- if you get `Error` or `0 operations`, run `make fclean && make` and retry
- note: `0 operations` may also mean the input was already sorted