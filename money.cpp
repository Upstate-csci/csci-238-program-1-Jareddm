/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#include <cmath>
#include "money.h"

string result;

// convert current currency values to a string
string Money::toString() {
    string str = to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) +
        " quarters " + to_string(dimes) + " dimes "  + to_string(nickels) + " nickels " + to_string(cents) + " pennies";
    return str;
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {

    stringstream ss;

    ss << "$" << fixed << setprecision(2) << amount;

    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    double money = 0;
    cin >> hundreds;
    cin >> tens;
    cin >> fives;
    cin >> ones;
    cin >> quarters;
    cin >> dimes;
    cin >> nickels;
    cin >> cents;

    money += hundreds * 100;
    money += tens * 10;
    money += fives * 5;
    money += ones * 1;
    money += quarters * 0.25;
    money += dimes * 0.10;
    money += nickels * 0.05;
    money += cents * 0.01;

    result = toString() + " = " + toCurrency(money) + "\n";

    return result;
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    //initial and remaining Money
    double rMoney = 0;
    string iMoney;

    cin >> iMoney;
    rMoney = stod(iMoney);

    hundreds = rMoney / 100;
    rMoney -= (hundreds * 100);
    tens = rMoney / 10;
    rMoney -= (tens * 10);
    fives = rMoney / 5;
    rMoney -= (fives * 5);
    ones = rMoney / 1;
    rMoney -= (ones * 1);
    quarters = rMoney / 0.25;
    rMoney -= (quarters * 0.25);
    dimes = rMoney / 0.10;
    rMoney -= (dimes * 0.10);
    nickels = rMoney / 0.05;
    rMoney -= (nickels * 0.05);
    cents = static_cast<int>(round(rMoney * 100.00));

    result = iMoney + " = " + toString() + "\n";

    return result;
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    //initial and remaining Money
    double iMoney = 0, rMoney = 0;
    string result;

    cin >> iMoney;
    rMoney = iMoney;

    hundreds = rMoney / 100;
    rMoney -= (hundreds * 100);
    tens = rMoney / 10;
    rMoney -= (tens * 10);
    ones = rMoney / 1;
    rMoney -= (ones * 1);
    cents = static_cast<int>(round(rMoney * 100.00));

    result = "check for " + toCurrency(iMoney) + "= ";

    if (hundreds > 0)
    {
        switch (hundreds)
        {
            case 1: result += "One hundred ";
                break;
            case 2: result += "Two hundred ";
                break;
            case 3: result += "Three hundred ";
                break;
            case 4: result += "Four hundred ";
                break;
            case 5: result += "Five hundred ";
                break;
            case 6: result += "Six hundred ";
                break;
            case 7: result += "Seven hundred ";
                break;
            case 8: result += "Eight hundred ";
                break;
            case 9: result += "Nine hundred ";
                break;
            default: cout << "invalid entry";
        }

    }
    if (tens == 1)
    {
        switch (ones)
        {
            case 1: result += "eleven ";
                break;
            case 2: result += "twelve ";
                break;
            case 3: result += "thirteen ";
                break;
            case 4: result += "fourteen ";
                break;
            case 5: result += "fifteen ";
                break;
            case 6: result += "sixteen ";
                break;
            case 7: result += "seventeen ";
                break;
            case 8: result += "eighteen ";
                break;
            case 9: result += "nineteen ";
                break;
            default: cout << "invalid entry teens";
        }

    }
    if (tens > 1)
    {
        switch (tens)
        {
            case 2: result += "twenty ";
                break;
            case 3: result += "thirty ";
                break;
            case 4: result += "forty ";
                break;
            case 5: result += "fifty ";
                break;
            case 6: result += "sixty ";
                break;
            case 7: result += "seventy ";
                break;
            case 8: result += "eighty ";
                break;
            case 9: result += "ninety ";
                break;
            default: cout << "invalid entry tens";
        }

    }
    if ( ones > 0 && tens != 1)
    {
        switch(ones)
        {
            case 1: result += "one ";
                break;
            case 2: result += "two ";
                break;
            case 3: result += "three ";
                break;
            case 4: result += "four ";
                break;
            case 5: result += "five ";
                break;
            case 6: result += "six ";
                break;
            case 7: result += "seven ";
                break;
            case 8: result += "eight ";
                break;
            case 9: result += "nine ";
                break;
            default: cout << "invalid entry ones";
        }
    }

    if (hundreds == 0 && tens == 0 && ones == 0)
    {
        result += "Zero ";
    }

    result += "dollars and ";

    result += to_string(cents) + " cents" + "\n";

    return result;
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    //initial and remaining Change
    double money = 0, iChange = 0, rChange = 0;

    cin >> money;
    cin >> total;

    iChange = money - total;
    rChange = iChange;

    hundreds = rChange / 100;
    rChange -= (hundreds * 100);
    tens = rChange / 10;
    rChange -= (tens * 10);
    fives = rChange / 5;
    rChange -= (fives * 5);
    ones = rChange / 1;
    rChange -= (ones * 1);
    quarters = rChange / 0.25;
    rChange -= (quarters * 0.25);
    dimes = rChange / 0.10;
    rChange -= (dimes * 0.10);
    nickels = rChange / 0.05;
    rChange -= (nickels * 0.05);
    cents = static_cast<int>(round(rChange * 100.00));

    result = "change back on " + toCurrency(money) + " for purchase of " + toCurrency(total) + " is " + toCurrency(iChange) + " which is " + toString() + "\n";
    return result;
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    //initial and remaining Change
    double money = 0, iChange = 0, rChange = 0;

    cin >> hundreds;
    cin >> tens;
    cin >> fives;
    cin >> ones;
    cin >> quarters;
    cin >> dimes;
    cin >> nickels;
    cin >> cents;

    cin >> total;

    money += hundreds * 100;
    money += tens * 10;
    money += fives * 5;
    money += ones * 1;
    money += quarters * 0.25;
    money += dimes * 0.10;
    money += nickels * 0.05;
    money += cents * 0.01;

    iChange = money - total;
    rChange = iChange;

    result = "change back on " + toString() + " for purchase of " + toCurrency(total) + " is " + toCurrency(iChange) + " which is ";

    hundreds = rChange / 100;
    rChange -= (hundreds * 100);
    tens = rChange / 10;
    rChange -= (tens * 10);
    fives = rChange / 5;
    rChange -= (fives * 5);
    ones = rChange / 1;
    rChange -= (ones * 1);
    quarters = rChange / 0.25;
    rChange -= (quarters * 0.25);
    dimes = rChange / 0.10;
    rChange -= (dimes * 0.10);
    nickels = rChange / 0.05;
    rChange -= (nickels * 0.05);
    cents = static_cast<int>(round(rChange * 100.00));


    result += toString() + "\n";

    return result;
}
