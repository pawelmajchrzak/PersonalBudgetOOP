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
    struct less_than_date {
        inline bool operator() (Income struct1, Income struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };
    struct less_than_dateExp {
        inline bool operator() (Expense struct1, Expense struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };
    sort(incomes.begin(), incomes.end(), less_than_date());
    sort(expenses.begin(), expenses.end(), less_than_dateExp());

    int date = AuxiliaryMethods::loadCurrentDate();
    int minDate = date/100*100;
    int maxDate = minDate+100;
    float sumIncomes = 0;
    float sumExpenses = 0;
    system("cls");
    cout << "    >>> Bilans " << date/10000 << "-" << minDate%10000/100 << " <<<" << endl << endl;
    cout << "    >>> Przychody: <<<" << endl << endl;
    for (int i = 0 ; i< incomes.size(); i++)
        if ((incomes[i].getDate()>minDate)&&(incomes[i].getDate()<maxDate)) {
            displayIncome(i);
            sumIncomes += incomes[i].getAmount();
        }
    cout << "              Suma przychodow:   ";
    printf("%.2f zl", sumIncomes);

    cout << endl << endl << "    >>> Wydatki: <<<" << endl << endl;
    for (int i = 0 ; i< expenses.size(); i++)
        if ((expenses[i].getDate()>minDate)&&(expenses[i].getDate()<maxDate)) {
            displayExpense(i);
            sumExpenses += expenses[i].getAmount();
        }
    cout << "              Suma wydatkow:     ";
    printf("%.2f zl", sumExpenses);
    cout << endl << endl;
    cout << "    >>> Bilans: <<<              ";
    printf("%.2f zl", sumIncomes-sumExpenses);
    cout << endl << endl;


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
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    float amount;
    cout << "Podaj wysokosc przychodu: ";
    amount = AuxiliaryMethods::loadAmount();
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
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    float amount;
    cout << "Podaj wysokosc przychodu: ";
    amount = AuxiliaryMethods::loadAmount();
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
        case '2': {
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
            }
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

//void WalletManager::sortVector(vector <Operation> &operations) {


