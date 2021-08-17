#ifndef RENDERER_H
#define RENDERER_H

#include "Config.hpp"
#include "Ticks.hpp"
#include <utility>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdexcept>

class Renderer
{
public:
    Renderer() = delete;
    Renderer(const Renderer& other) = delete;
    Renderer(Renderer&& other) = delete;
    
    static void init(int screenWidth, int screenHeight)
    {
        if (TTF_Init() != 0)
            throw std::runtime_error(TTF_GetError());

        font = TTF_OpenFont(TTF_PATH, 14);
        SDL_assert(font != nullptr);

        if (SDL_Init( SDL_INIT_EVERYTHING ) < 0)
            throw std::runtime_error(SDL_GetError());
        window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (window == nullptr)
            throw std::runtime_error(SDL_GetError());
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr)
            throw std::runtime_error(SDL_GetError());    
    }
    static void debug(Ticks ticks) noexcept
    {
        char buf[20];
        double ftime = convert<double>(ticks, MILLI);
        snprintf(buf, sizeof(buf), "frametime: %.2lf ms", ftime);

        // as TTF_RenderText_Solid could only be used on
        // SDL_Surface then you have to create the surface first
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, buf, {255, 255, 255}); 
        SDL_assert(surfaceMessage != nullptr);

        // now you can convert it into a texture
        SDL_Texture* msgTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_assert(msgTexture != nullptr);

        SDL_Rect msgRect; //create a rect
        msgRect.x = 0;  //controls the rect's x coordinate 
        msgRect.y = 0; // controls the rect's y coordinte
        msgRect.w = surfaceMessage->w; // controls the width of the rect
        msgRect.h = surfaceMessage->h; // controls the height of the rect

        render(msgTexture, &msgRect);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(msgTexture);
    }
    static inline bool render(SDL_Texture* texture, const SDL_Rect* rect) noexcept
    {
        return SDL_RenderCopy(renderer, texture, nullptr, rect) == 0;
    }
    static inline SDL_Texture* createTextureFromSurface(SDL_Surface* surface) noexcept
    {
        return SDL_CreateTextureFromSurface(renderer, surface);
    }
    static inline void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
    }
    static inline void clear() noexcept
    {
        SDL_RenderClear(renderer);
    }
    static void present() noexcept
    {
        SDL_RenderPresent(renderer);
    }
    static void destroy() noexcept
    {
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    static inline int64_t ticks;
    static inline TTF_Font* font;
    static inline SDL_Window* window = nullptr;
    static inline SDL_Renderer* renderer = nullptr;
};

#endif