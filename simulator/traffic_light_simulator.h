#ifndef TRAFFIC_LIGHT_SIMULATOR_H
#define TRAFFIC_LIGHT_SIMULATOR_H

#include "simulator.h"

class TrafficLightSimulator : public Simulator
{
public:
    explicit TrafficLightSimulator(uint64_t ft) : Simulator(ft) {}
};


#endif // TRAFFIC_LIGHT_SIMULATOR_H
