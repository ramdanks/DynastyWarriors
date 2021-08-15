#pragma once

#include "WeaponEffects.hpp"
#include "WeaponType.hpp"
#include "ElementalAffinity.hpp"
#include <cstdint>

struct Weapon
{
    uint8_t power;
    enum WeaponType type;
    enum ElementalAffinity affinity;
    enum WeaponEffects effects;
};