
//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <cstring>
#include "Person.h"

using namespace std;

class Mission
{
    string name;
    int missionNumber, cost, faultProbability;

    bool completed; // boolean that indicates the mission success

    Passenger *passengers, *ptail; // passengers that added to the mission, and the tail of the passengers linkedlist
    Astronaut *crew, *ctail; // crew members that assigned to the mission, and the tail of the crew members linkedlist

    int static numMissions; // total number of created missions

public:
    Mission* next;
    
    Mission();                  // constructor
    Mission(string, int, int);  // constructor

    //getter and setter methods
    string getName();
    void setName(string);
    int getCost();
    int getMissionNumber();

    // wanted methods
    void operator += (Astronaut *);
    void operator += (Passenger *);
    bool executeMission();
    int calculateProfit(int);
};




