#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::loginUser() {
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    for (int i = 0 ; i< users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password) {
                    loggedInUserId = users[i].getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i = 0 ; i< users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            fileWithUsers.saveChangesToFileXML(i,newPassword);
            system("pause");
        }
    }
}

void UserManager::logoutUser() {
    loggedInUserId = 0;
}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isThereALoginExisting(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;

}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isThereALoginExisting(string login) {
    for (int i = 0 ; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers() {
    for (int i = 0 ; i< users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}
