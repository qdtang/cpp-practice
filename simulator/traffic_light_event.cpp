#include "traffic_light_event.h"
#include <iostream>

void RedLightOnEvent::processEvent()
{
    std::cout << "Red light on at " << time << "\n";
    tls.scheduleEvent(new RedLightOffEvent(time + 30, tls));
}

void RedLightOffEvent::processEvent()
{
    std::cout << "Red light off at " << time << "\n";
    tls.scheduleEvent(new YellowLightOnEvent(time, tls));
    tls.scheduleEvent(new YellowLightOffEvent(time + 3, tls));
    tls.scheduleEvent(new GreenLightOnEvent(time + 3, tls));
}

void YellowLightOnEvent::processEvent()
{
    std::cout << "Yellow light on at " << time << "\n";
}

void YellowLightOffEvent::processEvent()
{
    std::cout << "Yellow light off at " << time << "\n";
}

void GreenLightOnEvent::processEvent()
{
    std::cout << "Green light on at " << time << "\n";
    tls.scheduleEvent(new GreenLightOffEvent(time + 20, tls));
}

void GreenLightOffEvent::processEvent()
{
    std::cout << "Green light off at " << time << "\n";
    tls.scheduleEvent(new YellowLightOnEvent(time, tls));
    tls.scheduleEvent(new YellowLightOffEvent(time + 3, tls));
    tls.scheduleEvent(new RedLightOnEvent(time + 3, tls));
}
