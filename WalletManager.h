#ifndef WalletManager_h
#define WalletManager_h

#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class WalletManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;


    Income getNewIncomeData();
    Expense getNewExpenseData();
    int getUserId();
    int setDate();
    //void sortVector(vector <Operation> &operations);


public:
    WalletManager(string nameFileWithIncomes, string nameFileWithExpenses, int loggedInUserId)
        : fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses),
        LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
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
