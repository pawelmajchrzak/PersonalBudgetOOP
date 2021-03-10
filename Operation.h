#ifndef Operation_h
#define Operation_h

#include <iostream>

using namespace std;

class Operation {
    int operationId;
    int userId;
    int date;
    string item;
    float amount;

public:
    void setOperationId(int newOperationId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getOperationId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif // Operation
