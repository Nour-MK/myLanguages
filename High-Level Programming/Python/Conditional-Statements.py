# This program demonstrates how the if-elif-else conditional structure works in Python.

# Check if the first condition is True (0 is False, so this block will not run)
if 0: 
    print("A")  # This line is skipped, as the condition is False.
# Check if the second condition is True (1 is True, so this block will run)
elif 1: 
    print("B")  # This line will be executed because 1 is considered True.
# If neither the first nor the second condition is True, the else block will run (this is skipped in this case)
else: 
    print("C")  # This line is skipped because the elif condition was met.

# Output will be:
# B
