#ifndef APP_H
#define APP_H

#include "Ticks.hpp"

class App
{
protected:
    App() {}
    App(const App& other) = delete;
    App(App&& other) = delete;

public:
    virtual ~App() noexcept {}

    virtual bool onInit() = 0;
    virtual bool onExit() = 0;
    virtual bool onLoop(Ticks ticks) = 0;

private:
    App& operator=(const App& other) = delete;
    App& operator=(App&& other) = delete;
};

#endif