//
// Created by Yaşar Selçuk Çalışkan on 26.10.2018.
//

#include <sstream>
#include <iostream>
#include <fstream>
#include "Simulation.h"

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

void Simulation::runSimulation(char *argv[]) {

    readInput(argv[1]);

    //default scenario
    Scenario scenario1(false, false, false, numLuggageCounters, numSecCounters);
    Scenario scenario2(true, false, false, numLuggageCounters, numSecCounters);
    Scenario scenario3(false, true, false, numLuggageCounters, numSecCounters);
    Scenario scenario4(true, true, false, numLuggageCounters, numSecCounters);
    Scenario scenario5(false, false, true, numLuggageCounters, numSecCounters);
    Scenario scenario6(true, false, true, numLuggageCounters, numSecCounters);
    Scenario scenario7(false, true, true, numLuggageCounters, numSecCounters);
    Scenario scenario8(true, true, true, numLuggageCounters, numSecCounters);
    scenarios.push_back(&scenario1);
    scenarios.push_back(&scenario2);
    scenarios.push_back(&scenario3);
    scenarios.push_back(&scenario4);
    scenarios.push_back(&scenario5);
    scenarios.push_back(&scenario6);
    scenarios.push_back(&scenario7);
    scenarios.push_back(&scenario8);
    fillScenarios();
    for (Scenario* scenario : scenarios){
        results.push_back(scenario->runScenario());
    }
    writeOutput(argv[2], results);
}

void Simulation::readInput(char* inputFile) {

    ifstream infile(inputFile);
    if(infile.peek() == ifstream::traits_type::eof()){
        cout << "input file is empty, finishing simulation." << endl;
        return;
    }
    string line;
    // process first line
    getline(infile, line);
    vector<string> features;
    split1(line, features);
    //N number of passengers
    numPassengers = stoi(features[0]);
    //L number of luggage counters
    numLuggageCounters = stoi(features[1]);
    //S number of security counters
    numSecCounters = stoi(features[2]);

    for (int i=0; i<numPassengers; i++) {
        getline(infile, line);

        vector<string> passenger_features;
        split1(line,passenger_features);

        passengers.push_back(new Passenger(passenger_features));
    }

}

void Simulation::fillScenarios() {
    for (int i=0; i<scenarios.size(); i++){
        (*scenarios[i]).setPassengers(passengers);
    }
}

void Simulation::writeOutput(char *outputFile, const vector<vector<float>> &results) {
    ofstream myfile;
    myfile.open (outputFile);
    for (vector<float> result : results){
        myfile << result[0] << " " << result[1] << endl;
    }
    myfile.close();
}
