#ifndef AuxiliaryMethods_h
#define AuxiliaryMethods_h


#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

class AuxiliaryMethods
{
    static int daysInMonth(int month, int year);

public:
    static string convertIntegerToString(int number);
    static int convertStringToInteger(string number);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static char loadChar();
    static int loadInteger();
    static string loadLine();
    static string getNumber(string text, int charPosition);
    static int loadCurrentDate();
    static bool compareDate(int date1, int date2);
    static int checkAndConvertDateToInteger(string date);

};


#endif // AuxiliaryMethods_h
