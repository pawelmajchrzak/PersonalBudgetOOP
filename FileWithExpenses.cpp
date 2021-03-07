#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));
    xml.Save("expenses.xml");
}

vector <Expense>  FileWithExpenses::loadExpensesOfLoggedInUserFromFile(int loggedInUserId) {
    Expense expense;
    vector <Expense> expenses;
    lastExpenseId = 0;
    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()) {

        xml.IntoElem();
        xml.FindElem();
        int expenseId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        int userId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        int date = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        string item = xml.GetData();
        xml.FindElem();
        float amount = AuxiliaryMethods::convertStringToFloat(xml.GetData());
        xml.OutOfElem();
        lastExpenseId = expenseId;
        if (loggedInUserId == userId) {
        expense.setExpenseId(expenseId);
        expense.setUserId(userId);
        expense.setDate(date);
        expense.setItem(item);
        expense.setAmount(amount);
        expenses.push_back(expense);
        }
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

