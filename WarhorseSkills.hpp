#pragma once

#include "Engine/SerializableEnum.hpp"
#include "Engine/Math.hpp"

SERIALIZABLE_ENUM (WarhorseSkills, char, HighBit<char>,

    ARROW_DANCE  = 1 << 0,
    RENBU_GAIT   = 1 << 1,
    FIND_SADDLE  = 1 << 2,
    FIND_WEAPON  = 1 << 3,
    MUSOU_SPIRIT = 1 << 4

)