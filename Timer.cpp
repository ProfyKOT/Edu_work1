#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

class Timer {
public:
    bool start() {
        isStarted = true;
        this->startTime = time(NULL);
        return true;
    }
    bool stop() {
        if (isStarted == false) {
            return false;
        }
        this->isStarted = false;
        this->endTime = time(NULL);
        return true;
    }
    bool save() {
        this->value = this->endTime - this->startTime;
        return true;
    }
    bool reset() {
        this->isStarted = false;
        this->startTime = 0;
        this->endTime = 0;
        this->value = 0;
        return true;
    }
    struct tm get() {
        localtime_s(&this->timeStruct, &this->value);
        this->timeStruct.tm_hour -= 3;
        return this->timeStruct;
    }
private:
    bool isStarted = false;
    time_t startTime = 0;
    time_t endTime = 0;
    time_t value = 0;
    struct tm timeStruct;
};


ostream& operator << (ostream& out, Timer& timer) //Вывод
{
    tm dataTimer = timer.get();
    out << "Current time: " << dataTimer.tm_hour << ":" << dataTimer.tm_min << ":" << dataTimer.tm_sec << endl;
    return out;
}
