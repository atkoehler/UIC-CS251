/// @file traincars.h
/// @author Adam T Koehler, PhD
/// @date October 2, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         several classes to demonstrate C++ inheritance and polymorphism.
///         Including the creation of several virtual functions.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#pragma once

#include <string>

using namespace std;


// our basic train car
class TrainCar
{
    private:
        string carName;        
        
    protected:
        int modelYear;

    public:
        TrainCar();
        TrainCar(int);
        string getCarName() const;
        void setCarName(string);
        virtual string toString() const; 
        virtual ~TrainCar();      
};

// our engine car inherits from train car
class EngineCar : public TrainCar
{
    private:
        bool electric;
        
    protected:
        
    public:
        EngineCar();
        bool isElectric() const;
        void setElectric(bool);   
        virtual string toString() const;  
        virtual ~EngineCar();   
};

// our passenger car inherits from train car
class PassengerCar : virtual public TrainCar
{
    private:
        int numSeats;
        int numPeople;
        
    protected:
        
    public:
        PassengerCar();
        PassengerCar(int,int,int);
        int getSeats() const;
        int getPeopleCount() const;
        void setSeats(int);
        void setPeopleCount(int); 
        virtual string toString() const; 
        virtual ~PassengerCar();     
};

// our bike car inherits from train car
class BikeCar : virtual public TrainCar
{
    private:
        
    protected:
        int bikeSlots;
        int numBikes;    
        
    public:
        BikeCar();
        BikeCar(int,int,int);
        int getSlots() const;
        int getBikeCount() const;
        void setBikeSlots(int);
        void setBikeCount(int); 
        virtual string toString() const;  
        virtual ~BikeCar();    
};

// our combo car is a passenger car and a bike car
class ComboCar : public PassengerCar, public BikeCar
{
    private:
       
    protected:
        
    public:
        ComboCar(int seats, int slots, int year);
        virtual string toString() const; 
        virtual ~ComboCar();
};

