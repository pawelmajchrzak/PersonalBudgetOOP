#include "WalletManager.h"

void WalletManager::addIncome() {
    Operation income = getNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.addOperationToFile(income);

    cout << endl << "Przychod zostal dodany pomyslnie!" << endl << endl;
    system ("pause");
}

void WalletManager::addExpense() {
    Operation expense = getNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.addOperationToFile(expense);

    cout << endl << "Wydatek zostal dodany pomyslnie!" << endl << endl;
    system ("pause");
}

void WalletManager::showBalanceForCurrentMonth() {
    int date = AuxiliaryMethods::loadCurrentDate();
    int beginningOfPeriod = date/100*100+1;
    int endOfPeriod = beginningOfPeriod + AuxiliaryMethods::daysInMonth(date%10000/100, date/10000) - 1;
    showBalance(beginningOfPeriod,endOfPeriod);
}

void WalletManager::showBalanceForPreviousMonth() {
    int dateCurrent = AuxiliaryMethods::loadCurrentDate();
    int date = 0;
    if (dateCurrent%10000/100 != 12)
        date = dateCurrent-100;
    else date = dateCurrent-10000+1100;
    int beginningOfPeriod = date/100*100+1;
    int endOfPeriod = beginningOfPeriod + AuxiliaryMethods::daysInMonth(date%10000/100, date/10000) - 1;
    showBalance(beginningOfPeriod,endOfPeriod);
}

void WalletManager::showBalanceInSelectedPeriod() {
    system ("cls");
    cout << "Data poczatku okresu" << endl;
    int beginningOfPeriod = AuxiliaryMethods::loadDate();
    cout << endl << "Data konca okresu" << endl;
    int endOfPeriod = AuxiliaryMethods::loadDate();
    showBalance(beginningOfPeriod,endOfPeriod);
}

Operation WalletManager::getNewIncomeData() {
    Operation income;
    income.setOperationId(fileWithIncomes.getLastOperationId()+1);
    income.setUserId(LOGGED_IN_USER_ID);
    income.setDate(setDate());

    string item;
    cout << "Podaj nazwe przychodu: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    float amount;
    cout << "Podaj wysokosc przychodu: ";
    amount = AuxiliaryMethods::loadAmount();
    income.setAmount(amount);

    return income;
}

Operation WalletManager::getNewExpenseData() {
    Operation expense;

    expense.setOperationId(fileWithExpenses.getLastOperationId()+1);
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(setDate());

    string item;
    cout << "Podaj nazwe wydatku: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    float amount;
    cout << "Podaj wysokosc wydatku: ";
    amount = AuxiliaryMethods::loadAmount();
    expense.setAmount(amount);

    return expense;
}

int WalletManager::getUserId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getOperationId() + 1;
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
            date = AuxiliaryMethods::loadDate();
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            //system("pause");
            break;
        }
    }
    return date;
}


void WalletManager::displayIncome(int incomeId) {
    cout << AuxiliaryMethods::convertDateToFormatyyyymmdd (incomes[incomeId].getDate()) << " ";
    cout << incomes[incomeId].getItem() << "    ";
    printf("%.2f zl", incomes[incomeId].getAmount());
    cout << endl;
}

void WalletManager::displayExpense(int expenseId) {
    cout << AuxiliaryMethods::convertDateToFormatyyyymmdd (expenses[expenseId].getDate()) << " ";
    cout << expenses[expenseId].getItem() << "    ";
    printf("%.2f zl", expenses[expenseId].getAmount());
    cout << endl;
}

void WalletManager::showBalance(int beginningOfPeriod, int endOfPeriod) {
    struct less_than_date {
        inline bool operator() (Operation struct1, Operation struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };
    sort(incomes.begin(), incomes.end(), less_than_date());
    sort(expenses.begin(), expenses.end(), less_than_date());

    float sumIncomes = 0;
    float sumExpenses = 0;
    system("cls");
    cout << "    >>> Bilans " << AuxiliaryMethods::convertDateToFormatyyyymmdd(beginningOfPeriod) << " - " << AuxiliaryMethods::convertDateToFormatyyyymmdd(endOfPeriod) << " <<<" << endl << endl;
    cout << "    >>> Przychody: <<<" << endl << endl;
    for (int i = 0 ; i< incomes.size(); i++)
        if ((incomes[i].getDate()>=beginningOfPeriod)&&(incomes[i].getDate()<=endOfPeriod)) {
            displayIncome(i);
            sumIncomes += incomes[i].getAmount();
        }
    cout << "              Suma przychodow:   ";
    printf("%.2f zl", sumIncomes);

    cout << endl << endl << "    >>> Wydatki: <<<" << endl << endl;
    for (int i = 0 ; i< expenses.size(); i++)
        if ((expenses[i].getDate()>=beginningOfPeriod)&&(expenses[i].getDate()<=endOfPeriod)) {
            displayExpense(i);
            sumExpenses += expenses[i].getAmount();
        }
    cout << "              Suma wydatkow:     ";
    printf("%.2f zl", sumExpenses);
    cout << endl << endl;
    cout << "    >>> Bilans: <<<              ";
    printf("%.2f zl", sumIncomes-sumExpenses);
    cout << endl << endl;
    system ("pause");
}
