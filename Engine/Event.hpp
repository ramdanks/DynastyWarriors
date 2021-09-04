#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include <array>
#include <algorithm>

template <std::size_t Size>
class Event
{
private:
    std::array<SDL_Event, Size> eventQueue;

public:
    Event() noexcept { SDL_assert(Size < 21); }
    void poll() noexcept
    {
        // ref: https://wiki.libsdl.org/SDL_PollEvent
        // ref: https://wiki.libsdl.org/SDL_Event
        // ref: https://wiki.libsdl.org/SDL_PeepEvents
        // if there's event need to process and it's a quit
        SDL_PeepEvents(eventQueue.begin(), static_cast<int>(Size), SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT);
        SDL_PumpEvents();
    }
    int findEvent(Uint32 type) const
    {
        const auto it = std::find_if(begin(eventQueue), end(eventQueue), [&](const SDL_Event& e){ return e.type == type; });
        if (it != end(eventQueue))
            return static_cast<int>(it - begin(eventQueue));
        return -1;
    }
    void dispatch() {}
};


#endif