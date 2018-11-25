#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <time.h>
#include <iterator>
#include "Passenger.h"
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

int main(int argc, char* argv[]) {

    clock_t tStart = clock();
    if(argc != 3){
        cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
        return 1;
    }

    Simulation simulation;
    simulation.runSimulation(argv);

    printf("Time taken: %.32fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
