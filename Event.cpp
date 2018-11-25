//
// Created by Yaşar Selçuk Çalışkan on 25.10.2018.
//

#include "Event.h"

Event::Event(eventType type, Passenger *passenger, int time) {
    this->type= type;
    this->passenger = passenger;
    this->time = time;
}
