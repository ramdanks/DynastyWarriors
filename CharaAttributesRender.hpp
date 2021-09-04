#ifndef CHARA_ATTRIBUTES_RENDER_H
#define CHARA_ATTRIBUTES_RENDER_H

#include "Engine/Renderer.hpp"
#include "LiveCharacter.hpp"
#include "Stringify.hpp"

SDL_Color musouColor{255, 0, 127, 255};
SDL_Color lifeColor{100, 210, 255, 255};
SDL_Color attackColor{255, 128, 0, 255};
SDL_Color defenseColor{128, 255, 0, 255};
SDL_Color bgColor{32, 32, 32, 255};

void drawRect(const SDL_Rect* rect, SDL_Color color)
{
    SDL_SetRenderDrawColor(Renderer::getRenderer(), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(Renderer::getRenderer(), rect);
}

SDL_Texture* createTextureFromText(TTF_Font* font, const char* text, SDL_Color fg)
{
    SDL_Surface* surface = TTF_RenderText_Blended(font, text, fg);
    return SDL_CreateTextureFromSurface(Renderer::getRenderer(), surface);
}

void render(const LiveCharacter chara)
{
    Exp exp                             = chara.getExp();
    uint8_t level                       = exp.getLevel();
    Attributes attributes               = chara.getAttributes();
    std::string_view strTitle           = exp.getTitle();
    std::string_view strSpecialAttacks  = Stringify::SpecialAttacks[serial(chara.specialAttacks)];
    std::string_view strCharacter       = Stringify::Character[serial(chara.id)];

    static TTF_Font* font = nullptr;
    static SDL_Texture* texture1 = nullptr;
    static SDL_Texture* texture2 = nullptr;
    static SDL_Texture* texture3 = nullptr;
    static SDL_Texture* texture4 = nullptr;
    static SDL_Texture* texture5 = nullptr;
    static SDL_Texture* texture6 = nullptr;
    static SDL_Texture* texture7 = nullptr;

    if (font == nullptr)
    {
        font = TTF_OpenFont("Engine/ttf/JetBrainsMono-Regular.ttf", 40);
        SDL_assert(font != nullptr);
        texture1 = createTextureFromText(font, "Title",   {255,255,255,255});
        texture2 = createTextureFromText(font, "Exp",     {255,255,255,255});
        texture3 = createTextureFromText(font, "Life",    {255,255,255,255});
        texture4 = createTextureFromText(font, "Musou",   {255,255,255,255});
        texture5 = createTextureFromText(font, "Attack",  {255,255,255,255});
        texture6 = createTextureFromText(font, "Defense", {255,255,255,255});
        texture7 = createTextureFromText(font, "Special", {255,255,255,255});
    }

    SDL_Rect r{250,50,250,50};

    auto drawHorizontalFillBar = [](const SDL_Rect& bgRect, int fillWidth, SDL_Color bgColor, SDL_Color fgColor) {
        SDL_Rect fillRect = {bgRect.x, bgRect.y, fillWidth, bgRect.h};
        drawRect(&bgRect, bgColor);
        drawRect(&fillRect, fgColor);
    };

    auto drawText = [](SDL_Rect& rect, SDL_Texture* text) {
        SDL_QueryTexture(text, nullptr, nullptr, &rect.w, &rect.h);
        SDL_RenderCopy(Renderer::getRenderer(), text, nullptr, &rect);
    };

    
    auto* textureTitle = createTextureFromText(font, strTitle.begin(), {255,255,255,255});
    auto* textureExp   = createTextureFromText(font, "99999/99999", {255,255,255,255});
    auto* textureSpecialAttacks = createTextureFromText(font, strSpecialAttacks.begin(), {255,255,255,255});

    drawText(r, textureTitle);
    r.y += 55;
    drawText(r, textureExp);
    r.y += 55;
    drawHorizontalFillBar(r, attributes.life, bgColor, lifeColor);
    r.y += 55;
    drawHorizontalFillBar(r, attributes.musou, bgColor, musouColor);
    r.y += 55;
    drawHorizontalFillBar(r, attributes.attack, bgColor, attackColor);
    r.y += 55;
    drawHorizontalFillBar(r, attributes.defense, bgColor, defenseColor);
    r.y += 55;
    drawText(r, textureSpecialAttacks);

    r.y = 50;
    r.x = 50;
    drawText(r, texture1);
    r.y += 55;
    drawText(r, texture2);
    r.y += 55;
    drawText(r, texture3);
    r.y += 55;
    drawText(r, texture4);
    r.y += 55;
    drawText(r, texture5);
    r.y += 55;
    drawText(r, texture6);
    r.y += 55;
    drawText(r, texture7);
}

#endif