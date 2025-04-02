#include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/
// All the global declarations

int old_currency;
int new_currency;
char choice;
double money_amount; 
// chose to make it double type in case the user had halfs or quarters to convert (making the program as efficent as possible)
void data_entry ();
int main ();
// had to globally declare the main in this program because it was called in the continuation function
void check (int old_currency, int new_currency);
void continuation ();
// below are the 10 conversion functions
// they contain mathmatical equations to convert from the old currency to the new one 
// (the multiplication factor is the ratio between both currencies)
void convert2AED (int old_currency, double money_amount); 
void convert2IND (int old_currency, double money_amount);
void convert2USD (int old_currency, double money_amount);
void convert2GBP (int old_currency, double money_amount);
void convert2EUR (int old_currency, double money_amount);
void convert2AUD (int old_currency, double money_amount);
void convert2JOD (int old_currency, double money_amount);
void convert2TRY (int old_currency, double money_amount);
void convert2PHP (int old_currency, double money_amount);
void convert2KWD (int old_currency, double money_amount);
// globally declaring all the variables and functions
// in case some of them are called within other user-defined functions

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/


void data_entry ()
// the purpose of this function is to take data from the user
{

  cout <<
    "Please select the number of the currency you would like to convert." <<
    endl;

  cin >> old_currency;		// the user must enter a number from 1 to 10 



  cout <<
    "Please select the number of the currency you would like to convert to."
    << endl;

  cin >> new_currency;		// the user must enter a number from 1 to 10 and it can't be the same number as the old_currency 



  cout << "How much money would you like to convert?" << endl;

  cin >> money_amount; // any number is ok



  check (old_currency, new_currency); 
  // calling the check function that would make sure everything the user has input is valid for the program to operate

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/



void check (int old_currency, int new_currency)
/* the purpose of this function is to check the currency numbers that the user chose are within the offered limits (the 10 currencies) 
and that the currency the user chose to convert to isn't the same as the original currency (because that would mean they don't need  
to convert anything) before passing it on to the currency converter */
{

  if (old_currency >= 1 && old_currency <= 10 && new_currency >= 1 && new_currency <= 10 && new_currency != old_currency)

    // we had to use && for this one because all these conditions must be satisfied for the program to continue working properly 

    {
      if (new_currency == 1) // Emirati Dirham
	      convert2AED (old_currency, money_amount);

      else if (new_currency == 2) // Indian Rupee
	      convert2IND (old_currency, money_amount);

      else if (new_currency == 3) // US Dollar
	      convert2USD (old_currency, money_amount);

      else if (new_currency == 4) // British Pound
	      convert2GBP (old_currency, money_amount);

      else if (new_currency == 5) // Euro
	      convert2EUR (old_currency, money_amount);

      else if (new_currency == 6) // Australian Dollar
	      convert2AUD (old_currency, money_amount);

      else if (new_currency == 7) // Jordanian Dinar
	      convert2JOD (old_currency, money_amount);

      else if (new_currency == 8) // Turkish Lira
	      convert2TRY (old_currency, money_amount);

      else if (new_currency == 9) // Philippine Peso
	      convert2PHP (old_currency, money_amount);

      else if (new_currency == 10) // Kuwaiti Dinar
	      convert2KWD (old_currency, money_amount);



    }



  else

    {

      // we had to nest if statements inside the else statement because there are different reposnes for the unsatified conditions, 

      // if it was just one same response then we could have directly plugged it insode the else without any nested if's 



      if (old_currency < 1 || old_currency > 10 || new_currency < 1
	  || new_currency > 10)

	// we had to use || for this because if either of these conditions is unsatisfied then they generate the same issue 

	{

	  cout <<
	    "Error! Invalid option! Please choose a numbers from the options displayed above!"
	    << endl << endl;

	  data_entry (); // calling the data entry function to automatically enable the user to enter the values again but correctly

	}



      if (new_currency == old_currency)

	// we had to seperate this condition from the above ones because the error response to it must be different but in the end 

	// it will lead the user to re-enter the data 

	{

	  cout <<
	    "Error! Invalid option! The currency you wish to convert to must not be the same as your original currency!"
	    << endl << endl;

	  data_entry ();

	}

    }



}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2AED (int old_currency, double money_amount)
// converting from the old currency the user chose to Emirati Dirham
{
  cout << "The converted amount is ";

  if (old_currency == 2) // Indian Rupee
    cout << money_amount * 0.049 << endl;

  else if (old_currency == 3) // US Dollar
    cout << money_amount * 3.67 << endl;

  else if (old_currency == 4) // British Pound
    cout << money_amount * 4.90 << endl;

  else if (old_currency == 5) // Euro
    cout << money_amount * 4.16 << endl;

  else if (old_currency == 6) // Australian Dollar
    cout << money_amount * 2.62 << endl;

  else if (old_currency == 7) // Jordanian Dinar
    cout << money_amount * 5.18 << endl;

  else if (old_currency == 8) // Turkish Lira
    cout << money_amount * 0.30 << endl;

  else if (old_currency == 9) // Philippine Peso
    cout << money_amount * 0.073 << endl;

  else if (old_currency == 10) // Kuwaiti Dinar
    cout << money_amount * 12.13 << endl;


}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2IND (int old_currency, double money_amount)
// converting from the old currency the user chose to Indian Rupee
{
  cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 20.43 << endl;

  else if (old_currency == 3)
    cout << money_amount * 75.05 << endl;

  else if (old_currency == 4)
    cout << money_amount * 100.14 << endl;

  else if (old_currency == 5)
    cout << money_amount * 84.96 << endl;

  else if (old_currency == 6)
    cout << money_amount * 53.46 << endl;

  else if (old_currency == 7)
    cout << money_amount * 105.86 << endl;

  else if (old_currency == 8)
    cout << money_amount * 6.04 << endl;

  else if (old_currency == 9)
    cout << money_amount * 1.49 << endl;

  else if (old_currency == 10)
    cout << money_amount * 247.82 << endl;

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2USD (int old_currency, double money_amount)
// converting from the old currency the user chose to American Dollar
{
    cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 0.27 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.013 << endl;

  else if (old_currency == 4)
    cout << money_amount * 1.33 << endl;

  else if (old_currency == 5)
    cout << money_amount * 1.13 << endl;

  else if (old_currency == 6)
    cout << money_amount * 0.71 << endl;

  else if (old_currency == 7)
    cout << money_amount * 1.41 << endl;

  else if (old_currency == 8)
    cout << money_amount * 0.080 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.020 << endl;

  else if (old_currency == 10)
    cout << money_amount * 3.30 << endl;


}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2GBP (int old_currency, double money_amount)
// converting from the old currency the user chose to British Pound
{
    cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 0.20 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.01 << endl;

  else if (old_currency == 3)
    cout << money_amount * 0.75 << endl;

  else if (old_currency == 5)
    cout << money_amount * 0.85 << endl;

  else if (old_currency == 6)
    cout << money_amount * 0.53 << endl;

  else if (old_currency == 7)
    cout << money_amount * 1.06 << endl;

  else if (old_currency == 8)
    cout << money_amount * 0.06 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.015 << endl;

  else if (old_currency == 10)
    cout << money_amount * 2.48 << endl;


}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2EUR (int old_currency, double money_amount)
// converting from the old currency the user chose to Euro
{
  cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 0.24 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.012 << endl;

  else if (old_currency == 3)
    cout << money_amount * 0.88 << endl;

  else if (old_currency == 4)
    cout << money_amount * 1.18 << endl;

  else if (old_currency == 6)
    cout << money_amount * 0.63 << endl;

  else if (old_currency == 7)
    cout << money_amount * 1.25 << endl;

  else if (old_currency == 8)
    cout << money_amount * 0.071 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.018 << endl;

  else if (old_currency == 10)
    cout << money_amount * 2.92 << endl;

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2AUD (int old_currency, double money_amount)
// converting from the old currency the user chose to Australian Dollar
{
    cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 0.38 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.019 << endl;

  else if (old_currency == 3)
    cout << money_amount * 1.40 << endl;

  else if (old_currency == 4)
    cout << money_amount * 1.87 << endl;

  else if (old_currency == 5)
    cout << money_amount * 1.59 << endl;

  else if (old_currency == 7)
    cout << money_amount * 1.98 << endl;

  else if (old_currency == 8)
    cout << money_amount * 0.11 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.029 << endl;

  else if (old_currency == 10)
    cout << money_amount * 4.64 << endl;

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2JOD (int old_currency, double money_amount)
// converting from the old currency the user chose to Jordanian Dinar
{
    cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 0.19 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.0094 << endl;

  else if (old_currency == 3)
    cout << money_amount * 0.71 << endl;

  else if (old_currency == 4)
    cout << money_amount * 0.95 << endl;

  else if (old_currency == 5)
    cout << money_amount * 0.80 << endl;

  else if (old_currency == 6)
    cout << money_amount * 0.51 << endl;

  else if (old_currency == 8)
    cout << money_amount * 0.057 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.014 << endl;

  else if (old_currency == 10)
    cout << money_amount * 2.34 << endl;


}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2TRY (int old_currency, double money_amount)
// converting from the old currency the user chose to Turkish Lira
{
    cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 3.38 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.17 << endl;

  else if (old_currency == 3)
    cout << money_amount * 12.43 << endl;

  else if (old_currency == 4)
    cout << money_amount * 16.58 << endl;

  else if (old_currency == 5)
    cout << money_amount * 14.06 << endl;

  else if (old_currency == 6)
    cout << money_amount * 8.85 << endl;

  else if (old_currency == 7)
    cout << money_amount * 17.53 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.25 << endl;

  else if (old_currency == 10)
    cout << money_amount * 41.04 << endl;


}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2PHP (int old_currency, double money_amount)
// converting from the old currency the user chose to Philippine Peso
{
    cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 13.75 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.67 << endl;

  else if (old_currency == 3)
    cout << money_amount * 50.50 << endl;

  else if (old_currency == 4)
    cout << money_amount * 67.38 << endl;

  else if (old_currency == 5)
    cout << money_amount * 57.14 << endl;

  else if (old_currency == 6)
    cout << money_amount * 35.94 << endl;

  else if (old_currency == 7)
    cout << money_amount * 71.22 << endl;

  else if (old_currency == 8)
    cout << money_amount * 4.06 << endl;

  else if (old_currency == 10)
    cout << money_amount * 166.79 << endl;

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void convert2KWD (int old_currency, double money_amount) 
// converting from the old currency the user chose to Kuwaiti Dinar
{
  cout << "The converted amount is ";

  if (old_currency == 1)
    cout << money_amount * 0.082 << endl;

  else if (old_currency == 2)
    cout << money_amount * 0.0040 << endl;

  else if (old_currency == 3)
    cout << money_amount * 0.30 << endl;

  else if (old_currency == 4)
    cout << money_amount * 0.40 << endl;

  else if (old_currency == 5)
    cout << money_amount * 0.34 << endl;

  else if (old_currency == 6)
    cout << money_amount * 0.22 << endl;

  else if (old_currency == 7)
    cout << money_amount * 0.43 << endl;

  else if (old_currency == 8)
    cout << money_amount * 0.024 << endl;

  else if (old_currency == 9)
    cout << money_amount * 0.006 << endl;


}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void continuation ()
{
  cout <<
    "Enter 'Y' if you would like to continue converting. Else, please enter 'N'."
    << endl;
  cin >> choice;

  if (choice == 'Y')
    main (); // calling the main function which will repeat the code in the case the user wants to continue

  else if (choice == 'N')
    cout << "The program is finished." << endl;

  else
    {
      cout << "Error!" << endl; // in case the user inputs an response that doesn't is not a yes or no
      continuation ();
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{

  cout << "\t \t \t ( Currency Convereter ) \t \t \t" << endl;	//title of the program 

  cout << "\t  - - - - - - - - - - - - - - - - - - - - - - - - - - - \t " <<
    endl;

  cout << "\t  - - - - - - - - - - - - - - - - - - - - - - - - - - - \t " <<
    endl << endl << endl; // multiple endlines used just for beautification



  cout << "\t \t \t1.  AED - Emirati Dirham\t \t \t" << endl // multiple tabs used to center the options menu and beautify the code
    << "\t \t \t2.  INR - Indian Rupee\t \t \t" << endl
    << "\t \t \t3.  USD - US Dollar\t \t \t" << endl
    << "\t \t \t4.  GBP - British Pound\t \t \t" << endl
    << "\t \t \t5.  EUR - Euro\t \t \t" << endl
    << "\t \t \t6.  AUD - Australian Dollar\t \t \t" << endl
    << "\t \t \t7.  JOD - Jordanian Dinar\t \t \t" << endl
    << "\t \t \t8.  TRY - Turkish Lira\t \t \t" << endl
    << "\t \t \t9.  PHP - Philippine Peso\t \t \t" << endl
    << "\t \t \t10. KWD - Kuwaiti Dinar\t \t \t" << endl << endl;
// above is the menu which will be centered on the screen and displayed to the user
// it's the menu of all the currencies available for the user to convert to and from


  data_entry ();		// (data entry) leads to (check) which leads to (choice) which leads to one of the (10 conversion functions)

  continuation (); // looping the program based on the user's wish


  return 0;

}
