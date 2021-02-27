#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::loginUser() {

}

void UserManager::changePassword() {

}

void UserManager::logoutUser() {

}

bool UserManager::isUserLoggedIn() {

}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isThereALoginExising(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {

}

bool UserManager::isThereALoginExising() {

}
