//
// Created by chanbin on 25. 2. 27.
//

#include "../header/time.h"

std::string Time::nowDate()
{

    auto now = std::chrono::system_clock::now();
    auto today = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(now)};

    return std::format("{}-{:02d}-{:02d}",
                      static_cast<int>(today.year()),
                      static_cast<unsigned>(today.month()),
                      static_cast<unsigned>(today.day()));
}