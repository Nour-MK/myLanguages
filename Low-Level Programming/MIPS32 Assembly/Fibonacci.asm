# Compute several Fibonacci numbers and put in array, then print
.data
fibs:.word   0 : 19         # "array" of words to contain fib values
size: .word  19             # size of "array" (agrees with array declaration)
prompt: .asciiz "How many Fibonacci numbers to generate? (2 <= x <= 19)"
.text
      la   $s0, fibs        # load address of array
      la   $s5, size        # load address of size variable
      lw   $s5, 0($s5)      # load array size

# Optional: user inputs the number of Fibonacci numbers to generate
#pr:   la   $a0, prompt      # load address of prompt for syscall
#      li   $v0, 4           # specify Print String service
#      syscall               # print the prompt string
#      li   $v0, ?????Replace_this_dummy_with_the_correct_numeric_value???????           # specify Read Integer service
#      syscall               # Read the number. After this instruction, the number read is in $v0.
#      bgt  $v0, $s5, pr     # Check boundary on user input -- if invalid, restart
#      blt  $v0, $zero, pr   # Check boundary on user input -- if invalid, restart
#      add  $s5, $v0, $zero  # transfer the number to the desired register
      
      li   $s2, 1           # 1 is the known value of first and second Fib. number
      sw   $s2, 0($s0)      # F[0] = 1
      sw   $s2, 4($s0)      # F[1] = F[0] = 1
      addi $s1, $s5, -2     # Counter for loop, will execute (size-2) times
      
      # Loop to compute each Fibonacci number using the previous two Fib. numbers.
loop: lw   $s3, 0($s0)      # Get value from array F[n-2]
      lw   $s4, 4($s0)      # Get value from array F[n-1]
      add  $s2, $s3, $s4    # F[n] = F[n-1] + F[n-2]
      sw   $s2, 8($s0)      # Store newly computed F[n] in array
      addi $s0, $s0, 4      # increment address to now-known Fib. number storage
      addi $s1, $s1, -1     # decrement loop counter
      bgtz $s1, loop        # repeat while not finished
      
      # Fibonacci numbers are computed and stored in array. Print them.
      la   $a0, fibs        # first argument for print (array)
      add  $a1, $zero, $s5  # second argument for print (size)
      jal  print            # call print routine. 

      # The program is finished. Exit.
      li   $v0, 10          # system call for exit
      syscall               # Exit!
		
###############################################################
# Subroutine to print the numbers on one line.
      .data
space:.asciiz  " "          # space to insert between numbers
head: .asciiz  "The Fibonacci numbers are:\n"
      .text
print:add  $t0, $zero, $a0  # starting address of array of data to be printed
      add  $t1, $zero, $a1  # initialize loop counter to array size
      la   $a0, head        # load address of the print heading string
      li   $v0, 4           # specify Print String service
      syscall               # print the heading string
      
out:  lw   $a0, 0($t0)      # load the integer to be printed (the current Fib. number)
      li   $v0, 1           # specify Print Integer service
      syscall               # print fibonacci number
      
      la   $a0, space       # load address of spacer for syscall
      li   $v0, 4           # specify Print String service
      syscall               # print the spacer string
      
      addi $t0, $t0, 4      # increment address of data to be printed
      addi $t1, $t1, -1     # decrement loop counter
      bgtz $t1, out         # repeat while not finished
      
      jr   $ra              # return from subroutine
# End of subroutine to print the numbers on one line
###############################################################

# This MIPS assembly program calculates a series of Fibonacci numbers and stores them in an array. 
# Initially, the code loads the address of the array fibs and the size of the array, which is set to 
# hold up to 19 Fibonacci numbers. Optionally, the user can input how many Fibonacci numbers they wish 
# to generate (from 2 to 19), although this section is commented out. The program starts by assigning 
# the first two Fibonacci numbers, both equal to 1, to the first two positions in the array. It then 
# enters a loop where it calculates each subsequent Fibonacci number by summing the previous two, storing 
# the result in the array, and updating the pointer to the next position. After generating the requested 
# Fibonacci numbers, the program enters a subroutine that prints the numbers. It begins by printing a 
# heading ("The Fibonacci numbers are:") and then prints each number in the array, separated by spaces. 
# Finally, the program terminates with an exit system call once all the numbers have been printed.







