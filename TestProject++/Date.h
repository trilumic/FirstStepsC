#ifndef DATE_H
#define DATE_H

class Date{

private:
int year, day, month;
Date() {}

public:
Date(int year, int month, int day);
void printDate();
};


#endif // DATE_H
