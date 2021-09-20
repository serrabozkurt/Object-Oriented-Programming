//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <cstring>
#include "Mission.h"
using namespace std;


class Agency
{
    string name; 
    int cash, ticketPrice;

    Mission *completedMissions; 
    Mission *nextMissions;
    Mission *completedMissionsTail;
    Mission *nextMissionsTail;
    
public:
    Agency();                      // constructor
    Agency(string, int, int);      // constructor

    //getter and setter mothods 
    string getName();
    int getTicketPrice();
    void setTicketPrice(int);
    
    //wanted methods
    void addMission(Mission);
    void executeNextMission();    
    friend ostream& operator <<(ostream&, Agency);
};


