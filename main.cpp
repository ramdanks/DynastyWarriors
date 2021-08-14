#include "Kingdom.hpp"
#include "Stringify.hpp"
#include "LiveCharacter.hpp"
#include "CharacterList.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <utility>

void diplayDialog(Character chara)
{
    const auto idx = serial(chara.id);
    puts(Stringify::Character[idx].begin());
}

int main(int argc, char* argv[])
{
    CharacterID effects = static_cast<CharacterID>(argc);
    auto idx = serial(effects);
    puts(Stringify::Character[idx].begin());
}