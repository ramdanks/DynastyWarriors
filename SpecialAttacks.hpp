#pragma once

#include "SerializeEnum.hpp"

enum SpecialAttacks : char
{
    TRUE_SPEED,
    VOLLEY,
    ROCKFALL,
    SWIFT_ATTACK,
    FIRE
};

NOSERIALIZE(SpecialAttacks)