#pragma once

#include "SerializeEnum.hpp"

enum ElementalAffinity : char
{
    EA_FIRE,
    EA_ICE,
    EA_LIGHTNING
};

NOSERIALIZE(ElementalAffinity)