#include "PersonalBudget.h"

using namespace std;

void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::loginUser() {
    userManager.loginUser();

    if (userManager.isUserLoggedIn()) {
        walletManager = new WalletManager(FILE_NAME_WITH_INCOMES,FILE_NAME_WITH_EXPENSES,userManager.getLoggedInUserId());
    }

}

void PersonalBudget::changePassword() {
    userManager.changePassword();
}

void PersonalBudget::logoutUser() {
    userManager.logoutUser();
    //delete walletManager;
    //walletManager = NULL;
}

int PersonalBudget::getLoggedInUserId() {
    loggedInUserId = userManager.getLoggedInUserId();
    return loggedInUserId;
}

char PersonalBudget::selectOptionFromMainMenu() {
    char select;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::loadChar();

    return select;
}

char PersonalBudget::selectOptionFromUserMenu() {
    char select;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    //cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
    //cout << "3. Wyszukaj po nazwisku" << endl;
    //cout << "4. Wyswietl adresatow" << endl;
    //cout << "5. Usun adresata" << endl;
    //cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxiliaryMethods::loadChar();

    return select;
}

void PersonalBudget::addIncome() {
    if (userManager.isUserLoggedIn()) {
        walletManager->addIncome();
    } else {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void PersonalBudget::addExpense() {
    if (userManager.isUserLoggedIn()) {
        walletManager->addExpense();
    } else {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}


void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}

