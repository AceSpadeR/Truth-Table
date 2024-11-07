#include <iostream>
#include "truthtable.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    truthT table;
    char AR;
    char negation;
    bool pNot = false, qNot = false;
    cout << "Enter: V (or), A (and)" << endl
         << "Do you want to use And or Or? ";
    cin >> AR;
    table.checkAR(AR);

    cout << "Enter: Y (Yes), N (No)" << endl
         << "Do you want to NOT p? ";
    cin >> negation;
    table.checkChoice(negation);
    if (negation == 'Y' || negation == 'y')
    {
        pNot = true;
        table.doNegation(pNot, qNot);
        pNot = false;
    }

    cout << "Do you want to NOT q? ";
    cin >> negation;
    table.checkChoice(negation);
    if (negation == 'Y' || negation == 'y')
    {
        qNot = true;
        table.doNegation(pNot, qNot);
        qNot = false;
    }

    table.doOperation(AR);

    cout << table;
    return 0;
}