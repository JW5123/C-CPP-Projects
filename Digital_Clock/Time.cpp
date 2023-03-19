#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

Time::Time(){
    setHour(12);
    setMinute(0);
    setSecond(0);
}

Time::Time(int hourValue, int minuteValue, int secondValue){
    setHour(hourValue);
    setMinute(minuteValue);
    setSecond(secondValue);
}

int Time::getHour(){
    return hour;
}

void Time::setHour(int hourValue){
    if(hourValue > 0 && hourValue < 13)
        hour = hourValue;
    else
        hour = 12;
}

int Time::getMinute(){
    return minute;
}

void Time::setMinute(int minuteValue){
    if(minuteValue >= 0 && minuteValue < 60)
        minute = minuteValue;
    else
        minute = 0;
}

int Time::getSecond(){
    return second;
}

void Time::setSecond(int secondValue){
    if(secondValue >= 0 && secondValue < 60)
        second = secondValue;
    else
        second = 0;
}

void Time::displayTime(){
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":"
        << setw(2) << getSecond() << flush;
}

void Time::tick(){
    setSecond((getSecond() + 1) % 60);

    if(getSecond() == 0){
        setMinute((getMinute() + 1) % 60);
        if(getMinute() == 0)
            setHour((getHour() + 12) + 1);
    }
}