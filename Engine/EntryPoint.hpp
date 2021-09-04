#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef _WIN32
    #include <direct.h>
    #define GetCurrentDir _getcwd
#elif __linux__
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

#include "App.hpp"
#include "Renderer.hpp"
#include "Timer.hpp"
#include "Event.hpp"
#include <stdio.h>
#include <SDL2/SDL_image.h>

extern App* CreateApp();

#define IMPLEMENT_APP(appname) \
    App* CreateApp() { return new appname(); }

std::string_view getCwd()
{
    static char buf[FILENAME_MAX];
    GetCurrentDir(buf, sizeof(buf));
    return buf;
}

int main(int argc, const char* argv[])
{
    Timer timer;
    int64_t ticks = 0;
    App* app = nullptr;
    Event<5u> event;
    
    try
    {
        app = CreateApp();
        app->onInit();
        Renderer::init(640, 480);
        while (event.poll(), event.findEvent(SDL_QUIT) == -1)
        {
            Renderer::clear();
            app->onLoop(ticks);
            Renderer::debug(ticks);
            Renderer::present();
            ticks = timer.toc();
            timer.tic();
        }
        app->onExit();
    }
    catch (std::runtime_error& e)
    {
        perror(e.what());
        return EXIT_FAILURE;
    }

    delete app;
    Renderer::destroy();

    return EXIT_SUCCESS;
}

#endif