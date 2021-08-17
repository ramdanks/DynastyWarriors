#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <stdexcept>

class Renderer
{
public:
    static void init(int screenWidth, int screenHeight)
    {
        if (SDL_Init( SDL_INIT_EVERYTHING ) < 0)
            throw std::runtime_error(SDL_GetError());
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if (window == nullptr)
            throw std::runtime_error(SDL_GetError());
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr)
            throw std::runtime_error(SDL_GetError());
    }
    static void inline clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
    }
    static void inline clear()
    {
        SDL_RenderClear(renderer);
    }
    static void inline present()
    {
        SDL_RenderPresent(renderer);
    }
    static void inline destroy()
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    static inline SDL_Window* window = nullptr;
    static inline SDL_Renderer* renderer = nullptr;
};

#endif