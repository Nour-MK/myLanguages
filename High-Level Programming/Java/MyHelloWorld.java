// https://www.youtube.com/watch?v=BB0gZFpukJU
// In order for the interpreter to work on your java code, you must open vs code on the folder of the project. It can't just be the file itself opened in any window.

public class MyHelloWorld // Note how the class name is the same as the file name
{
	public static void main (String [] arg) // main method when the Java program begins execution
    { 
        // ANSI escape code to clear the screen from the path of the file to achieve a cleaner terminal output
        System.out.print("\033[H\033[2J");
        System.out.flush();

        // Print your message after clearing the screen
        System.out.println("Nour is learning to code Java yo!");
        
    } // ends method main

} // ends the class MyHelloWorld