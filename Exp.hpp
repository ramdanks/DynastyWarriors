#pragma once

#include "Attributes.hpp"
#include <array>
#include <utility>
#include <string_view>

#define MKPAIR_EXP(exp, title) std::make_pair<uint32_t, std::string_view>(exp, title)

struct Exp
{
    uint32_t exp;

    constexpr Exp() noexcept : exp(0) {}
    constexpr Exp(const Exp& exp) noexcept = default;
    constexpr Exp(Exp&& exp) noexcept = default;
    constexpr Exp(uint32_t exp) noexcept : exp(exp) {}
    
    constexpr uint8_t getLevel() const noexcept
    {
        for (size_t i = 0; i < expRequirementsForLevel.size(); ++i)
            if (exp < expRequirementsForLevel[i].first)
                return i + 1;
        return expRequirementsForLevel.size() + 1;
    }
    constexpr std::string_view getTitle() const noexcept
    {
        const auto level = getLevel();
        return expRequirementsForLevel[level-1].second;
    }

    constexpr Exp& operator=(const Exp& level) noexcept = default;
    constexpr Exp& operator=(Exp&& level) noexcept = default;

    static constexpr std::array expRequirementsForLevel =
    {
        // 1000 increase
        MKPAIR_EXP(1000, "Lt General"),
        MKPAIR_EXP(2000, "Assistant General"),
        MKPAIR_EXP(3000, "Field General"),
        MKPAIR_EXP(4000, "Gate General"),
        MKPAIR_EXP(5000, ""),
        MKPAIR_EXP(6000, "Crusher General"),
        MKPAIR_EXP(7000, ""),
        MKPAIR_EXP(8000, "Guard General"),
        MKPAIR_EXP(9000, "Flying General"),
        MKPAIR_EXP(10000, "Support General"),
        MKPAIR_EXP(11000, "Order General"),
        MKPAIR_EXP(12000, "Slashing General"),
        MKPAIR_EXP(13000, "Pacifying General"),
        MKPAIR_EXP(14000, ""),
        MKPAIR_EXP(15000, "Pike General"),
        MKPAIR_EXP(16000, "Dignified General"),
        MKPAIR_EXP(17000, "Dispatch General"),
        MKPAIR_EXP(18000, "Cohort General"),
        MKPAIR_EXP(19000, ""),
        MKPAIR_EXP(20000, "Commander General"),
        // 2000 increase
        MKPAIR_EXP(22000, "Tower General"),
        MKPAIR_EXP(24000, "Moral General"),
        MKPAIR_EXP(26000, ""),
        MKPAIR_EXP(28000, "Trusted General"),
        MKPAIR_EXP(30000, "Spear General"),
        MKPAIR_EXP(32000, ""),
        MKPAIR_EXP(34000, "Resolute General"),
        MKPAIR_EXP(36000, "Enchanter General"),
        MKPAIR_EXP(38000, "Assault General"),
        MKPAIR_EXP(40000, "Tiger General"),
        MKPAIR_EXP(42000, "Ambush General"),
        MKPAIR_EXP(44000, "Left Flank General"),
        MKPAIR_EXP(46000, "Rank General"),
        MKPAIR_EXP(48000, "File General"),
        MKPAIR_EXP(50000, "Horse General"),
        // 3000 increase
        MKPAIR_EXP(53000, "Banner General"),
        MKPAIR_EXP(56000, "Lance General"),
        MKPAIR_EXP(59000, "Guardian General"),
        MKPAIR_EXP(62000, "Commandant General"),
        MKPAIR_EXP(65000, "Rising Dragon General"),
        MKPAIR_EXP(68000, "Tranquil General"),
        MKPAIR_EXP(71000, "Crown General"),
        MKPAIR_EXP(74000, "Master General"),
        MKPAIR_EXP(77000, ""),
        MKPAIR_EXP(80000, "Front General"),
        // 4000 increase
        MKPAIR_EXP(84000, ""),
        MKPAIR_EXP(88000, ""),
        MKPAIR_EXP(92000, "Cavalier General"),
        // Cap to Max Experience
        MKPAIR_EXP(99999, "Grand General"),
    };
};