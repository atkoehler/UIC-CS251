/// @file traincars.cpp
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

#include <string>
#include <iostream>
#include "traincars.h"

using namespace std;


// ----------------------------------------------------
// ------------- TrainCar Implementations -------------
// ----------------------------------------------------

TrainCar::~TrainCar()
{
    cout << "Destroying Generic: " << toString() << endl;
}

TrainCar::TrainCar()
{
    carName = "Generic";
    modelYear = 0;
}

TrainCar::TrainCar(int modelYear)
{
    carName = "Generic";
    this->modelYear = modelYear;
}

string TrainCar::getCarName() const
{
    return carName;
}

void TrainCar::setCarName(string name)
{
    carName = name;
}

string TrainCar::toString() const
{
    // This part was written with the activity handout
    return "{" + carName + ", " + to_string(modelYear) + "}";
}



// ---------------------------------------------------
// ------------ EngineCar Implementations ------------
// ---------------------------------------------------
EngineCar::~EngineCar()
{
    cout << "Destroying Engine: " << toString() << endl;
}

EngineCar::EngineCar()
{
    electric = false;
    modelYear = 0;
    setCarName("Electric");    
}

bool EngineCar::isElectric() const
{
    return electric;
}

void EngineCar::setElectric(bool value) 
{
    electric = value;
}

string EngineCar::toString() const
{
    string s;
    s += "{" + getCarName() + ", " + to_string(modelYear) + ", ";
    if (electric)
    {
        s += "electric";
    }
    else
    {
        s += "combustion";
    }

    s += "}";

    return s;
}



// ----------------------------------------------------
// ----------- PassengerCar Implementations -----------
// ----------------------------------------------------
PassengerCar::~PassengerCar()
{
    cout << "Destroying Passenger: " << toString() << endl;
}

PassengerCar::PassengerCar()
{
    numSeats = 20;
    numPeople = 0;
    modelYear = 0;
    setCarName("Passenger");
}

PassengerCar::PassengerCar(int seats, int people, int year)
{
    numSeats = seats;
    numPeople = people;
    modelYear = year;
    setCarName("Passenger");
}

int PassengerCar::getSeats() const
{
    return numSeats;
}

int PassengerCar::getPeopleCount() const
{
    return numPeople;
}

void PassengerCar::setSeats(int x)
{
    numSeats = x;
}

void PassengerCar::setPeopleCount(int x)
{
    numPeople = x;
}

string PassengerCar::toString() const
{
    string s;
    s += "{" + getCarName() + ", " + to_string(modelYear) + ", ";
    s += "Seats: " + to_string(numSeats) + ", ";
    s += "People: " + to_string(numPeople);
    s += "}";

    return s;
}



// ---------------------------------------------------
// ------------- BikeCar Implementations -------------
// ---------------------------------------------------
BikeCar::~BikeCar()
{
    cout << "Destroying Bike: " << toString() << endl;
}

BikeCar::BikeCar()
{
    bikeSlots = 10;
    numBikes = 0;
    modelYear = 0;
    setCarName("Bike");
}

BikeCar::BikeCar(int slots, int bikes, int year)
{
    bikeSlots = slots;
    numBikes = bikes;
    modelYear = 0;
    setCarName("Bike");
}

int BikeCar::getSlots() const
{
    return bikeSlots;
}

int BikeCar::getBikeCount() const
{
    return numBikes;
}

void BikeCar::setBikeSlots(int x)
{
    bikeSlots = x;
}

void BikeCar::setBikeCount(int x)
{
    numBikes = x;
}

string BikeCar::toString() const
{
    string s;
    s += "{" + getCarName() + ", " + to_string(modelYear) + ", ";
    s += "Slots: " + to_string(bikeSlots) + ", ";
    s += "Bikes: " + to_string(numBikes);
    s += "}";

    return s;
}



// --------------------------------------------------
// ------------ ComboCar Implementations ------------
// --------------------------------------------------
ComboCar::~ComboCar()
{
    cout << "Destroying Combo: " << toString() << endl;
}

ComboCar::ComboCar(int seats, int slots, int year)
{
    bikeSlots = slots;
    numBikes = 0;
    modelYear = year;
    setSeats(seats);
    setPeopleCount(0);
    setCarName("Combo");
}

string ComboCar::toString() const
{
    string s;

    // This part was written with the activity handout
    s += "{" + getCarName() + ", " + to_string(modelYear) + ", ";
    s += "Seats: " + to_string(getSeats()) + ", ";
    s += "People: " + to_string(getPeopleCount()) + ", ";    
    s += "Slots: " + to_string(bikeSlots) + ", ";
    s += "Bikes: " + to_string(numBikes);
    s += "}";

    return s;
}
