//
// Created by Yaşar Selçuk Çalışkan on 26.10.2018.
//

#ifndef UNTITLED1_SCENARIO_H
#define UNTITLED1_SCENARIO_H


#include <queue>
#include "Passenger.h"
#include "Event.h"

using namespace std;


//also compare the event types
struct eventCompare{
    bool operator()(const Event* a, const Event* b){
        if(a->time == b->time){
            if(a->type == b->type){
                return a->passenger->getArrivalTime() > b->passenger->getArrivalTime();
            }
            return a->type < b->type;
        }
        return a->time > b->time;
    }
};
struct firstToFlyQueueCompare{
    bool operator()(const Event* a, const Event* b){
        if(a->passenger->getBoardingTime() == b->passenger->getBoardingTime()){
            return a->passenger->getArrivalTime() > b->passenger->getArrivalTime();
        }
        return a->passenger->getBoardingTime() > b->passenger->getBoardingTime();
    }
};
class Scenario {
public:

    Scenario(bool firstToFly, bool noSecCheckVip, bool onlineTicketing, int numLuggageCounters, int numSecCounters);
    void setPassengers(const vector<Passenger*>& passengers);
    vector<float> runScenario();
    void processEvent(const Event& event);

private:
    int time;
    long waitingTime;
    int numFlightMiss;
    bool firstToFly;
    bool noSecCheckVip;
    bool onlineTicketing;
    int numLuggageCounters;
    int numSecCounters;
    int numPassengers;
    priority_queue<Event*, vector<Event*>, eventCompare> eventQueue;
    typedef priority_queue<Event*, vector<Event*>, function<bool(Event const*, Event const*)>> passenger_queue;
    passenger_queue luggageQueue;
    passenger_queue securityQueue;
};


#endif //UNTITLED1_SCENARIO_H
