=== Push_Swap Visualizer ===

This visualizer shows how push_swap operations move values between stack A and stack B.


- Usage:

Pipe the output of push_swap into the visualizer:

    $> ARG="4 67 3 87 23"; ./push_swap $ARG | ./visualizer $ARG


- Delay:

You can adjust the animation speed using:

    --delay <seconds>

Example:

    $> ./push_swap 4 1 9 3 | ./visualizer 4 1 9 3 --delay 0.05

(Default delay = 0.3 seconds)


- Examples:

Random 30 numbers:

    $> ARG=$(shuf -i 0-9999 -n 30 | tr '\n' ' ')
    $> ./push_swap $ARG | ./visualizer $ARG

Random 30 numbers (faster delay):

    $> ARG=$(shuf -i 0-9999 -n 30 | tr '\n' ' ')
    $> ./push_swap $ARG | ./visualizer $ARG --delay 0.05

Random 500 numbers:

    $> ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
    $> ./push_swap $ARG | ./visualizer $ARG


- Notes:

- Requires push_swap output on stdin
- Numbers must be passed again to the visualizer on argv
- The displayed score is based on the official 42 evaluation sheet
- Press Ctrl+C to quit
