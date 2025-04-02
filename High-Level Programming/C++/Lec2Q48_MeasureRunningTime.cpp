# include <iostream>
# include <ctime> // library in which the clock() function is defined 
using namespace std;

int main ()
{
   clock_t StartTime = clock (); // This line records the time right before the code enclosed between StartTime and EndTime runs
   // clock_t is a clock type capable of representing clock tick counts.
   // Clock ticks are units of time of a constant but system-specific length
   // clock () returns the approximate processor time that is consumed by the program expressed in clock ticks
   // The clock() time depends on how the operating system allocate resources to the process that’s why clock() time may be slower or faster than the actual clock.

   // Code to be measured goes here between StartTime and EndTime
   
   // Note that a simple one cout statement takes 0 seconds, so this isn't an useful case to measure, better measure a loop that runs
   // for at least 100 times

   clock_t EndTime = clock (); // This line records the time right after the code enclosed between StartTime and EndTime finishes running

   cout << double ((EndTime - StartTime))/CLOCKS_PER_SEC << endl; 
   // The difference between the time the code starts running and the time it finishes is the total time, and divided over how many ticks
   // there are per second, it gives the amount of time the code took to run in seconds.
}