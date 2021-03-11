#ifndef WalletManager_h
#define WalletManager_h

#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

#include "Operation.h"
#include "FileWithOperations.h"
#include "AuxiliaryMethods.h"

using namespace std;

class WalletManager {
    const int LOGGED_IN_USER_ID;
    vector <Operation> incomes;
    vector <Operation> expenses;
    FileWithOperations fileWithIncomes;
    FileWithOperations fileWithExpenses;


    Operation getNewIncomeData();
    Operation getNewExpenseData();
    int getUserId();
    int setDate();
    void showBalance(int beginningOfPeriod, int endOfPeriod);
    //vector <Operation> sortVector(vector <Operation> vec);

public:
    WalletManager(string nameFileWithIncomes, string nameFileWithExpenses, int loggedInUserId)
        : fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses),
        LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadOperationsOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadOperationsOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();
    void showBalanceInSelectedPeriod();

    void displayIncome(int incomeId);
    void displayExpense(int expenseId);
};

#endif // WalletManager_h
