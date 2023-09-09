// Compare Objects
// compare.cpp

#include <iostream>
#include "ArrayList.h"
using namespace std;
using namespace lectures;

void banchod(const ArrayList& someData)
{
    cout << "This function BC() has been called. ";
    someData.display();
}

int main() {
    /* float gh[] = { 89.4f, 67.8f, 45.5f };
     Student harry(1234, gh, 3), harry_(1234, gh, 3);
     if (areIdentical(harry, harry_))
         cout << "are identical" << endl;
     else
         cout << "are different" << endl;*/

   // banchod(ArrayList(5));

    ArrayList al(10);
    ArrayList al1;
    if (al)
    {
        al.display();
    }
    else
    {
        cout << "Lauduu";
    }


    if (al1)
    {
        al1.display();
    }
    else
    {
        cout << "Banchod" << endl;
    }

   // cout << "The obj al printed to the screen: " << al << endl;
   // cout << "The obj al printed to the screen: " << al1 << endl;


    al.push_back(5.6)
        .push_back(2.6)
        .display();

    al1.push_back(4.567)
        .push_back(9.876)
        .display();

    al += al1;
    al.display();

    al << al1;
    al.display();
    // :: ?: .
    // Overloading operator
    // Cant add more operator
    // Cant change the number of param
    // Some operators cant be overloaded
}