#pragma once

#include "SerializeEnum.hpp"

enum Kingdom : char
{
    SHU,
    WEI,
    WU,
    OTHER
};

NOSERIALIZE(Kingdom)