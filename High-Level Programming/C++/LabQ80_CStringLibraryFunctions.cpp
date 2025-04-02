# include <iostream>
# include <cstring>
using namespace std;

int main ()
{
    char s1 [50] = "jack";
    char s2 [25] = "jill";
    char s3 [50] = "jamy";
    cout << strcpy (s3, s2) << endl; 
    // copying the content of s2 into s3, so now s3 = "jill" so we print that

    char s4 [50] = "nour";
    char s5 [25] = "mustafa";
    char s6 [50] = "kamel";
    cout << strlen (s4) + strlen (s5) << endl; 
    // the addition of the numbers of characters in string s4 and s5 without counting the null
    // 4 + 7 = 11

    char s7 [50] = "kaz";
    char s8 [25] = "brekker";
    strcat (s7, s8); 
    // concatenating string s8 to the end of string s7, so the new s7 = kazbrekker
    cout << s7 << endl;    
}