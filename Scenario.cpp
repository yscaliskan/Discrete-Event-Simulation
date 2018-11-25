//
// Created by Yaşar Selçuk Çalışkan on 26.10.2018.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Scenario.h"

Scenario::Scenario(bool firstToFly, bool noSecCheckVip, bool onlineTicketing, int numLuggageCounters,
                   int numSecCounters) : firstToFly(firstToFly), noSecCheckVip(noSecCheckVip),
                                         onlineTicketing(onlineTicketing), numLuggageCounters(numLuggageCounters),
                                         numSecCounters(numSecCounters) {
    if(firstToFly){
        luggageQueue = passenger_queue{firstToFlyQueueCompare{}};
        securityQueue = passenger_queue{firstToFlyQueueCompare{}};
    } else{
        luggageQueue = passenger_queue{eventCompare{}};
        securityQueue = passenger_queue{eventCompare{}};
    }
    time = 0;
    waitingTime = 0;
    numFlightMiss = 0;
}

void Scenario::setPassengers(const vector<Passenger *>& passengers) {
    numPassengers = passengers.size();
    for (int i=0; i<passengers.size(); i++){
        Passenger* passenger = new Passenger(*passengers[i]);
        eventQueue.push(new Event(eventType::arrival, passenger, passenger->getArrivalTime()));
    }
}

void Scenario::processEvent(const Event &event) {
    if(event.type == eventType::arrival){
        if(onlineTicketing && !event.passenger->hasLuggage()) {
            if(noSecCheckVip && event.passenger->isVip()){
                time = event.time;
                if(time > event.passenger->getBoardingTime()){
                    numFlightMiss++;
                }
            }
            else if(numSecCounters != 0){
                eventQueue.push(new Event(eventType::board, event.passenger,
                                          event.time + event.passenger->getSecurityControlTime()));
                time = event.time;
                numSecCounters--;
            }
            else{
                securityQueue.push(new Event(eventType::goSecurity, event.passenger, event.time));
                time = event.time;
            }
        }
        else if(numLuggageCounters != 0){
            eventQueue.push(new Event(eventType::finishLuggage, event.passenger,
                    event.time + event.passenger->getLuggageTime()));
            time = event.time;
            numLuggageCounters--;
        }
        else{
            luggageQueue.push(new Event(eventType::goLuggage, event.passenger, event.time));
            time = event.time;
        }
    }
    else if(event.type == eventType::goLuggage){
        if(numLuggageCounters != 0){
            eventQueue.push(new Event(eventType::finishLuggage, event.passenger,
                                      time + event.passenger->getLuggageTime()));
            numLuggageCounters--;
        }
        else{
            luggageQueue.push(new Event(eventType::goLuggage, event.passenger, event.time));
        }
    }
    else if(event.type == eventType::finishLuggage){
        if(noSecCheckVip && event.passenger->isVip()){
            time = event.time;
            numLuggageCounters++;
            waitingTime += (time - event.passenger->getArrivalTime());
            if(time > event.passenger->getBoardingTime()){
                numFlightMiss++;
            }
        }
        else if(numSecCounters != 0){
            eventQueue.push(new Event(eventType::board, event.passenger,
                    event.time + event.passenger->getSecurityControlTime()));
            time = event.time;
            numSecCounters--;
            numLuggageCounters++;
        }
        else{
            securityQueue.push(new Event(eventType::goSecurity, event.passenger, event.time));
            time = event.time;
            numLuggageCounters++;
        }
        if(!luggageQueue.empty()){
            Event* goLuggageEvent = luggageQueue.top();
            processEvent(*goLuggageEvent);
            luggageQueue.pop();
            delete goLuggageEvent;
        }
    }
    else if(event.type == eventType::goSecurity){
        if(numSecCounters != 0){
            eventQueue.push(new Event(eventType::board, event.passenger,
                    time + event.passenger->getSecurityControlTime()));
            numSecCounters--;
        }
        else{
            securityQueue.push(new Event(eventType::goSecurity, event.passenger, event.time));
        }
    }
    else if(event.type ==eventType::board){
        time = event.time;
        numSecCounters++;
        waitingTime += (time - event.passenger->getArrivalTime());
        if(time > event.passenger->getBoardingTime()){
            numFlightMiss++;
        }
        if(!securityQueue.empty()){
            Event* goSecurityEvent = securityQueue.top();
            processEvent(*goSecurityEvent);
            securityQueue.pop();
            delete goSecurityEvent;
        }
    }
}

vector<float> Scenario::runScenario() {
    while(!eventQueue.empty()){
        Event* event = eventQueue.top();
        processEvent(*event);
        eventQueue.pop();
        delete event;
    }
    vector<float> result;
    result.push_back((float)waitingTime/numPassengers);
    result.push_back(numFlightMiss);
    return result;
}