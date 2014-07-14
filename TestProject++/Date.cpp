#include "Date.h"
#include <stdio.h>
#include <iostream>

Date::Date(int year, int month, int day) : year(year), month(month), day(day){}
    /*this->year = year;
    this->month = month;
    this->day = day;}*/

void Date::printDate(){
    using namespace std;
        cout << "Date is: " << year << "." << month << "." << day << endl;
        }
