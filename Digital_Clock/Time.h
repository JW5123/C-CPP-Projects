#ifndef TIME_H
#define TIME_H

class Time {
    public:
        Time();
        Time(int, int, int);
        void displayTime();
        void tick();

        int getHour();
        int getMinute();
        int getSecond();

        void setHour(int);
        void setMinute(int);
        void setSecond(int);

    private:
        int hour;
        int minute;
        int second;
};
#endif