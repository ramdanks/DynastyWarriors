#include "Kingdom.hpp"
#include "Stringify.hpp"
#include "LiveCharacter.hpp"
#include "CharacterList.hpp"
#include "Weapon.hpp"
#include "ThreadPool.hpp"
#include <iostream>

bool isMePrime = false;

constexpr bool isPrime(uint64_t value) noexcept
{
    if (value == 0 || value == 1)
        return false;
    if (value == 2)
        return true;
    for (uint64_t i = 3; i != value / 2; ++i)
        if (value % i == 0)
            return false;
    return true;
}

int main(int argc, char* argv[])
{
    ThreadPool* tpool = new ThreadPool();
    
    tpool->dispatch([&]{
        long long value = std::atoll(argv[1]);
        isMePrime = isPrime(value);
    });

    puts("DW6 Chara");

    uint read = 0;
    while (scanf("%u", &read) && read != 0)
    {
        // if guard statement, prevent to run further instructions
        if (read >= CharacterList::CHARACTERS.size()) continue;

        const Character chara = CharacterList::CHARACTERS[read];
        printf("%s, %s, %s\n",
            Stringify::Character[serial(chara.id)].begin(),
            Stringify::Kingdom[serial(chara.kingdom)].begin(),
            Stringify::SpecialAttacks[serial(chara.specialAttacks)].begin()
        );
    }

    delete tpool;
    puts(isMePrime ? "true" : "false");
}