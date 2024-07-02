#include <ctime>
#include <iostream>

class Time{
public:
    void acquireTime();
    long getTimep();
    void judge();
};

long Time::getTimep() {
    time_t timep;
    return time(&timep);
}

void Time::acquireTime()
{
    time_t timep;
    time(&timep); //获取从1970至今过了多少秒，存入time_t类型的timep
    printf("%s", ctime(&timep));//用ctime将秒数转化成字符串格式，输出：Thu Feb 28 14:14:17 2019
}