#ifndef UserManager_h
#define UserManager_h

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool isThereALoginExisting(string login);

public:

    UserManager (string filenameWithUsers) : fileWithUsers(filenameWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedInUserId();

    void showAllUsers();
};

#endif // UserManager_h
