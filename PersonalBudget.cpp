#include "PersonalBudget.h"

using namespace std;

void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::loginUser() {
    userManager.loginUser();

    if (userManager.isUserLoggedIn()) {
        //walletManager = new WalletManager(FILE_NAME_WITH_INCOMES,userManager.getIdLoggedUser());
    }

}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}


void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}

