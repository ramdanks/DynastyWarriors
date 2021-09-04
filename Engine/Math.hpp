#pragma once

#include <cstdint>

constexpr static int table[64] = {
    0, 58, 1, 59, 47, 53, 2, 60, 39, 48, 27, 54, 33, 42, 3, 61,
    51, 37, 40, 49, 18, 28, 20, 55, 30, 34, 11, 43, 14, 22, 4, 62,
    57, 46, 52, 38, 26, 32, 41, 50, 36, 17, 19, 29, 10, 13, 21, 56,
    45, 25, 31, 35, 16, 9, 12, 44, 24, 15, 8, 23, 7, 6, 5, 63 
};

constexpr int LogBase2(uint64_t n) noexcept
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return table[(n * 0x03f6eaf2cd271461) >> 58];
}

// find first occurences of high bit in the data
// if not found (n == 0) return -1;
template <typename T>
constexpr int HighBit(T n) noexcept
{
    int count = 0;
    if (n == 0) return -1;
    for (T i = 1; i != n; i <<= 1, ++count);
    return count;
}