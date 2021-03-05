#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save("users.xml");
}

vector <User>  FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()) {
        xml.IntoElem();
        xml.FindElem();
        user.setId(AuxiliaryMethods::convertStringToInteger(xml.GetData()));
        xml.FindElem();
        user.setLogin(xml.GetData());
        xml.FindElem();
        user.setPassword(xml.GetData());
        xml.FindElem();
        user.setName(xml.GetData());
        xml.FindElem();
        user.setSurname(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::saveChangesToFileXML(int userNumber, string newPassword) {
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    for (int i=0; i<=userNumber; i++)
        xml.FindElem();
    xml.IntoElem();
    xml.FindElem();
    xml.FindElem();
    xml.FindElem();
    xml.SetData(newPassword);
    cout << xml.GetData() << "ej to ja" << endl;
    xml.Save("users.xml");
}
