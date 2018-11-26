#include <iostream>
#include "simulator.h"
#include "event.h"

void Simulator::run()
{
    while (!eventQueue.empty()) {
        Event* nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
        if (finishTime > 0 && time > finishTime) {
            time = finishTime;
            delete nextEvent;
            cleanupEvents();
            break;
        }
        nextEvent->processEvent();
        delete nextEvent;
    }
    std::cout << "Simulator finishes at time " << time << "\n";
}

void Simulator::cleanupEvents()
{
    while (!eventQueue.empty()) {
        Event* nextEvent = eventQueue.top();
        eventQueue.pop();
        delete nextEvent;
    }
}

bool Simulator::EventComp::operator()(const Event* e1, const Event* e2)
{
    return e1->time > e2->time;
}
