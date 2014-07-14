#include <iostream>
#include <stdio.h>
#include "math.h"
#include "date.h"
#include "string.h"
#include "IntArray.h"

#define MARC
#define RAPHI



using namespace std;

int main()
{

    IntArray arr(10);

    for(int i = 0; i < arr.getLength(); i++)
    {
        arr[i] = i * 17;
        cout << arr[i] << endl;
    }
    /*

    #undef RAPHI
    Date date(2014,12,23);
    date.printDate();
    #ifdef MARC
    int x = 7634;
    #endif // MARC
    char name[255] = "Raphi";
    cout << strcat(name, " der Tapfere") << endl;
    #ifdef RAPHI
    int x = 900;
    #endif // RAPHI

    cout << "Multiplication: " << multiply(x,y) << endl;

    cout << "Subtraction: " << subtract(x,y) <<endl;

    cout << "Division : " << divide(x,y) << endl;

    cout << "Addition: " << add(x,10) << endl;


cout << add(x,93); */
    return 0;
}
