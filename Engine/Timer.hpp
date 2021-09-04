#ifndef TIMER_H
#define TIMER_H

#include <chrono>

using namespace std::chrono;

struct Timer
{
    void inline tic() noexcept
    {
        start = high_resolution_clock::now();
    }

    nanoseconds::rep inline toc() const noexcept
    {
        const auto now = high_resolution_clock::now() - start;
        return now.count();
    }

private:
    high_resolution_clock::time_point start;
};

#endif