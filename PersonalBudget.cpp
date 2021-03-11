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
    delete walletManager;
    walletManager = NULL;
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
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
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
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}


void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}

void PersonalBudget::showBalanceForCurrentMonth() {
    if (userManager.isUserLoggedIn()) {
        walletManager->showBalanceForCurrentMonth();
    } else {
        cout << "Aby zobaczyc bilans, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void PersonalBudget::showBalanceForPreviousMonth() {
    if (userManager.isUserLoggedIn()) {
        walletManager->showBalanceForPreviousMonth();
    } else {
        cout << "Aby zobaczyc bilans, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void PersonalBudget::showBalanceInSelectedPeriod() {
    if (userManager.isUserLoggedIn()) {
        walletManager->showBalanceInSelectedPeriod();
    } else {
        cout << "Aby zobaczyc bilans, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void PersonalBudget::showIncoe() {
    if (userManager.isUserLoggedIn()) {
        walletManager->displayIncome(1);
    } else {
        cout << "Aby zobaczyæ bilans, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}


