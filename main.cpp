//Using SDL and standard IO

#include "Renderer.hpp"
#include <stdio.h>

int main( int argc, char* args[] )
{
    try
    {
        Renderer::init(640, 480);
        Renderer::clear();
        Renderer::present();
        SDL_Delay(5000);
        Renderer::destroy();
    }
    catch (std::runtime_error e)
    {
        perror(e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}