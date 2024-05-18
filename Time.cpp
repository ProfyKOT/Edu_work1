#include <iostream>

using namespace std;

class Time {
public:
    Time(int seconds,int minutes,int hours) {
        this->seconds = seconds;
        this->minutes = minutes;
        this->hours = hours;
    }
    bool changeFormat() {
        if (this->hours > 12) {
            this->isPm = true;
            this->hours -= 12;
            this->isEng = true;
        }
        else {
            this->isEng = true;
        }
        return true;
    }
    int getSeconds() {
        return this->seconds;
    }
    int getMinutes() {
        return this->minutes;
    }
    int getHours() {
        return this->hours;
    }
    string getPmAm() {
        if (isEng) {
            if (isPm) {
                return "pm";
            }
            else {
                return "am";
            }
        }
        else {
            return "";
        }
    }
    int setSeconds(int seconds) {
        this->seconds = seconds;
        return this->seconds;
    }
    int setMinutes(int minutes) {
        this->minutes = minutes;
        return this->minutes;
    }
    int setHours(int hours) {
        this->hours = hours;
        return this->hours;
    }
    Time operator + (Time otherTime)
    {
        tempSeconds = seconds + otherTime.getSeconds();
        tempMinutes = minutes + otherTime.getMinutes();
        tempHours = hours + otherTime.getHours();
        return Time{ tempSeconds,tempMinutes,tempHours };
    }
    Time operator += (Time otherTime)
    {
        this->seconds = seconds + otherTime.getSeconds();
        this->minutes = minutes + otherTime.getMinutes();
        this->hours = hours + otherTime.getHours();
        return Time{ this->seconds,this->minutes,this->hours };
    }
    Time operator - (Time otherTime)
    {
        tempSeconds = seconds - otherTime.getSeconds();
        tempMinutes = minutes - otherTime.getMinutes();
        tempHours = hours - otherTime.getHours();
        return Time{ tempSeconds,tempMinutes,tempHours };
    }
    Time operator -= (Time otherTime)
    {
        this->seconds = seconds - otherTime.getSeconds();
        this->minutes = minutes - otherTime.getMinutes();
        this->hours = hours - otherTime.getHours();
        return Time{ this->seconds,this->minutes,this->hours };
    }
    bool operator < (Time otherTime)
    {
        if (hours < otherTime.getHours()) {
            return true;
        }
        else if (minutes < otherTime.getMinutes()) {
            return true;
        }
        else if (seconds < otherTime.getSeconds()) {
            return true;
        }
        return false;
    }
    bool operator > (Time otherTime)
    {
        if (hours > otherTime.getHours()) {
            return true;
        }
        else if (minutes > otherTime.getMinutes()) {
            return true;
        }
        else if (seconds > otherTime.getSeconds()) {
            return true;
        }
        return false;
    }
    bool operator == (Time otherTime)
    {
        if ((hours == otherTime.getHours()) && (minutes == otherTime.getMinutes()) && (seconds == otherTime.getSeconds())) {
            return true;
        }
        return false;
    }
    bool operator != (Time otherTime)
    {
        if ((hours == otherTime.getHours()) && (minutes == otherTime.getMinutes()) && (seconds == otherTime.getSeconds())) {
            return false;
        }
        return true;
    }


private:
    int minutes = 0;
    int seconds = 0;
    int hours = 0;

    int tempMinutes = 0;
    int tempSeconds = 0;
    int tempHours = 0;

    bool isEng = false;
    bool isPm = false;

};


istream& operator >> (istream& input, Time& otherTime) //Ввод
{
    int hours;
    int minutes;
    int seconds;
    input >> hours;
    input >> minutes;
    input >> seconds;
    otherTime.setSeconds(seconds);
    otherTime.setMinutes(minutes);
    otherTime.setHours(hours);
    return input;
}
ostream& operator << (ostream& out, Time otherTime) //Вывод
{
    out << "Hours: " << otherTime.getHours() << "\t";
    out << "Minutes: " << otherTime.getMinutes() << "\t";
    out << "Seconds: " << otherTime.getSeconds() << "\t";
    out << otherTime.getPmAm() << "\t";
    return out;
}
