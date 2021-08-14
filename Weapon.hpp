#pragma once

#include "WeaponEffects.hpp"
#include "WeaponType.hpp"
#include "ElementalAffinity.hpp"
#include <cstdint>

struct Weapon
{
    uint8_t power;
    WeaponType type;
    ElementalAffinity affinity;
    WeaponEffects effects;
};