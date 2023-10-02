/// @file 20230927.cpp
/// @author Adam T Koehler, PhD
/// @date September 27, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         builds a several classes to demonstrate class design and 
///         inheritance in C++.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include <vector>
#include "traincars.h"

using namespace std;

int main()
{
    cout << "Generic Train Car Prints" << endl;
    TrainCar one;
    TrainCar two(2020);
    TrainCar *three = new TrainCar(2020);
    cout << one.toString() << endl;
    cout << two.toString() << endl;
    cout << three->toString() << endl;


    cout << endl << endl;
    cout << "Engine Car Prints" << endl;
    EngineCar four;
    EngineCar *five = new EngineCar();
    cout << four.toString() << endl;
    cout << five->toString() << endl; 


    cout << endl << endl;
    cout << "Passenger Car Prints" << endl;
    PassengerCar six;
    PassengerCar *seven = new PassengerCar();
    cout << six.toString() << endl;
    cout << seven->toString() << endl; 
    six.setPeopleCount(5);
    cout << six.toString() << endl;


    cout << endl << endl;
    cout << "Bike Car Prints" << endl;
    BikeCar eight;
    BikeCar *nine = new BikeCar();
    cout << eight.toString() << endl;
    cout << nine->toString() << endl; 


    cout << endl << endl;
    cout << "Combo Car Prints" << endl;

    ComboCar ten(15, 5, 2023);
    cout << ten.toString() << endl;

    ten.setBikeCount(3);
    ten.setPeopleCount(7);
    cout << ten.toString() << endl;
    ComboCar *eleven = new ComboCar(15, 5, 2023);
    eleven->setBikeCount(1);
    eleven->setPeopleCount(13);
    cout << eleven->toString() << endl;    


    cout << endl << endl;
    cout << "Generic Train Car is Combo Print: " << endl;
    TrainCar twelve = ComboCar(25, 10, 2023);
    cout << twelve.toString() << endl;


    cout << endl << endl;
    cout << "Vector of Train Cars Prints: " << endl;
    vector<TrainCar *> train;
    train.push_back(&four);
    train.push_back(&six);
    train.push_back(&eight);
    train.push_back(&six);
    train.push_back(&ten);

    for (const auto &car : train)
    {
        cout << car->toString() << endl;
    }

    return 0;
}


