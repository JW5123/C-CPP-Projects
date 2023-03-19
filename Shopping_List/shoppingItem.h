#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <string>
using namespace std;

class shoppingItem {
    public:
        shoppingItem(string &, int, shoppingItem *); //constructor

        void setName(string &);
        string getName();

        void setQuantity(int);
        int getQuantity();

        void setNextItem(shoppingItem *);
        shoppingItem *getNextItem();

        void display();

    private:
        string name;
        int quantity;

        shoppingItem *next;
};

#endif //SHOPPINGITEM_H