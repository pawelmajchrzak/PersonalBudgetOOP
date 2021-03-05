#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    //PersonalBudget personalBudget("Users.xml","Incomes.xml","Expenses.xml");
    PersonalBudget personalBudget;

    char select;

    while (true)
    {
        if (personalBudget.getLoggedInUserId() == 0)
        {
            select = personalBudget.selectOptionFromMainMenu();

            switch (select)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            select = personalBudget.selectOptionFromUserMenu();

            switch (select)
            {
            /*
            case '1':
                personalBudget.dodajAdresata();
                break;
            case '2':
                personalBudget.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                personalBudget.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                personalBudget.wypiszWszystkichAdresatow();
                break;
            case '5':
                personalBudget.usunAdresata();
                break;
            case '6':
                personalBudget.edytujAdresata();
                break;
            */
            case '7':
                personalBudget.changePassword();
                break;
            case '8':
                personalBudget.logoutUser();
                break;
            }
        }
    }

    //personalBudget.registerUser();
    //personalBudget.loginUser();
    //personalBudget.logoutUser();
    //personalBudget.loginUser();
    //personalBudget.changePassword();
    //personalBudget.showAllUsers();




    //checkAndConvertDate
    //string date = "2020-03-04";
    //int dateInt = AuxiliaryMethods::checkAndConvertDateToInteger(date);
    //        if (dateInt!=0)
    //    cout << dateInt << endl;
    //else
    //    cout << "Nie poprawna data lub jej format!" << endl;


    return 0;
}
