#ifndef FileWithOperations_h
#define FileWithOperations_h

#include <iostream>
#include <vector>

#include "Operation.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "FileXML.h"

using namespace std;

class FileWithOperations : public FileXML
{
    int lastOperationId;
public:
    FileWithOperations(string nameFileWithOperations) : FileXML(nameFileWithOperations) {
    lastOperationId = 0;
    };
    void addOperationToFile(Operation operation);
    vector <Operation> loadOperationsOfLoggedInUserFromFile(int loggedInUserId);
    int getLastOperationId();
};

#endif // FileWithOperations_h
