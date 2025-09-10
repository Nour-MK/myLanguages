// C-Strings

- It's an array of characters.
- It's different from the traditional array of characters.
- C-String advantage is that it has some useful pre-defined functions.
- You must include the <cstring> library in order to use the functions.
- Last element in a c-string is \0 which is called a null characater.
Because of \0 it's easier to manipulate c-strings. Because sometimes you may not know the stop point but you
at least you know that an array of characters always ends with \0.
(so for example you can male a loop work so long as the value of the index does not equal \0.)
- Needs concatenate function to add c-strings to each other.
- Always book extra space when declaring the size of a cstring just in case.
- Contains functions such as :
strcat // concatenates the two cstrings by adding the second right at the end of the first
strcmp // compares the elements inside each string and returns the ASCII code difference between the letters
// so if the letters are all the same it will return 0 because there is no difference
// if the letters are different it will return a number. ASCII code of the 1st cstring - ASCII code of the 2nd cstring
strcpy // copies elements from one cstring to the other

cin>>here you write the name of the array without [] after it

char weekday[10]="Sunday!";

strcpy (target,source)
// notice that it only takes 2 parameters

strncpy (target, source, number of characters you want to copy)
// notice that it needs 3 parameters