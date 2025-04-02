#include <iostream>
using namespace std;

int main ()
{
	char c;
	while (c != 'n')
	{
		cout << "Do you want to continue: (y/n)" << endl;
		cin >> c;
	}
}