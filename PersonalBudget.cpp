#include "PersonalBudget.h"

using namespace std;

void PersonalBudget::registerUser() {
    userManager.registerUser();
}
/*
void PersonalBudget::loginUser() {
    userManager.loginUser();

    if (userManager.isUserLoggedIn()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }

}
*/

void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}
