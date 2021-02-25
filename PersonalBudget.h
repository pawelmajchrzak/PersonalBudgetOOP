#ifndef PersonalBudget_h
#define PersonalBudget_h

#include <iostream>

#include "UserManager.h"
#include "WalletManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    //WalletManager *walletManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;
    int loggedInUserId;

public:
    /*
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
    : userManager(nameFileWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses), loggedInUserId(0) {
    walletManager = NULL;
    };
    ~PersonalBudget() {
        delete walletManager;
        walletManager = NULL;
    };
    */
    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();
    void showBalanceInSelectedPeriod();
    void changePassword();
    void logoutUser();
    bool isUserLoggedIn();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};

#endif // PersonalBudget_h
