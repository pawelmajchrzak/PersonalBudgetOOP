#include "WalletManager.h"

void WalletManager::addIncome() {
    Income income = getNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Przychod zostal dodany pomyslnie!" << endl << endl;
    system ("pause");
}

void WalletManager::addExpense() {
    Expense expense = getNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Wydatek zostal dodany pomyslnie!" << endl << endl;
    system ("pause");
}

void WalletManager::showBalanceForCurrentMonth() {

}

void WalletManager::showBalanceForPreviousMonth() {

}

void WalletManager::showBalanceInSelectedPeriod() {

}

Income WalletManager::getNewIncomeData() {
    Income income;
    income.setIncomeId(fileWithIncomes.getLastIncomeId()+1);
    income.setUserId(LOGGED_IN_USER_ID);
    income.setDate(setDate());

    string item;
    cout << "Podaj nazwe przychodu: ";
    cin >> item;
    income.setItem(item);

    float amount;
    cout << "Podaj wysokosc przychodu: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}

Expense WalletManager::getNewExpenseData() {
    Expense expense;

    expense.setExpenseId(fileWithExpenses.getLastExpenseId()+1);
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(setDate());

    string item;
    cout << "Podaj nazwe przychodu: ";
    cin >> item;
    expense.setItem(item);

    float amount;
    cout << "Podaj wysokosc przychodu: ";
    cin >> amount;
    expense.setAmount(amount);

    return expense;
}

int WalletManager::getUserId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

int WalletManager::setDate() {
    system("cls");
    cout << "Czy przychod dotyczy dzisiejszego dnia?" << endl << endl;
    cout << "1. Tak" << endl;
    cout << "2. Nie" << endl;
    char select;
    int date = 0;
    while (date == 0) {
        select = AuxiliaryMethods::loadChar();
        switch (select) {
        case '1':
            date = AuxiliaryMethods::loadCurrentDate();
            break;
        case '2':
            string dateString = "";
            while (true) {
                cout << "Podaj date w formacie rrrr-mm-dd: ";
                cin >> dateString;
                date = AuxiliaryMethods::checkAndConvertDateToInteger(dateString);
                if (date != 0)
                    break;
                else
                    cout << "Bledna data lub jej format!";
            }
            break;

        //default: {
         //   cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
          //  system("pause");
        //}
        //    break;


        }
    }
    return date;
}
