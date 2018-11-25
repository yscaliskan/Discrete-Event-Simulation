//
// Created by Yaşar Selçuk Çalışkan on 25.10.2018.
//

#ifndef UNTITLED1_EVENT_H
#define UNTITLED1_EVENT_H


#include "Passenger.h"

enum eventType{
    arrival = 1,
    goLuggage = 2,
    finishLuggage = 3,
    goSecurity = 4,
    board = 5
};

class Event {
public:

    int time;
    eventType type;
    Passenger* passenger;

    Event(eventType type, Passenger* passenger, int time);
};


#endif //UNTITLED1_EVENT_H
