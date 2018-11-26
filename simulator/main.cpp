#include <iostream>
#include "traffic_light_simulator.h"
#include "traffic_light_event.h"

int main()
{
    TrafficLightSimulator tls{100};
    tls.scheduleEvent(new RedLightOnEvent(0, tls));
    tls.run();
    return 0;
}
