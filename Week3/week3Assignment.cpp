#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    if (year % 4 != 0) return false;
    
    bool isDivisibleBy100 = year % 100 == 0;
    bool isDivisibleBy400 = year % 400 == 0;

    return !isDivisibleBy100 || isDivisibleBy400;

    return (year % 100 != 0) || (year % 400 == 0);
}

void printBool(bool b) {
    cout << (b ? "Yes" : "No") << endl;
}

int main() {

    int year;
    cout << "Enter a year to see if it's a leap year: ";
    cin >> year;

    printBool(isLeapYear(year));

    return 0;
}