#include "FileWithOperations.h"

void FileWithOperations::addOperationToFile(Operation operation) {
    CMarkup xml;
    bool fileExists = xml.Load( getFileName() );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("OperationId", operation.getOperationId());
    xml.AddElem("UserId", operation.getUserId());
    xml.AddElem("Date", operation.getDate());
    xml.AddElem("Item", operation.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(operation.getAmount()));
    xml.Save(getFileName());
}

vector <Operation>  FileWithOperations::loadOperationsOfLoggedInUserFromFile(int loggedInUserId) {
    Operation operation;
    vector <Operation> operations;
    lastOperationId = 0;
    CMarkup xml;
    bool fileExists = xml.Load( getFileName() );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()) {

        xml.IntoElem();
        xml.FindElem();
        int operationId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        int userId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        int date = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        xml.FindElem();
        string item = xml.GetData();
        xml.FindElem();
        float amount = AuxiliaryMethods::convertStringToFloat(xml.GetData());
        xml.OutOfElem();
        lastOperationId = operationId;
        if (loggedInUserId == userId) {
        operation.setOperationId(operationId);
        operation.setUserId(userId);
        operation.setDate(date);
        operation.setItem(item);
        operation.setAmount(amount);
        operations.push_back(operation);
        }
    }
    return operations;
}

int FileWithOperations::getLastOperationId()
{
    return lastOperationId;
}
