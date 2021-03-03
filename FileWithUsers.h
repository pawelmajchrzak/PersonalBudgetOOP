#ifndef FileWithUsers_h
#define FileWithUsers_h

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
//#include "PlikTekstowy.h"

using namespace std;

class FileWithUsers //: public PlikTekstowy
{
public:
    void addUserToFile(User user);
};

#endif // FileWithUsers_h
