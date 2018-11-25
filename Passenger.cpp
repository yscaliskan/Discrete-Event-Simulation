//
// Created by Yaşar Selçuk Çalışkan on 25.10.2018.
//

#include <string>
#include <iostream>
#include "Passenger.h"

using namespace std;

Passenger::Passenger(const vector<string> passenger_features) {

    arrivalTime = stoi(passenger_features[0]);
    boardingTime = stoi(passenger_features[1]);
    luggageTime = stoi(passenger_features[2]);
    securityControlTime = stoi(passenger_features[3]);
    if(passenger_features[4] == "V") vip = true;
    else vip = false;
    if(passenger_features[5] == "L") luggage = true;
    else luggage = false;
}

Passenger::Passenger(const Passenger &passenger) {
    arrivalTime = passenger.arrivalTime;
    boardingTime = passenger.boardingTime;
    luggageTime = passenger.luggageTime;
    securityControlTime = passenger.securityControlTime;
    vip = passenger.vip;
    luggage = passenger.luggage;
}

Passenger& Passenger::operator=(const Passenger &passenger) {
    arrivalTime = passenger.arrivalTime;
    boardingTime = passenger.boardingTime;
    luggageTime = passenger.luggageTime;
    securityControlTime = passenger.securityControlTime;
    vip = passenger.vip;
    luggage = passenger.luggage;
    return (*this);
}

int Passenger::getArrivalTime() const {
    return arrivalTime;
}

void Passenger::setArrivalTime(int arrivalTime) {
    Passenger::arrivalTime = arrivalTime;
}

int Passenger::getBoardingTime() const {
    return boardingTime;
}

void Passenger::setBoardingTime(int boardingTime) {
    Passenger::boardingTime = boardingTime;
}

int Passenger::getLuggageTime() const {
    return luggageTime;
}

void Passenger::setLuggageTime(int luggageTime) {
    Passenger::luggageTime = luggageTime;
}

int Passenger::getSecurityControlTime() const {
    return securityControlTime;
}

void Passenger::setSecurityControlTime(int securityControlTime) {
    Passenger::securityControlTime = securityControlTime;
}

bool Passenger::isVip() const {
    return vip;
}

void Passenger::setVip(bool vip) {
    Passenger::vip = vip;
}

bool Passenger::hasLuggage() const {
    return luggage;
}

void Passenger::setLuggage(bool luggage) {
    Passenger::luggage = luggage;
}

Passenger::~Passenger() {

}
