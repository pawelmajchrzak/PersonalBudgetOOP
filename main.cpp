#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int maink()
{
    PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");
    //personalBudget.registerUser();
    personalBudget.loginUser();
    personalBudget.showBalanceForCurrentMonth();
    //personalBudget.showBalanceInSelectedPeriod();
    personalBudget.showBalanceForPreviousMonth();
    //personalBudget.showIncoe();
    //personalBudget.addIncome();
    //personalBudget.addExpense();
}


int main()
{
    PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");

    char select;

    while (true)
    {
        if (personalBudget.getLoggedInUserId() == 0)
        {
            select = personalBudget.selectOptionFromMainMenu();

            switch (select)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            select = personalBudget.selectOptionFromUserMenu();

            switch (select)
            {

            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.showBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceInSelectedPeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            }
        }
    }

    //personalBudget.registerUser();
    //personalBudget.loginUser();
    //personalBudget.logoutUser();
    //personalBudget.loginUser();
    //personalBudget.changePassword();
    //personalBudget.showAllUsers();




    //checkAndConvertDate
    //string date = "2020-03-04";
    //int dateInt = AuxiliaryMethods::checkAndConvertDateToInteger(date);
    //        if (dateInt!=0)
    //    cout << dateInt << endl;
    //else
    //    cout << "Nie poprawna data lub jej format!" << endl;


    return 0;
}
