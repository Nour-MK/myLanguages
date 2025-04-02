# include <iostream>
using namespace std;

int main ()
{
    int *p1, *p2;

    p1 = new int;
    *p1 = 16;
    p2 = p1;
    cout << "*p1 = " << *p1 << endl; // 16 from the clear assignment above
    cout << "*p2 = " << *p2 << endl; // 16 because p2 points at the same address as p1 so ofc it will have the same data at that address

    *p2 = 5;
    cout << "*p1 = " << *p1 << endl; // 5 because p1 and p2 point at the same address so we can use either p1 or p2 to manipulate the value of thr data stored at that address
    cout << "*p2 = " << *p2 << endl; // 5 from the clear assignment above

    p1 = new int;
    *p1 = 88;
    cout << "*p1 = " << *p1 << endl; // 88 from the clear assignment above
    cout << "*p2 = " << *p2 << endl; // 5 because we re-declared p1 so, although it has the same name as the older one, it is actually like a newly created pointer that is not associated with p2
}