#pragma once

#include "SerializeEnum.hpp"

enum WeaponType : char
{
    WT_STANDARD,
    WT_STRENGTH,
    WT_SKILL
};

NOSERIALIZE(WeaponType)