#ifndef CONCRET_EVENT_H
#define CONCRET_EVENT_H

#include "event.h"
#include "traffic_light_simulator.h"

class TrafficLightEvent : public Event
{
public:
    TrafficLightEvent(uint64_t t, TrafficLightSimulator& s) :
        Event(t), tls(s) {}
protected:
    TrafficLightSimulator& tls;
};

class RedLightOnEvent : public TrafficLightEvent
{
public:
    RedLightOnEvent(uint64_t t, TrafficLightSimulator& s) :
        TrafficLightEvent(t, s){}
    virtual void processEvent() override;
};

class RedLightOffEvent : public TrafficLightEvent
{
public:
    RedLightOffEvent(uint64_t t, TrafficLightSimulator& s) :
        TrafficLightEvent(t, s) {}
    virtual void processEvent() override;
};

class YellowLightOnEvent : public TrafficLightEvent
{
public:
    enum Direction {ToGreen, ToRed};
    YellowLightOnEvent(uint64_t t, TrafficLightSimulator& s) :
        TrafficLightEvent (t, s) {}
    virtual void processEvent() override;
};

class YellowLightOffEvent : public TrafficLightEvent
{
public:
    YellowLightOffEvent(uint64_t t, TrafficLightSimulator& s) :
        TrafficLightEvent (t, s) {}
    virtual void processEvent() override;
};

class GreenLightOnEvent : public TrafficLightEvent
{
public:
    GreenLightOnEvent(uint64_t t, TrafficLightSimulator& s) :
        TrafficLightEvent (t, s) {}
    virtual void processEvent() override;
};

class GreenLightOffEvent : public TrafficLightEvent
{
public:
    GreenLightOffEvent(uint64_t t, TrafficLightSimulator& s) :
        TrafficLightEvent (t, s) {}
    virtual void processEvent() override;
};
#endif // CONCRET_EVENT_H
