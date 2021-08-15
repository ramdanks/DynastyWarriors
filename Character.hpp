#pragma once

#include "CharacterID.hpp"
#include "SpecialAttacks.hpp"
#include "Kingdom.hpp"

#include <string_view>

struct Character
{
    enum CharacterID id;
    enum Kingdom kingdom;
    enum SpecialAttacks specialAttacks;
    
    constexpr Character() = delete;
    constexpr Character(const Character& character) noexcept = default;
    constexpr Character(Character&& character) noexcept = default;
    constexpr Character(enum CharacterID id, enum Kingdom kingdom, enum SpecialAttacks specialAttacks) noexcept
    : id(id), kingdom(kingdom), specialAttacks(specialAttacks)
    {}

    constexpr Character& operator=(const Character& character) noexcept = default;
    constexpr Character& operator=(Character&& character) noexcept = default;
};