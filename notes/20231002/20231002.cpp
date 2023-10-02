/// @file 20231002.cpp
/// @author Adam T Koehler, PhD
/// @date October 2, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         several classes to demonstrate C++ inheritance and polymorphism.

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
    // We can create objects of the base class.
    // Allocating from the stack memory or using new to 
    //  dynamically allocate memory from the heap.
    cout << "Generic Train Car Prints" << endl;
    TrainCar one;
    TrainCar two(2020);
    TrainCar *three = new TrainCar(2020);
    cout << one.toString() << endl;
    cout << two.toString() << endl;
    cout << three->toString() << endl;


    // We can create objects of each derived class,
    //  and utilize the member functions.
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


    // We can create a ComboCar that has multiple inheritance.
    //  ComboCars are both BikeCars and PassengerCars so we can
    //  use the inherited data members or the member functions
    //  of both of those base classes.
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


    // We can create a ComboCar that has multiple inheritance.
    //  ComboCars are both BikeCars and PassengerCars.
    //  However both all are TrainCars so it fits there too!
    cout << endl << endl;
    cout << "Generic Train Car is Combo Print: " << endl;
    TrainCar twelve = ComboCar(25, 10, 2023);
    cout << twelve.toString() << endl;


    // We can create a container of similar objects.
    //  All of our derived cars inherit from the TrainCar class,
    //  so they all can fit into a TrainCar data type.
    cout << endl << endl;
    cout << "Vector of Train Cars Prints:" << endl;
    vector<TrainCar> train;
    train.push_back(four);
    train.push_back(six);
    train.push_back(eight);
    train.push_back(six);
    train.push_back(ten);
    for (const auto &car : train)
    {
        cout << car.toString() << endl;
    }


    // We need to use pointers to achieve polymorphism
    // We could use the addresses of the actual objects
    //  that have been created in our main, this isn't
    //  always good to do as the pointer will be a dangling
    //  pointer if the object goes out of scope and is destroyed.
    cout << endl << endl;
    cout << "Vector of Train Cars Pointer Prints:" << endl;
    vector<TrainCar *> train2;
    train2.push_back(&four);
    train2.push_back(&six);
    train2.push_back(&eight);
    train2.push_back(&six);
    train2.push_back(&ten);
    for (const auto &car : train2)
    {
        cout << car->toString() << endl;
    }
    train2.clear();

    // We can use the dynamic allocations as well
    // since they are already pointers!
    cout << endl << endl;
    cout << "Vector of Train Cars Pointer Prints:" << endl;
    train2.push_back(three);
    train2.push_back(five);
    train2.push_back(seven);
    train2.push_back(nine);
    train2.push_back(eleven);
    for (const auto &car : train2)
    {
        cout << car->toString() << endl;
    }


    // without these we do not get a clean valgrind report
    // for every dynamic allocation now stored in train2
    //  deallocate the memory associated with the pointer
    for (const auto &car : train2)
    {
        delete car;
    }


    // Destrutors get called when program ends as variables
    // leave scope at the end of a function!
    cout << endl << endl;
    cout << "Exiting program destructor calls!" << endl; 

    return 0;
}


