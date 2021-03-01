#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    //PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");
    PersonalBudget personalBudget;

    personalBudget.registerUser();
    //personalBudget.loginUser();
    personalBudget.showAllUsers();
    personalBudget.registerUser();
    personalBudget.registerUser();
    personalBudget.showAllUsers();

    return 0;
}
