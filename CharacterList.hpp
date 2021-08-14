#pragma once

#include "CharacterID.hpp"
#include "Character.hpp"
#include "Kingdom.hpp"
#include <array>

struct CharacterList
{
    template <class Pred>
    constexpr static auto countCharacters(Pred pred) noexcept
    {
        size_t count = 0;
        for (const auto& chara : CHARACTERS)
            if (pred(chara))
                ++count;
        return count;
    }

    template <class Pred>
    constexpr static auto fetchCharacters(Pred pred) noexcept
    {
        const auto count = countCharacters(pred);
        std::array<const Character*, count> charas;
        size_t insert = 0;
        for (const auto& chara : CHARACTERS)
            if (pred(chara))
            {
                charas[insert] = &chara;
                if (count == ++insert)
                    break;
            }
        return charas;
    }

    static constexpr std::array CHARACTERS = 
    {
        // SHU
        Character(GUAN_PING,         SHU,     TRUE_SPEED),
        Character(GUAN_YU,           SHU,     SWIFT_ATTACK),
        Character(HUANG_ZHONG,       SHU,     VOLLEY),
        Character(LIU_BEI,           SHU,     VOLLEY),
        Character(MA_CHAO,           SHU,     TRUE_SPEED),
        Character(PANG_TONG,         SHU,     ROCKFALL),
        Character(WEI_YAN,           SHU,     SWIFT_ATTACK),
        Character(YUE_YING,          SHU,     VOLLEY),
        Character(ZHANG_FEI,         SHU,     SWIFT_ATTACK),
        Character(ZHAO_YUN,          SHU,     TRUE_SPEED),
        Character(ZHUGE_LIANG,       SHU,     FIRE),
        // WEI
        Character(CAO_CAO,           WEI,     ROCKFALL),
        Character(CAO_PI,            WEI,     VOLLEY),
        Character(CAO_REN,           WEI,     SWIFT_ATTACK),
        Character(DIAN_WEI,          WEI,     SWIFT_ATTACK),
        Character(SIMA_YI,           WEI,     ROCKFALL),
        Character(XIAHOU_DUN,        WEI,     SWIFT_ATTACK),
        Character(XIAHOU_YUAN,       WEI,     VOLLEY),
        Character(XU_HUANG,          WEI,     TRUE_SPEED),
        Character(XU_ZHU,            WEI,     SWIFT_ATTACK),
        Character(ZHANG_HE,          WEI,     TRUE_SPEED),
        Character(ZHANG_LIAO,        WEI,     TRUE_SPEED),
        Character(ZHEN_JI,           WEI,     FIRE),
        // WU
        Character(GAN_NING,          WU,      TRUE_SPEED),
        Character(HUANG_GAI,         WU,      SWIFT_ATTACK),
        Character(LING_TONG,         WU,      TRUE_SPEED),
        Character(LU_MENG,           WU,      ROCKFALL),
        Character(LU_XUN,            WU,      FIRE),
        Character(SUN_CE,            WU,      SWIFT_ATTACK),
        Character(SUN_JIAN,          WU,      SWIFT_ATTACK),
        Character(SUN_QUAN,          WU,      VOLLEY),
        Character(SUN_SHANG_XIANG,   WU,      VOLLEY),
        Character(TAISHI_CI,         WU,      SWIFT_ATTACK),
        Character(XIAO_QIAO,         WU,      TRUE_SPEED),
        Character(ZHOU_TAI,          WU,      TRUE_SPEED),
        Character(ZHOU_YU,           WU,      TRUE_SPEED),
        // OTHER
        Character(DIAO_CHAN,         OTHER,   TRUE_SPEED),
        Character(DONG_ZHUO,         OTHER,   SWIFT_ATTACK),
        Character(LU_BU,             OTHER,   SWIFT_ATTACK),
        Character(YUAN_SHAO,         OTHER,   VOLLEY),
        Character(ZHANG_JIAO,        OTHER,   FIRE)
    };
};