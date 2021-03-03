#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    //PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");
    PersonalBudget personalBudget;
    string date = "2020-03-04";
    int dateInt = AuxiliaryMethods::checkAndConvertDateToInteger(date);
    //personalBudget.registerUser();
    //personalBudget.loginUser();
        if (dateInt!=0)
        cout << dateInt << endl;
    else
        cout << "Nie poprawna data lub jej format!" << endl;
    personalBudget.showAllUsers();

    return 0;
}
