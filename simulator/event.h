#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
class Simulator;

class Event
{
public:
    explicit Event(uint64_t t) : time(t) {}
    virtual ~Event() = default;
    virtual void processEvent() = 0;

    const uint64_t time;
};

#endif // EVENT_H
