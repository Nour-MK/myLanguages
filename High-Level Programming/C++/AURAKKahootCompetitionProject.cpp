// 3 chance per question
// 2 difficulty levels
// count how many correct
//  no of correct / correct + incorrect *100
// loop program to repe
// diffuclty increases when the 
// use rand
//10 and 99
// 0 and 9
// intro func
// generate numbers func
// ask questions func
// 5 questions
// keep track of progress
// comments
// passing grade is 80


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variables and function prototypes
int difficulty;
int Answer;
char sign;
int correct_counter = 0;
int wrong_counter = 0;
void math_sign();
void pick_difficulty();
void generate_questions(char sign, int difficulty);

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void pick_difficulty()
{
    cout << "Pick a number for the level of difficulty.\nLevel 1: One digit numbers\nLevel 2: Two digit numbers." << endl;
    cin >> difficulty;
    if (difficulty == 1 || difficulty == 2)
    {
        generate_questions(sign, difficulty);
    }
    else
    {
        cout << "Error! The number must be between 1 and 2." << endl;
        pick_difficulty();
    }
}
// Removed empty Question functions
/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/
void generate_questions(char sign, int difficulty)
{
    int num_questions = 5;
    correct_counter = 0;
    wrong_counter = 0;
    for (int i = 1; i <= num_questions; i++)
    {
        int x, y, answer, tries = 0;
        if (difficulty == 1)
        {
            x = rand() % 10; // 0-9
            y = rand() % 10; // 0-9
        }
        else
        {
            x = 10 + rand() % 90; // 10-99
            y = 10 + rand() % 90; // 10-99
        }
        int correct = 0;
        while (tries < 3 && !correct)
        {
            cout << "Question " << i << ": ";
            cout << x << " " << sign << " " << y << " = ";
            cin >> answer;
            int result = 0;
            switch (sign)
            {
                case '+': result = x + y; break;
                case '-': result = x - y; break;
                case '*': result = x * y; break;
                case '/': result = (y != 0) ? x / y : 0; break;
            }
            if (answer == result)
            {
                cout << "Correct!\n";
                correct_counter++;
                correct = 1;
            }
            else
            {
                cout << "Incorrect. Try again.\n";
                tries++;
                if (tries == 3)
                {
                    cout << "The correct answer is: " << result << "\n";
                    wrong_counter++;
                }
            }
        }
    }
    int total = correct_counter + wrong_counter;
    double percent = (total > 0) ? (double)correct_counter / total * 100 : 0;
    cout << "\nYou got " << correct_counter << " out of " << num_questions << " correct." << endl;
    cout << "Your score: " << percent << "%\n";
    if (percent >= 80)
        cout << "Congratulations! You passed.\n";
    else
        cout << "You did not pass. Try again!\n";
}
/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/
void math_sign()
{
    cout << "Enter the mathematical operator you'd like to practice (+, -, *, /): ";
    cin >> sign;
    if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
    {
        pick_difficulty();
    }
    else
    {
        cout << "Error! Operator must be +, -, *, /" << endl;
        math_sign();
    }
}
/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/
int main()
{
    srand(time(0)); // Seed random number generator
    cout << "Welcome to the math practice simulation!" << endl;
    math_sign();
    return 0;
}

// main to welcome
// enter math sign - check input and error
// enter difficulty - check input and error
// generate problem based on diffuclty and math sign