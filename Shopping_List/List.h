#ifndef LIST_H
#define LIST_H

#include "shoppingItem.h"
using namespace std;

class List {
    public:
        List();

        void setFirstItem(shoppingItem *);
        shoppingItem *getFirstItem();

        void addItem(string, int);
        void displayList();
        void deleteList();

    private:
    shoppingItem *firstItem;

};

#endif //LIST_H