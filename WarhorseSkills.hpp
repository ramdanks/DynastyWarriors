#pragma once

#include "SerializeEnum.hpp"
#include "Math.hpp"

enum WarhorseSkills : char
{
    ARROW_DANCE  = 1 << 0,
    RENBU_GAIT   = 1 << 1,
    FIND_SADDLE  = 1 << 2,
    FIND_WEAPON  = 1 << 3,
    MUSOU_SPIRIT = 1 << 4
};

SERIALIZE(WarhorseSkills, HighBit<char>)