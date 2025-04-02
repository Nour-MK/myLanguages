import java.util.*;  // must always be added before the class name - it is responsible of enabling the programmer to use input commands

public class InputPrintNameAgeWeight 
{
    static Scanner console = new Scanner (System.in);  
    // must always be added after class name

    public static void main (String [] arg) 
    {
        String name;
        int age;
        double weight;

        System.out.println("Please enter your name, age, and weight.");

        name = console.nextLine(); // this is the input command syntax
        age = console.nextInt();
        weight = console.nextDouble();

        System.out.println("Name : " + name);
        System.out.println("Age : " + age);
        System.out.println("Weight : " + weight);
    }
}
