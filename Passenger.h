//
// Created by Yaşar Selçuk Çalışkan on 25.10.2018.
//

#ifndef UNTITLED1_PASSENGER_H
#define UNTITLED1_PASSENGER_H

#include "vector"

using namespace std;

class Passenger {
private:
    int arrivalTime;
    int boardingTime;
    int luggageTime;
    int securityControlTime;
    bool vip;
    bool luggage;
public:
    Passenger(const vector<string> passenger_features);

    virtual ~Passenger();

    Passenger(const Passenger& _passenger);

    Passenger& operator=(const Passenger& passenger);

    int getArrivalTime() const;

    void setArrivalTime(int arrivalTime);

    int getBoardingTime() const;

    void setBoardingTime(int boardingTime);

    int getLuggageTime() const;

    void setLuggageTime(int luggageTime);

    int getSecurityControlTime() const;

    void setSecurityControlTime(int securityControlTime);

    bool isVip() const;

    void setVip(bool _vip);

    bool hasLuggage() const;

    void setLuggage(bool _luggage);
};


#endif //UNTITLED1_PASSENGER_H
