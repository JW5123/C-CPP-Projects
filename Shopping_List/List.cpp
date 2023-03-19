#include <iostream>
#include "List.h"
using namespace std;

List::List(){
    setFirstItem(0);
}

void List::setFirstItem(shoppingItem *newFirstItem){
    firstItem = newFirstItem;
}

shoppingItem *List::getFirstItem(){
    return firstItem;
}

void List::addItem(string itemName, int quantity){
    shoppingItem *newItem = new shoppingItem(itemName, quantity, 0);

    newItem->setNextItem(getFirstItem());
    setFirstItem(newItem);
}

void List::displayList(){
    shoppingItem *currentItem = getFirstItem();

    cout << "\nShopping List\n";
    cout << "--------------\n";

    while(currentItem != 0){
        currentItem->display();
        currentItem = currentItem->getNextItem();
    }
}

void List::deleteList(){
    shoppingItem *currentItem = getFirstItem();

    while(currentItem != 0){
        shoppingItem *nextItem = currentItem->getNextItem();
        cout << "\nMemory being released for: " << currentItem->getName() << "\n";

        delete currentItem;

        currentItem = nextItem; 
    }
}