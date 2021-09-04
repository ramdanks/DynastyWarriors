#include "Engine/Engine.hpp"
#include "Attributes.hpp"
#include "LiveCharacter.hpp"
#include "CharacterList.hpp"
#include "CharaAttributesRender.hpp"
#include <iostream>

class Sandbox : public App
{
public:
    bool onInit() override
    {
        return true;
    }
    bool onExit() override
    {
        return true;
    }
    bool onLoop(Ticks ticks) override
    {
        Renderer::clear(0, 0, 0, 0);

        constexpr LiveCharacter chara(
            CharacterList::CHARACTERS[serial(CAO_CAO)],
            99999,
            {26, 29, 27, 27},
            0.15
        );

        render(chara);

        return true;
    }
};

IMPLEMENT_APP(Sandbox)