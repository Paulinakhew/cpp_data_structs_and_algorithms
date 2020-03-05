//
// Created by Paulina Khew on 2020-03-04.
//

#ifndef CPP_LINKED_LISTS_PRINT_EXECUTION_TIME_HPP
#define CPP_LINKED_LISTS_PRINT_EXECUTION_TIME_HPP

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

void printExecutionTime(ClockTime start_time, ClockTime end_time);

#endif //CPP_LINKED_LISTS_PRINT_EXECUTION_TIME_HPP
