//
// Created by Yaşar Selçuk Çalışkan on 26.10.2018.
//

#ifndef UNTITLED1_SIMULATION_H
#define UNTITLED1_SIMULATION_H


#include "Passenger.h"
#include "Scenario.h"

class Simulation {
private:
    int numPassengers;
    int numLuggageCounters;
    int numSecCounters;
    vector<Passenger*> passengers;
    vector<Scenario*> scenarios;
    vector<vector<float>> results;
public:
    void runSimulation(char* argv[]);
    void readInput(char* argv);
    void fillScenarios();
    void writeOutput(char* outputFile, const vector<vector<float>>& results);
};


#endif //UNTITLED1_SIMULATION_H
