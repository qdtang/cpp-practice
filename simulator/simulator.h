#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <cstdint>
#include <queue>
#include <vector>

class Event;

class Simulator
{
public:
    explicit Simulator(uint64_t ft = 0) : finishTime(ft) {}
    virtual ~Simulator() = default;
    void run();
    uint64_t currentTime() const {return time;}
    uint64_t getFinishTime() const {return finishTime;}
    void scheduleEvent(Event* e) {eventQueue.push(e);}
private:
    void cleanupEvents();

    struct EventComp {
        bool operator() (const Event* e1, const Event* e2);
    };
    using EventQueue = std::priority_queue<Event*, std::vector<Event*>, EventComp>;

    uint64_t time = 0;
    uint64_t finishTime; // 0 indicates the simulator won't stop until all events are processed.
    EventQueue eventQueue;

};

#endif // SIMULATOR_H
