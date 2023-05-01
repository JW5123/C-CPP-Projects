#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int rollDice(){
    int die1, die2, diceSum;
    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    diceSum = die1 + die2;

    cout << "\nPlayer rolled " << die1 << " + " << die2 << " = " << diceSum << "\n";
    return diceSum;
}
int main(){
    const int LUCKY_SEVEN = 7;
    const int YO_LEVEN = 11;

    const int SNAKE_EYES = 2;
    const int TREY = 3;
    const int BOX_CARS = 12;
    const int CRAPS = 7;

    enum status{CONTINUE, WON, LOST};

    int sum;
    int myPoint;
    string input;
    status gameStatus;

    srand(time(0));
    sum = rollDice();

    switch(sum){
        case LUCKY_SEVEN:
        case YO_LEVEN:
            gameStatus = WON;
            break;

        case SNAKE_EYES:
        case TREY:
        case BOX_CARS:
            gameStatus = LOST;
            break;

        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            cout << "Point is " << myPoint << "\n";
            break;
    }
    while(gameStatus == CONTINUE){
        cout << "\nPress enter to continue...";
        getline(cin, input);

        sum = rollDice();
        if(sum == myPoint){
            gameStatus = WON;
        }
        else if(sum == CRAPS){
            gameStatus = LOST;
        }
    }
    if(gameStatus == WON){
        cout << "Player wins" << "\n\n";
    }
    else{
        cout << "Player loses" << "\n\n";
    }

    return 0;
}