#include "Operation.h"

void Operation::setOperationId(int newOperationId) {
    if (newOperationId >= 0)
        operationId = newOperationId;
}
void Operation::setUserId(int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}
void Operation::setDate(int newDate) {
    date = newDate;
}
void Operation::setItem(string newItem) {
    item = newItem;
}
void Operation::setAmount(float newAmount) {
    amount = newAmount;
}

int Operation::getOperationId() {
    return operationId;
}
int Operation::getUserId() {
    return userId;
}
int Operation::getDate() {
    return date;
}
string Operation::getItem() {
    return item;
}
float Operation::getAmount() {
    return amount;
}
