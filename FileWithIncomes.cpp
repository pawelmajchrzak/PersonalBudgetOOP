#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));
    xml.Save("incomes.xml");
}

vector <Income>  FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId) {
    Income income;
    vector <Income> incomes;
    lastIncomeId = 0;
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()) {

        xml.IntoElem();
        xml.FindElem();
        int incomeId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        int userId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        int date = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        string item = xml.GetData();
        xml.FindElem();
        float amount = AuxiliaryMethods::convertStringToFloat(xml.GetData());
        xml.OutOfElem();
        lastIncomeId = incomeId;
        if (loggedInUserId == userId) {
        income.setIncomeId(incomeId);
        income.setUserId(userId);
        income.setDate(date);
        income.setItem(item);
        income.setAmount(amount);
        incomes.push_back(income);
        }
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
