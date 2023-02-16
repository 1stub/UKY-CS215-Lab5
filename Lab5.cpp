/*course: CS215 - 014x
 *Project: Lab 5 (As part of Project 1)
 *Purpose: Display the Super Bowl in Roman Numeral Representation
 *         The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
 *         This program displays the Super Bowls in a centenary, from year 2000 to year 2099.
 *Author: Anthony Arnold
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Must be using c++17 for this roman_numeral to work

/*
   Returns a string form of a Roman numeral.
   n must be between 1 and 3999
   @param n the number to convert into Roman Numeral
   @return string representing the corresponding Roman Numeral for n
*/

string roman_numeral(int num) {
    vector < pair < int, string >> roman_val{
        { 1000, "M" },
        { 900,  "CM" },
        { 500,  "D" },
        { 400,  "CD" },
        { 100,  "C" },
        { 90,   "XC" },
        { 50,   "L" },
        { 40,   "XL" },
        { 10,   "X" },
        { 9,    "IX" },
        { 5,    "V" },
        { 4,    "IV" },
        { 1,    "I" }
    };

    string total;

    for ( auto [x, y] : roman_val) { 
        while (num >= x) {
            total += y;
            num -= x;
        }
    }
    return total;
}

int main()
{
    const int START_SUPERBOWL = 1967;      // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum) 
    const int START = 2000;     // This program displays Super Bowl starting in year 2000
    const int END = 2099;        // This program displays Super Bowl ending in year 2099
    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    // The last Super Bowl which can be represented by Roman Numerals would be: START_SUPERBOWL + MAX_ROMAN - 1;
    const int GROUP = 10;                  // Layout the years in a group of 10

    // display the first 100 years of Super Bowl, starting at 1967
    cout << endl << "\t\t\tSuper Bowl Records" << endl;
    cout << "The first Super Bowl was hold at Los Angeles Memorial Coliseum on January 15, " << START_SUPERBOWL << endl;
    cout << "\tYear\t\tSuper Bowl" << endl;

    for (int i = START; i <= END; i++)
    {
        int year = i - START_SUPERBOWL + 1;
        if (i % GROUP == 0)
            cout << endl << "************************************" << endl << endl;
        cout << "\t" << i << "\t--->\t" << roman_numeral(year) << endl;
    }

    return 0;
}


/*
   Returns a string form of a Roman numeral.
   n must be between 1 and 3999
   @param n the number to convert into Roman Numeral
   @return string representing the corresponding Roman Numeral for n
*/

//This code works

/*string roman_numeral(int num)
{
    string m[] = { "", "M", "MM", "MMM" };
    string c[] = { "",  "C",  "CC",  "CCC",  "CD", "D", "DC", "DCC", "DCCC", "CM" };
    string x[] = { "",  "X",  "XX",  "XXX",  "XL", "L", "LX", "LXX", "LXXX", "XC" };
    string i[] = { "",  "I",  "II",  "III",  "IV", "V", "VI", "VII", "VIII", "IX" };

    // Converting to roman
    string thousands = m[num / 1000];
    string hundreds = c[(num % 1000) / 100];
    string tens = x[(num % 100) / 10];
    string ones = i[num % 10];

    string ans = thousands + hundreds + tens + ones;

    return ans;
} */