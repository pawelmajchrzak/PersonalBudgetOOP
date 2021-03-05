#ifndef FileWithUsers_h
#define FileWithUsers_h

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "FileXML.h"

using namespace std;

class FileWithUsers //: public FileXML
{
public:
    //FileWithUsers(string nameFileWithUsers) : FileXML(nameFileWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif // FileWithUsers_h
