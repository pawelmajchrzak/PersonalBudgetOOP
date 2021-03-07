#ifndef FileWithIncomes_h
#define FileWithIncomes_h

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "FileXML.h"

using namespace std;

class FileWithIncomes //: public FileXML
{
    int lastIncomeId;
public:
    //FileWithUsers(string nameFileWithUsers) : FileXML(nameFileWithUsers) {};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
    int getLastIncomeId();
};

#endif // FileWithIncomes_h
