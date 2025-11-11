#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // ---- Constructors ----
    Date();                              // Default constructor
    Date(int d, int m, int y);           // Parameterized constructor
    Date(const Date &d);                 // Copy constructor

    // ---- Member Functions ----
    void printDate() const;

    // ---- Operator Overloading ----
    int operator-(Date d2);              // Difference in days
    Date operator+(int days);            // Add days to date
    Date operator++();                   // Prefix ++
    Date operator++(int);                // Postfix ++
    void operator=(Date d2);             // Assignment
    bool operator==(Date d2);            // Equality check
    operator int();                      // Type casting to int (total days)
    int operator[](char ch);             // Access by character
};

// ---- Constructors ----
Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
    cout << "Default constructor called!" << endl;
}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
    cout << "Parameterized constructor called!" << endl;
}

Date::Date(const Date &d) {
    day = d.day;
    month = d.month;
    year = d.year;
    cout << "Copy constructor called!" << endl;
}

// ---- printDate ----
void Date::printDate() const {
    cout << day << "/" << month << "/" << year << endl;
}

// ---- Operator Overloading ----

// Difference in days (approximate)
int Date::operator-(Date d2) {
    int total1 = year * 365 + month * 30 + day;
    int total2 = d2.year * 365 + d2.month * 30 + d2.day;
    return total1 - total2;
}

// Add days to date
Date Date::operator+(int days) {
    Date temp = *this;
    temp.day += days;
    while (temp.day > 30) {
        temp.day -= 30;
        temp.month++;
        if (temp.month > 12) {
            temp.month = 1;
            temp.year++;
        }
    }
    return temp;
}

// Prefix ++
Date Date::operator++() {
    *this = *this + 1;
    return *this;
}

// Postfix ++
Date Date::operator++(int) {
    Date temp = *this;
    *this = *this + 1;
    return temp;
}

// Assignment
void Date::operator=(Date d2) {
    this -> day = d2.day;
    this -> month = d2.month;
    this -> year = d2.year;
}

// Equality check
bool Date::operator==(Date d2) {
    return (day == d2.day && month == d2.month && year == d2.year);
}

// Casting to int (total days)
Date::operator int() {
    return (year * 365 + month * 30 + day);
}

// Access by character
int Date::operator[](char ch) {
    switch (ch) {
        case 'd':
        case 'D':
            return day;
        case 'm':
        case 'M':
            return month;
        case 'y':
        case 'Y':
            return year;
        default:
            cout << "Invalid index! Use 'd', 'm', or 'y'." << endl;
            return -1;
    }
}

// ---- Main Function ----
int main() {
    cout << "d1 = 5  / 11 / 2025" << endl;
    cout << "d1 = 15 / 11 / 2025" << endl << endl;
    Date d1(5, 11, 2025), d2(15, 11, 2025);
    Date d3;

    cout << "\n--- Testing Operators ---\n";

    cout << "\nd3 = d1 + 10\n";
    d3 = d1 + 10;
    d3.printDate(); // 15/11/2025 approx.

    cout << "Difference: " << (d2 - d1) << " days\n";

    ++d1;
    cout << "After prefix ++ : "; d1.printDate();

    d1++;
    cout << "After postfix ++ : "; d1.printDate();

    if (d1 == d2)
        cout << "Dates are equal!\n";
    else
        cout << "Dates are different!\n";

    int totalDays = (int)d1;
    cout << "Total days from 0 AD: " << totalDays << endl;

    cout << "Day = " << d1['d'] << ", Month = " << d1['m'] << ", Year = " << d1['y'] << endl;

    return 0;
}
