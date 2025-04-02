# Create a program that generates a random number between 1 and 10 and asks the user to guess the number. The program should give the user feedback on whether their guess is too high or too low and continue prompting them to guess until they correctly guess the number.

import random # a built-in module that provides functions for generating random numbers and performing random operations

def guess_the_number():
    target_number = random.randint(1, 10)
    # random.randint(a, b): Generates a random integer between a (inclusive) and b (inclusive).
    guessed = False #flag
    
    while not guessed:
        user_guess = int(input("Guess a number between 1 and 10: "))
        # The input() function is used to take user input from the keyboard.
        # The int() function is used to convert a value into an integer data type. Since the input() function returns a string (the user's typed input), we use int() to convert that string into an integer.
        
        if user_guess < target_number:
            print("Too low! Try again.")
        elif user_guess > target_number:
            print("Too high! Try again.")
        else:
            print(f"Congratulations! You guessed the number {target_number} correctly!")
            guessed = True

guess_the_number() #calling the function to start the game