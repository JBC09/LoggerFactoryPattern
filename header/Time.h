//
// Created by chanbin on 25. 2. 27.
//


#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <chrono>
#include <format>

class Time
{
public:

    Time();
    ~Time();

    static std::string nowDate();

};

#endif //TIME_H
