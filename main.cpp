#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");

    char select;

    while (true) {
        if (personalBudget.getLoggedInUserId() == 0) {
            select = personalBudget.selectOptionFromMainMenu();

            switch (select) {
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
        } else {
            select = personalBudget.selectOptionFromUserMenu();

            switch (select) {

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
    return 0;
}
