#include <iostream>
#include <iomanip>
#include "shoppingItem.h"
#include "List.h"
using namespace std;

int displayMenu(){
    int selection = 0;

    cout << "\nSelect one of the following options\n";
    cout << "1 - Enter new item\n";
    cout << "2 - Display list\n";
    cout << "3 - Exit the application\n";
    cout << "Enter selection: ";
    cin >> selection;

    return selection;
}

int main(){
    int selection = 0;
    string itemName;
    int itemQuantity;
    List shoppingList;

    while(selection != 3){
        selection = displayMenu();

        switch (selection){
        case 1:
            cin.ignore();

            cout << "\nEnter item name: ";
            getline(cin, itemName);

            cout << "Enter quantity: ";
            cin >> itemQuantity;

            shoppingList.addItem(itemName, itemQuantity);

            break;
        case 2:
            shoppingList.displayList();

            break;
        case 3:
            shoppingList.deleteList();
            cout << "\n";
            
            break;
        default:
            cout << "error: Enter a valid menu selection";
        }
    }
    
    return 0;
}