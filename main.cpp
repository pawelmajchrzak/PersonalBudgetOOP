#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    //PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");
    PersonalBudget personalBudget;

    //personalBudget.registerUser();
    personalBudget.loginUser();

    personalBudget.showAllUsers();




    //checkAndConvertDate
    //string date = "2020-03-04";
    //int dateInt = AuxiliaryMethods::checkAndConvertDateToInteger(date);
    //        if (dateInt!=0)
    //    cout << dateInt << endl;
    //else
    //    cout << "Nie poprawna data lub jej format!" << endl;


    return 0;
}
