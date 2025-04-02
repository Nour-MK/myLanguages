# This program uses a while loop and a for loop to decrement a counter 'i' and print the result.

i = 10  # Initialize i to 10.

# Run the while loop as long as i is greater than 0
while i > 0:
    # Inside the while loop, run a for loop 3 times
    for j in range(3):  # The for loop runs 3 times
        i -= 1  # Decrement i by 1 each time the for loop runs.
    
    # After the inner for loop, print the current value of i
    print(i)  # This prints the value of i after each iteration of the while loop.

# Execution steps:
# First, i starts at 10. The inner for loop runs 3 times, so i becomes 7.
# It then prints 7.
# In the second iteration, i is 7, the inner for loop runs 3 times, i becomes 4.
# It then prints 4.
# In the third iteration, i is 4, the inner for loop runs 3 times, i becomes 1.
# It then prints 1.
# In the fourth iteration, i is 1, the inner for loop runs 3 times, i becomes -2.
# It then prints -2.

# Output will be:
# 7
# 4
# 1
# -2
