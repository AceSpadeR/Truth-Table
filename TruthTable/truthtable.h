#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class truthT
{
private:
    string header = "|p|q|";
    string p = " p ";
    string q = "q ";
    int X = 0, Y = 1;
    char grid[4][5] = {
        {'T', 'T', ' ', ' ', ' '},
        {'T', 'F', ' ', ' ', ' '},
        {'F', 'T', ' ', ' ', ' '},
        {'F', 'F', ' ', ' ', ' '}};

public:
    const int NUM_ROWS = 4, NUM_COL = 5;
    truthT() {}
    void doNegation(bool, bool);
    void doOperation(char);
    char checkAR(char &);
    char checkChoice(char &);
    friend ostream &operator<<(ostream &, const truthT &);
};

char truthT::checkAR(char &AR)
{
    do
    {
        if (AR != 'A' && AR != 'V' && AR != 'a' && AR != 'v')
        {
            cout << "Wrong input:";
            cin >> AR;
        }
    } while (AR != 'A' && AR != 'V' && AR != 'a' && AR != 'v');
    return AR;
}

char truthT::checkChoice(char &negation)
{
    do
    {
        if (negation != 'Y' && negation != 'N' && negation != 'y' && negation != 'n')
        {
            cout << endl
                 << "Wrong input:";
            cin >> negation;
        }
    } while (negation != 'Y' && negation != 'N' && negation != 'y' && negation != 'n');
    return negation;
}

void truthT::doNegation(bool pNot, bool qNot)
{
    if (pNot == true)
    {
        header += "~p|";
        p = "~p ";
        X = 2;
        for (int i = 0; i < NUM_ROWS; i++)
        {
            if (grid[i][0] == 'T')
            {
                grid[i][2] = 'F';
            }
            else
            {
                grid[i][2] = 'T';
            }
        }
    }
    if (qNot == true)
    {
        header += "~q|";
        q = "~q";
        Y = 3;
        for (int i = 0; i < NUM_ROWS; i++)
        {
            if (grid[i][1] == 'T')
            {
                grid[i][3] = 'F';
            }
            else
            {
                grid[i][3] = 'T';
            }
        }
    }
}

void truthT::doOperation(char AR)
{
    if (AR == 'A' || AR == 'a')
    {
        cout << header << p << "A " << q << "|" << endl;

        for (int r = 0; r < NUM_ROWS; r++)
        {
            if (grid[r][X] == 'T' && grid[r][Y] == 'T')
            {
                grid[r][4] = 'T';
            }
            else
            {
                grid[r][4] = 'F';
            }
        }
    }
    else
    {
        cout << header << p << "V " << q << "|" << endl;
        for (int r = 0; r < NUM_ROWS; r++)
        {
            if (grid[r][X] == 'T' || grid[r][Y] == 'T')
            {
                grid[r][4] = 'T';
            }
            else
            {
                grid[r][4] = 'F';
            }
        }
    }
}

ostream &operator<<(ostream &out, const truthT &T)
{
    for (int r = 0; r < T.NUM_ROWS; r++)
    {
        for (int c = 0; c < T.NUM_COL; c++)
        {
            if (T.grid[r][c] != ' ')
            {
                out << '|';
                if (c == 4)
                {
                    out << "   ";
                }
                out << T.grid[r][c];
                if (c == 2 || c == 3)
                {
                    out << " ";
                }
            }
        }
        out << "   |" << endl;
    }
    return out;
}
