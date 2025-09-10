################################################ FUNDAMENTALS ####################################################################################
# Open using MARS software. On MARS, first you must create a file, save it (without saving you cannot assemble), write code, assemble, run all or line by line
# To use the file, uncomment the lines you need to run.

# MIPS arithmetic instructions performs only one operation and must always have exactly 3 variables
# MIPS has 32 registers available.
# All MIPS instructions are 32 bits long.
# Note that subi instruction doesn't exist like it does for the add immediate. (no need for it because i can use addi to subtract by using addi with a second number that is negative)
# NOT instruction doesn't exist in MIPS
# topics: simple arithmetic (add, addi, sub, etc) - arrays (with lw and sw) - if else (bne and labels) - loops () - push (STR reg, [SP, #-4]!) - pop (LDR reg, [SP], #4) - function with passed arguments (label, sp, sw, lw, jr) - compare (slt)

# sub $s1, $s2, $s3 # $s1 = $s2 - $s3
# lw $s1, 20($s2) # load word (4 bytes) from memory to register $s1 = Memory[$s2 + 20]
# sw $s1, 20($s2) # store word (4 bytes) from register to memory Memory[$s2 + 20] = $s1
# lb $s1, 20($s2) # load (read) 1 byte from memory to register (in the rightmost 8 bits)
# sb $s1, 20($s2) # store 1 byte (specifically the rightmost 8 bits) of a register and writes it into memory
# lui $s0, num # load upper immediate instruction loads a value to the upper (leftmost, most significant bits) bits of a register, allowing the subsequent instruction to specify the lower (rightmost, least siginificant side) of the constant # it is used when your constants are big such that the 16 bits field is not sufficient 
# and $s1, $s2, $s3 # bit by bit logical and $s1 = $s2 & $s3 # AND helps to reset bits because ANDing anything with 0 = 0
# or $s1, $s2, $s3 # bit by bit logical or $s1 = $s2 | $s3 # OR helps to set bits because ORing anything with 1 = 1
# andi $s1, $s2, 20 # bit by bit and immediate with a constant $s1 = $s2 & 20 (the value 20 is treated as a binary value during the bitwise AND operation)
# ori $s1, $s2, 20 # bit by bit or immediate with a constant $s1 = $s2 | 20 (the value 20 is treated as a binary value during the bitwise OR operation)
# beq $s1, $s2, 25 # equality test conditional PC-relative brnach if ($s1 == $s2) go to PC + 4 + 100 # The immediate value 25 is an offset that specifies how far forward or backward to jump in the program. The offset is a 16-bit signed value that specifies the number of words to jump (each word is 4 bytes). PC is the current address of the instruction. The +4 accounts for the fact that the next instruction after the beq or bne is already being fetched. The offset is multiplied by 4 because the MIPS instruction set is word-addressed. In other words, this means PC + 4 + (25 * 4). # there are 25 lines between this instruction and the instrution at the address we are jumping to  
	# the immediate of the branch instruction will be directly put into the table of decoding # the immediate will be 0 if you are jumping to the next instruction
# bne $s1, $s2, 25 # inequality test conditional PC-relative brnach if ($s1 != $s2) go to PC + 4 + 100. # 25 is an address offset in terms of line whereas +4+100 is an offset in terms of address (bytes), so if the immediate is 0 then the address is just pc+4
# slt $s1, $s2, $s3 # compare less than and set $s1 to 1 - if ($s2 < $s3) then $s1 = 1; else $s1 = 0;
# slti $t0, $s2, 10 # $t0 = 1 if $s2 < 10
# j 2500 # unconditional jump to target address, which is 10000 in this case # the target address is a 26-bit immediate value stored in the instruction. However, since MIPS instructions are word-aligned (i.e., every instruction is 4 bytes), the target address is multiplied by 4 (i.e. left shifted twice) to get the final byte address. So, 2500 * 4. # 2500 is not an offset nor an address, it's an address that still needs to be modified by the processor (multiplied) in order to get the final address
# jr $ra # unconditional jump to register $ra - this is used for switch and procedure return # we dont have an offset here, we are jumping to the address stored in the register $ra
# sll $t2, $s0, 4 # $t2 = $s0 << 4 bits # A left shift is like multiplying by 2 for each bit shifted # So, like if $s0 = 9, then left shifting it by 4 would = 9*2*2*2*2 i.e. 9*2^(4) = 144
# srl $t1, $t0, 4 # shift right logical, if t0 = 400, then 400 /2/2/2/2 = 25
# nor $t0, $t1, $t3 # $t0 = ~($t1 or $t3)

################################################ EXERCISES ####################################################################################
# The following sequence of instructions adds the 4 variables b, c, d, e and stores the value in a
# add a, b, c # a = b + c
# add a, a, d # a = a + d
# add a, a, e # a = a + e

# Translate the following C instructions into MIPS assembly instructions: f = (g + h) � (i + j);
# add $t0, g, h
# add $t1, i, j
# sub f, $t0, $t1

# Now, assume the variables f, g, h, i, and j are assigned to the registers $s0, $s1, $s2, $s3, and $s4, respectively. What is the compiled MIPS code?
# add $t0, $s1, $s2
# add $t1, $s3, $s4
# sub $s0, $t0, $t1

# Let�s assume that A is an array of 100 words, and that the compiler has associated the variables g and h with the registers $s1 and $s2. Let�s also assume that the starting address, or base address, of the array is in $s3. Use the MIPS assembly language to compile the following C assignment statement: g = h + A[8];
# lw $t0, 32($s3) # Temporary register $t0 gets A[8] (s3 base register with a 32 offset) # NOTE that A is an array of words, and each word in MIPS is 4 bytes. Since each element (word) in the array A is 4 bytes, the 8th element is located at (4*8) = 32. Therefore, $s3 + 32 is the value of A[8]
# add $s1, $s2, $t0

# **Assume variable h is associated with register $s2 and the base address of the array A is in #$s3. What is the MIPS assembly code for the C assignment statement: A[12] = h + A[8];
# lw $t0, 32($s3) # to get A[8] we use 32 which is 4*8 inside $t0
# add $t0, $s2, $t0 # t0 = h + t0
# sw $t0, 48($s3) # to get A[12] we use 48 which is 4*12 # this instruction stores the value inside $t0 inside the address A[12]

# Consider the assignment statement A[300] = h + A[300]. If $t1 has the base of the array A and $s2 corresponds to h, write the MIPS assembly code.
# lw $t0, 1200($t1) #4*300 = 1200
# add $t0, $s2, $t0
# sw $t0, 1200($t1) 

# If the five variables f, g, h, i, j correspond to the five registers $s0 through $s4, respectively. What is the compiled MIPS code for the following C if statement? if (i == j) f = g + h; else f = g � h;
# bne $s3, $s4, Else # go to else if $s3 != $s4, otherwise continue executing the code sequentially
# add $s0, $s1, $s2 # f = g + h #This will happen if i = j i.e. if $s3 = $s4 because if they weren't equal we would have branched to somewhere else in the code and skipped this line
# j Exit # jumping unconditionally to the Exit section of the code to end the program
# ELse: sub $s0, $s1, $s2 # f = g - h # This is where the code will branch to if the i != j
# Exit:

# Convert the simple if statement if (i == j) i++; j--; assuming $s1 stores i and $s2 stores j.
# # always use the opposite of the condition to branch because if you use the condition itself you will just go to the next line anyway - no need for branch
# bne $s1, $s2, ELSE # branch to ELSE if $s1 != $s2 i.e. i != j
# addi $s1, $s1, 1 # i = i + 2
# ELSE: addi $s2, $s2, -1 # j = j + - 1 = j - 1

# **Consider the following C code: 
#while (save[i] == k) 
#i += 1; 
# Assume that we place the loop starting at location 80000 in memory. If the variables i and k correspond to the registers $s3 and $s5, respectively. The base address of save is stored in $s6 What is the compiled MIPS code.
# First, we must make sure we understand the exact functionality of the C code even if it looks simple and familiar before we try to convert it into assembly. This code will increment i by 1 as long as save[i] = k and since save is an array that depends on i for its index, then that means we are going through the array item by item and making sure they are all equal to k
# When calculating the address of an array element (like save[i]), the address calculation involves multiplying the index by the size of each element (in this case, 4 bytes) and then adding the base address of the array. This is a two-step process: you first compute the offset and then compute the final address.
# Loop: sll $t1, $s3, 2 # $t1 = $s3 << 2 = $t1 = $s3 * 2 * 2 # What this is achieving is multiplying i by 4, which is necessary because each integer in the save array occupies 4 bytes. This ensures that when you load or store a value from the array, you're accessing the correct memory location that corresponds to save[i]
# add $t1, $t1, $s6 # $t1 = $t1 + $s6 which essentially adds the base address of the save array (in $s6) to the offset calculated in the previous step ($t1). Now, $t1 contains the memory address of save[i]. The reason we are using $t1 as an intermediate register instead of doing the operations directly on $t0 is we avoid the risk of overwriting data and also it improves readability.
# lw $t0, 0($t1) # loading into regitser $t0 the value inside memory address ($t1+0) which contains save[i]
# bne $t0, $s5, Exit # Branch to Exit label if t0 != s5 which are save[i] and k # VERY IMPORTANT NOTE is that the branch destination has 2 instructions between it and this current instruction so we want to skip those 2 instructions to brnach directly to the address to the Exit which means that we want to skip 2 words (4 bytes + 4 bytes = 8 bytes) so it adds 8 bytes to the address of the following instruction
# addi $s3, $s3, 1 # i = i + 1
# j Loop # going back to label Loop again # IMPORTANT NOTE this will jump to the 20000 address in memory (not 80000) because 80000/4
# Exit: #end the program
# Remember when we are trying to pass through every element of an array we first must make the i a multiple of 4 then we add it to the base address of the array 

# Write the equivalent push/pop instruction to STR R5, [SP, #-4]! and STR R4, [SP, #-4]! #These instructions are storing R5 and R4 where the stack pointer is pointing and pre-decrementing by 4
# PUSH {R4, R5}

# Write the equivalent push/pop instruction to LDR R4, [SP], #4 and LDR R5, [SP], #4 #These instructions are loading R5 and R4 from where the stack pointer is pointing and post-incrementing by 4
# POP {R4, R5}

# int leaf_example (int g, int h, int i, int j)/ this is a callee function called by another function (caller) in the code - the caller gave it arguments (data) and this function will return results (data) to the caller
#{
#int f;
#f = (g+h) - (i+j);
#return f;
#}
# What is the compiled MIPS assembly code for the C code above? The parameter variables g, h, i, and j correspond to the argument registers $a0, $a1, $a2, and $a3, and f corresponds to $s0.
# leaf_example: #this is the label of the procedure
# addi $sp, $sp, -12 # making space on the stack for 3 words (1 word = 4 bytes) and we used negative 12 because the stack grows downwards towards lower addresses
# sw $t1, 8($sp) # saving the content of register $t1 onto the stack before we use it in the callee function (because the caller might have been storing important values in it too - we can't just overwrite things and lose critical values)
# sw $t0, 4($sp) # saving the content of register $t0 onto the stack
# sw $s0, 0($sp) # saving the content of register $s0 onto the stack
# add $t0, $a0, $a1 # $t0 = g + h
# add $t1, $a2, $a3 # $t1 = i + j
# sub $s0, $t0, $t1 # f = (g+h) - (i+j) and now we need to save the 3 registers $t0, $t1, $s0 so we will push them onto the stack and first we have to create space for them (3 registers x 4 bytes for each = 12 bytes) on the stack
# add $v0, $s0, $zero # to return the value of f we must copy it onto an appropriate function return value register 
# lw $s0, 0($sp) # popping out the registers in a last in first out style based on how we pushed them
# lw $t0, 4($sp) # restoring the value that was in register $t0 before we used it in our operations in callee function
# lw $t1, 8($sp) # restoring the value that was in register $t1 before we used it ... (we're basically packing our things back and leaving this function)
# addi $sp, $sp, 12 #adjusting the stack pointer to delete the space we made for the 3 registers
# jr $ra # careful and notice that this isn't just the jump instruction this is a jump register instruction, we use j when we have an immediate address value or label and we use jr when we are jumping to an address value stored in a register - #jump back to the calling routine using the return address register

# What is the MIPS assembly code to load the following 32-bit constant into register $s0? 0000 0000 0011 1101 0000 1001 0000 0000
# you cannot save a 32 bit value in one go in mips assembly this is because the immediate value has a limited number of bits in the i type instructions (only 16 bits)
# lui $s0, 61 # loads 0000 0000 0011 1101 into the leftmost side of the 32 bit register
# ori $s0, $s0, 2304 # loads 0000 1001 0000 0000 into the rightmost side of the 32 bit register therefore the full value in it becomes 0000 0000 0011 1101 0000 1001 0000 0000

# What would be the contents stored in the register $t0 after the following instruction gets executed?
# lui $t0, 255 # 0000 0000 1111 1111 0000 0000 0000 00000 (and keep in mind that the value of the whole 32 bits of the register is not 255 it's actually a much larger number because the 255 was loaded onto the upper 16 bits which means their values are not 32,16,8,4,2,1 but ...,65536 and so on)
# The upper 16 bits of $t0 become 0x00FF.
# The lower 16 bits are 0x0000.
# Therefore, the full 32-bit value in $t0 becomes: 0x00FF0000.


# Let $s0 refer to i, and $a1 refer to n, write the MIPS code for the loop instruction for (i = 0, i < n; i += 1) { ...
# move $s0, $zero # i = 0
# Loop: slt $t0, $s0, $a1 # set register $t0 = 1 if $s0 < $a1 # this is smart because if i < n then $t0 will be set and then in the next instruction when we do a branch if equal it's like we're seeing the result of the slt, if the $t0 was set then i indeed was less than n and if it wasn't set to 1 then i is not less than n so we leave the loop 
# beq $t0, $zero, EXIT # this is such a clever combination of slt and beq in order to acheive going somewhere in the code based on the result of a comparison like < or >
# (body of the loop not given in the question)
# addi $s0, $s0, 1 # i = i + 1
# j Loop
# EXIT:

# What represents the base address in the following instruction? 
# lw $t0, 0($t1) # this will load a word from memory address $t1 + 0 into register $t0, which means that the base address in this case is the register $t1 and the offset is 0

################################################ RUNNABLE ####################################################################################

#addi $t0, $zero, 20 # This puts the value 20 in register $t0
#addi $t3, $zero, -5 # This puts the value -5 in the register $t3
#add $s0, $t0, $t3 # This adds the value stored in registers $t0 + $t3 and stores them in $s0 (remember that the add itself is by default a signed operation, it's actually if you're unsigned that you have a special instruction which is addu)

# addi $s3, $zero, 4
# addi $s4, $zero, 4
# bne $s3, $s4, else # this would go to label else if $s3 != $s4 but they are equal so it will not branch and it will just continue executing the next instruction instead
# add $s0, $s3, $s4 # = 8
# j exit
# else: sub $s0, $s3, $s4 # = 0
# exit:


# addi $zero, $zero, 4 # you cant override the value of 0 in register $zer


# nor with 0 will achieve the same result as not
#    li $t0, 0x0000000F   # Load value 0x0000000F into $t0
#    nor $t0, $t0, $zero   # Perform NOT on $t0, result will be 0xFFFFFFF0


# addi $s1, $s1, 0x00000000
# addi $s2, $s2, 0x00000001
# addi $s3, $s3, 0x00000002
# slt $s1, $s2, $s3 # so this will only set the rightmost bit of s1 if the condition is satisfied, not the whole $s1

# mips instructions only work with hex numbers or decimal number, binary has to be converted


# A switch case code
#    addi $t0, $zero, 2       # $t0 holds the value of 'x' (switch variable)
#    addi $t1, $zero, 1       # t1 = 1
#    beq $t0, $t1, CASE1
#    addi $t1, $zero, 2       # t1 = 2
#    beq $t0, $t1, CASE2
#    addi $t1, $zero, 3       # t1 = 3
#    beq $t0, $t1, CASE3
#    j DEFAULT                # Default case if no match
# CASE1: # this is not a comment
#    addi $a0, $zero, 1       # Do something for Case 1
#    j END
# CASE2:
#    addi $a0, $zero, 2       # Do something for Case 2
#    j END
# CASE3:
#    addi $a0, $zero, 3       # Do something for Case 3
#    j END
# DEFAULT:
#    addi $a0, $zero, 0       # Do something for Default case
# END:
#    nop                      # do nothing
    

# Hello World Program
# .data                   # Section for declaring initialized data
# message: .asciiz "Hello, World!\n"  # The string to print
# .text                   # Section for the program code
# .globl main             # The starting point of the program
# main:
#    li $v0, 4           # Load system call code for print string (4) into $v0
#    la $a0, message     # Load the address of the string into $a0
#    syscall             # Make the system call
#    li $v0, 10          # Load system call code for exit (10) into $v0
#    syscall             # Make the system call to exit

add $t1, $t1, $zero
lw $t0, 4($t1)  # Load the word at memory address (value in $t1 + 4 bytes) into $t0

