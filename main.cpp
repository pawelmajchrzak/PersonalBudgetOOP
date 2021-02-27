#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    //PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");
    PersonalBudget personalBudget;

    personalBudget.registerUser();
    personalBudget.loginUser();


    return 0;
}
