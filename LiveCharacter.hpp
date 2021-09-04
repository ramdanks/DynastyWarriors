#pragma once

#include "Character.hpp"
#include "Attributes.hpp"
#include "Exp.hpp"
#include <memory>

class LiveCharacter : public Character
{
private:
    Exp exp;
    Attributes initialAttributes;
    float attributesGain;

public:
    constexpr LiveCharacter() = delete;
    constexpr LiveCharacter(const Character& character, const Exp& exp, 
        const Attributes& initialAttributes, float attributesGain) noexcept
        : Character(character), exp(exp), initialAttributes(initialAttributes), attributesGain(attributesGain)
    {}
    constexpr LiveCharacter(const LiveCharacter& other) noexcept = default;
    constexpr LiveCharacter(LiveCharacter&& other) noexcept = default;
    
    constexpr Exp getExp() const noexcept { return exp; }
    constexpr Attributes getAttributes() const noexcept
    { 
        const auto level = exp.getLevel();
        if (level == 1) return initialAttributes;
        return initialAttributes + initialAttributes * (attributesGain * (level - 1.0)); 
    }
    constexpr Attributes getInitialAttributes() const noexcept { return initialAttributes; }

    constexpr LiveCharacter& operator=(const LiveCharacter& other) noexcept = default;
    constexpr LiveCharacter& operator=(LiveCharacter&& other) noexcept = default;
};