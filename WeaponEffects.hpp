#pragma once

#include "SerializableEnum.hpp"
#include "Math.hpp"

SERIALIZABLE_ENUM (WeaponEffects, short, HighBit<short>,

    WE_BALANCE        = 1 << 0,
    WE_AIR_WAVE       = 1 << 1,
    WE_TRUE_MUSOU     = 1 << 2,
    WE_ARROW_SIGHT    = 1 << 3,
    WE_BERSERK        = 1 << 4,
    WE_RENBU_SPIRIT   = 1 << 5,
    WE_CONCENTRATION  = 1 << 6,
    WE_FLASH          = 1 << 7,
    WE_MYSTIC_SEAL    = 1 << 8,
    WE_LEECH          = 1 << 9

);