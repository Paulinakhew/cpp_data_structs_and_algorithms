//
// Created by Paulina Khew on 2020-03-04.
//

#include "print_execution_time.hpp"
using namespace std;

void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    auto execution_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    auto execution_time_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    auto execution_time_sec = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
    auto execution_time_min = std::chrono::duration_cast<std::chrono::minutes>(end_time - start_time).count();
    auto execution_time_hour = std::chrono::duration_cast<std::chrono::hours>(end_time - start_time).count();

    cout << "\nExecution Time: ";
    if(execution_time_hour > 0)
        cout << "" << execution_time_hour << " Hours, ";
    if(execution_time_min > 0)
        cout << "" << execution_time_min % 60 << " Minutes, ";
    if(execution_time_sec > 0)
        cout << "" << execution_time_sec % 60 << " Seconds, ";
    if(execution_time_ms > 0)
        cout << "" << execution_time_ms % long(1E+3) << " MicroSeconds, ";
    if(execution_time_ns > 0)
        cout << "" << execution_time_ns % long(1E+6) << " NanoSeconds, ";
}
