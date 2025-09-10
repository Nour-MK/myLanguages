//Strings

String are declared using type string. Also, you have to include the library <string>. 
No function to concatenate. Just use + operator between one string and the other.
To print the length of a string use cout<<S1.length();
To input use getline (cin,S1); or cin>>S1;  ((S1 is the name of the string))

string S1="Paula";
cout<<S1.at(2); // this function prints the character at index 2
// output : u

string S4="hieja";
cout<<S4.find('j'); // this function searches for the letter j in the string and prints its index for you so you can find it
// output : 3

string S8="hiejd";
cout<<S8.substr (1,2); 
// 1 is the index of where you want to start cutting
// 2 is the number of elements you want to cut starting from the index you decided previously

// output : ie

cout<<S8.substr(2,3);
// output : ejd

cout<<S8.substr(2,5);
// output : ejd
