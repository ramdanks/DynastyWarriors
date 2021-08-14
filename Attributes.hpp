#pragma once

#include <cstdint>

using val_t = uint8_t;

struct Attributes
{
    val_t life;
    val_t musou;
    val_t attack;
    val_t defense;

    constexpr Attributes() noexcept
    : life(0), musou(0), attack(0), defense(0)
    {}
    constexpr Attributes(const Attributes& other) noexcept = default;
    constexpr Attributes(Attributes&& other) noexcept = default;
    constexpr Attributes(val_t life, val_t musou, val_t attack, val_t defense) noexcept
    : life(life), musou(musou), attack(attack), defense(defense)
    {}

    template <typename T>
    constexpr Attributes operator+(T factor) const noexcept                { return add(factor); }
    constexpr Attributes operator+(const Attributes& other) const noexcept { return add(other); }
    template <typename T>
    constexpr Attributes operator-(T factor) const noexcept                { return sub(factor); }
    constexpr Attributes operator-(const Attributes& other) const noexcept { return sub(other); }
    template <typename T>
    constexpr Attributes operator*(T factor) const noexcept                { return mul(factor); }
    constexpr Attributes operator*(const Attributes& other) const noexcept { return mul(other); }
    template <typename T>
    constexpr Attributes operator/(T factor) const noexcept                { return div(factor); }
    constexpr Attributes operator/(const Attributes& other) const noexcept { return div(other); }
    
    constexpr Attributes& operator=(const Attributes& other) noexcept = default;
    constexpr Attributes& operator=(Attributes&& other) noexcept = default;

private:
    template <typename T>
    constexpr Attributes add(T factor) const noexcept
    { 
        return Attributes(
            static_cast<T>(life) + factor,
            static_cast<T>(musou) + factor,
            static_cast<T>(attack) + factor,
            static_cast<T>(defense) + factor
        );
    }
    constexpr Attributes add(const Attributes& other) const noexcept
    { 
        return Attributes(
            life + other.life,
            musou + other.musou,
            attack + other.attack,
            defense + other.defense
        ); 
    }
    template <typename T>
    constexpr Attributes sub(T factor) const noexcept
    { 
        return Attributes(
            static_cast<T>(life) - factor,
            static_cast<T>(musou) - factor,
            static_cast<T>(attack) - factor,
            static_cast<T>(defense) - factor
        );
    }
    constexpr Attributes sub(const Attributes& other) const noexcept
    { 
        return Attributes(
            life - other.life,
            musou - other.musou,
            attack - other.attack,
            defense - other.defense
        ); 
    }
    template <typename T>
    constexpr Attributes mul(T factor) const noexcept
    { 
        return Attributes(
            static_cast<T>(life) * factor,
            static_cast<T>(musou) * factor,
            static_cast<T>(attack) * factor,
            static_cast<T>(defense) * factor
        );
    }
    constexpr Attributes mul(const Attributes& other) const noexcept
    { 
        return Attributes(
            life * other.life,
            musou * other.musou,
            attack * other.attack,
            defense * other.defense
        ); 
    }
    template <typename T>
    constexpr Attributes div(T factor) const noexcept
    { 
        return Attributes(
            static_cast<T>(life) / factor,
            static_cast<T>(musou) / factor,
            static_cast<T>(attack) / factor,
            static_cast<T>(defense) / factor
        );
    }
    constexpr Attributes div(const Attributes& other) const noexcept
    { 
        return Attributes(
            life / other.life,
            musou / other.musou,
            attack / other.attack,
            defense / other.defense
        ); 
    }
};