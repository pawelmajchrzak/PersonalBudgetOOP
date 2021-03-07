#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntegerToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInteger(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

float AuxiliaryMethods::convertStringToFloat(string number) {
    float numberFloat;
    numberFloat = atof(number.c_str());
    return numberFloat;
}

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::loadChar() {
    string enter = "";
    char character  = {0};

    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            character = enter[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int AuxiliaryMethods::loadInteger() {
    string enter = "";
    int number = 0;

    while (true) {
        getline(cin, enter);

        stringstream myStream(enter);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::loadLine() {
    cin.clear();
    cin.sync();
    string enter = "";
    getline(cin, enter);
    return enter;
}

string AuxiliaryMethods::getNumber(string text, int charPosition) {
    string number = "";
    while(isdigit(text[charPosition]) == true) {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

int AuxiliaryMethods::loadCurrentDate() {
    time_t t = time(nullptr);
    tm *tm = localtime(&t);
    int currentYear = 1900 + tm->tm_year;
    int currentMonth = 1 + tm->tm_mon;
    int currentDay = tm->tm_mday;
    int currentDate=currentYear*10000+currentMonth*100+currentDay;
    return currentDate;
}

bool AuxiliaryMethods::compareDate(int date1, int date2) {
    if (date1>=date2)
        return true;
    else
        return false;
}

int AuxiliaryMethods::daysInMonth(int month, int year) {
    int daysInMonth = 0;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daysInMonth = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;

    case 2: {
        if (((year%4==0)&&(year%100!=0))||(year%400==0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    break;

    default:
        cout << "Bledny numer miesiaca";
    }

    return daysInMonth;
}

int AuxiliaryMethods::checkAndConvertDateToInteger(string date) {
    int dateInt = 0;
    if ((date.length()!=10)||(date[4]!='-')||(date[7]!='-'))
        return 0;

    string year = date.substr(0,4);
    int yearInt = atoi(year.c_str());
    string month = date.substr(5,2);
    int monthInt = atoi(month.c_str());
    string day = date.substr(8,2);
    int dayInt = atoi(day.c_str());

    int currentDate = loadCurrentDate();
    cout << currentDate <<endl;
    int currentYear = currentDate/10000;
    int currentMonth = (currentDate-currentYear*10000)/100;
    int currentDay = currentDate%100;

    if ((yearInt<2000)||(yearInt>currentYear)||(monthInt<1)||(monthInt>12))
        return 0;
    if ((dayInt<1)||(dayInt>AuxiliaryMethods::daysInMonth(monthInt, yearInt)))
        return 0;
    if (((monthInt>currentMonth)&&(yearInt==currentYear))||((yearInt==currentYear)&&(monthInt==currentMonth)&&(dayInt>currentDay)))
        return 0;
    dateInt=yearInt*10000+monthInt*100+dayInt;

    return dateInt;
}




