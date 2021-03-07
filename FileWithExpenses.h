#ifndef FileWithExpenses_h
#define FileWithExpenses_h

#include <iostream>
#include <vector>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "FileXML.h"

using namespace std;

class FileWithExpenses //: public FileXML
{
    int lastExpenseId;
public:
    //FileWithUsers(string nameFileWithUsers) : FileXML(nameFileWithUsers) {};
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesOfLoggedInUserFromFile(int loggedInUserId);
    int getLastExpenseId();
};

#endif // FileWithExpenses_h
