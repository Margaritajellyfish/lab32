#include <iostream>
#include <deque>
#include <array>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;
const int NUM_LANES = 4;
const int NUM_TIME_PERIODS = 20;
const int PAY_PROB = 46;
const int JOIN_PROB = 39;
const int SWITCH_PROB = 15;

int main() {
    array<deque<Car>, NUM_LANES> lanes;
    srand(static_cast<unsigned int>(time(0)));

  
    for (int i = 0; i < NUM_LANES; ++i) {
        int numCars = rand() % 3 + 1; 
        for (int j = 0; j < numCars; ++j) {
            lanes[i].push_back(Car());
        }
    }

    
    cout << "Initial lanes:" << endl;
    for (int i = 0; i < NUM_LANES; ++i) {
        cout << "Lane " << i + 1 << ":" << endl;
        for (auto& car : lanes[i]) {
            car.print();
        }
        cout << endl;
    }

    cout << endl;

    int timePeriod = 0; 

    
    while (timePeriod < NUM_TIME_PERIODS) {
        ++timePeriod;
        cout << "Time Period: " << timePeriod << endl;

        for (int i = 0; i < NUM_LANES; ++i) {
            cout << "Lane " << i + 1 << " Operation: ";

            if (!lanes[i].empty()) {
                int chance = rand() % 100 + 1;

                
                if (chance <= PAY_PROB) {
                    cout << "Car paid and left: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();

                
                } else if (chance <= PAY_PROB + JOIN_PROB) {
                    Car newCar;
                    lanes[i].push_back(newCar);
                    cout << "New car joined: ";
                    newCar.print();

                
                } else if (!lanes[i].empty()) {
                    int newLane;
                    do {
                        newLane = rand() % NUM_LANES;
                    } while (newLane == i); 

                    Car movingCar = lanes[i].back();
                    lanes[i].pop_back();
                    lanes[newLane].push_back(movingCar);
                    cout << "Rear car switched to Lane " << newLane + 1 << ": ";
                    movingCar.print();
                }
            } else {
                cout << "Lane is empty.";
            }

           
            cout << "\n  Current queue:" << endl;
            if (lanes[i].empty()) {
                cout << "    Empty" << endl;
            } else {
                for (auto& car : lanes[i]) {
                    car.print();
                }
            }
        }

        cout << endl;
    }

    cout << "Simulation ended after " << NUM_TIME_PERIODS << " time periods." << endl;
    return 0;
}
