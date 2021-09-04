#ifndef TICKS_H
#define TICKS_H

#include "Timer.hpp"

using Ticks = nanoseconds::rep;

enum Period
{
    NANO,
    MICRO,
    MILLI,
    SECOND
};

template <typename R>
constexpr R convert(Ticks ticks, Period period) noexcept
{
    switch (period)
    {
    case NANO:   return static_cast<R>(1) * ticks;
    case MICRO:  return static_cast<R>(1) * ticks / 1e3;
    case MILLI:  return static_cast<R>(1) * ticks / 1e6;
    case SECOND: return static_cast<R>(1) * ticks / 1e9;
    }
    return static_cast<R>(0);
}

template <typename R>
constexpr R getFps(Ticks ticks) noexcept
{
    return static_cast<R>(1e9) / ticks;
}

#endif