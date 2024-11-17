#include <iostream>
#include <deque>
#include <cstdlib> 
#include <ctime>
#include "Car.h"
using namespace std;

const int INSIZE = 2;

int main() {
    deque<Car> tollBoothQueue;
    srand(static_cast<unsigned int>(time(0)));

    
     for (int i = 0; i < INSIZE; ++i) {
        tollBoothQueue.push_back(Car());
    }
    cout << "Initial queue:" << endl;
    for (const auto& car : tollBoothQueue) {
        car.print();
    }
   
    cout << endl;

    int time = 0;
    while (!tollBoothQueue.empty()) {
        ++time;
        int chance = rand() % 100 + 1;
        cout << "Time: " << time << " Operation: ";

        if (chance <= 55) {
            cout << "Car paid: ";
            tollBoothQueue.front().print();
            tollBoothQueue.pop_front();
        } else { 
            Car newCar;
            cout << "Joined lane: ";
            newCar.print();
            tollBoothQueue.push_back(newCar);
        }

        
        cout << "Queue:" << endl;
        if (tollBoothQueue.empty()) {
            cout << "    Empty" << endl;
        } else {
            for (const auto& car : tollBoothQueue) {
                car.print();
            }
        }
        cout << endl;
    }

    return 0;
}
