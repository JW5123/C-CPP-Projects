#include <iostream>
#include "shoppingItem.h"
using namespace std;

shoppingItem::shoppingItem(string &itemName, int itemQuantity, shoppingItem *nextPointer){
    setName(itemName);
    setQuantity(itemQuantity);
    setNextItem(nextPointer);
}

void shoppingItem::setName(string &itemName){
    name = itemName;
}

string shoppingItem::getName(){
    return name;
}

void shoppingItem::setQuantity(int itemQuantity){
    if(itemQuantity < 0)
        quantity = 0;
    else
        quantity = itemQuantity;
}

int shoppingItem::getQuantity(){
    return quantity;
}

void shoppingItem::setNextItem(shoppingItem *nextPointer){
    next = nextPointer;
}

shoppingItem *shoppingItem::getNextItem(){
    return next;
}

void shoppingItem::display(){
    cout << "\nName: " << getName() << "\n";
    cout << "Quantity: " << getQuantity() << "\n";
}