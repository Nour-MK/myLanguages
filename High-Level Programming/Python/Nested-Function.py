# This program demonstrates the use of nested functions in Python.
# The outer function 'basefunc' takes one parameter 'first' and defines an inner function 'innerfunc' within it.
# The inner function takes a second parameter 'second' and returns the result of raising 'first' to the power of 'second'.

def basefunc(first):
    # Define the inner function 'innerfunc', which takes a parameter 'second'.
    def innerfunc(second):
        # Return the result of raising 'first' to the power of 'second'.
        return first ** second
    
    # Return the inner function 'innerfunc'. Notice that 'innerfunc' has access to 'first' from the outer function.
    return innerfunc

# Now, let's use the basefunc to create a function that calculates powers of 2.
power_of_2 = basefunc(2)  # Call basefunc with first = 2, and it returns the innerfunc function.
# Now 'power_of_2' is a function that takes one argument and returns 2 raised to the power of that argument.

# Let's test it with some values:
print(power_of_2(3))  # This calls innerfunc with second = 3. Result: 2 ** 3 = 8.
print(power_of_2(4))  # This calls innerfunc with second = 4. Result: 2 ** 4 = 16.

# The basefunc function allows us to "freeze" the value of 'first' and create custom functions for different bases.
# For example, if we call basefunc(3), we will get a function that calculates powers of 3.

power_of_3 = basefunc(3)  # Create a new function for powers of 3.
print(power_of_3(2))  # This calls innerfunc with second = 2. Result: 3 ** 2 = 9.

# Output will be:
# 8
# 16
# 9
