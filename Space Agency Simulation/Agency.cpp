//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Agency.h"

using namespace std;

Agency::Agency() // constructor
{
    name = "";
    cash = 0;
    ticketPrice = 0;

    completedMissions = NULL; 
    completedMissionsTail = NULL;
    nextMissions = NULL; 
    nextMissionsTail = NULL;
}

Agency::Agency(string n, int c, int t) // constructor
{   
    name = n;
    cash = c;

    if(t < 0)
    {
        cerr << "Ticket price can't be negative. It is set to 0." << endl;
        ticketPrice = 0;
    }
    else ticketPrice = t;

    completedMissions = NULL; 
    completedMissionsTail = NULL;
    nextMissions = NULL; 
    nextMissionsTail = NULL;
}

string Agency::getName(){
    return name;
}

int Agency::getTicketPrice(){
    return ticketPrice;
}

void Agency::setTicketPrice(int t){
    ticketPrice = t;
}

void Agency::addMission(Mission newMission)
{
    Mission* m = &newMission; // created a pointer to the new mission we will add

    if( !nextMissions ) // if the nextMissions linkedlist is empty, meaning its head points to NULL 
    {
        nextMissions = m;                // head of the linkedlist will be the provided mission
        nextMissionsTail = nextMissions; // tail and head will be the same
        nextMissions->next = NULL;
    } 
    else // if the linkedlist is not empty, we would continue from this line:
    {
        nextMissionsTail->next = m;                 // add the new mission to linkedlists tail
        nextMissionsTail = nextMissionsTail->next;  // make it the new tail
        nextMissionsTail->next = NULL;              // set its next to NULL
    }
}

void Agency::executeNextMission()
{
    if(nextMissions) // if the nextMissions linkedlist is NOT empty, meaning we have a mission to execute 
    {
        Mission* m = nextMissions;  // pointer to the mission we will execute

        if(!nextMissions->next) // if there are no any other missions in the linkedlist
        {
            nextMissions = NULL;         // make all pointers point to NULL
            nextMissionsTail = NULL;
        }
        else nextMissions = nextMissions->next; // else just remove the mission from the head, change the head

        bool executed = m->executeMission(); // execute the mission

        if( executed ) // if the mission has been executed successfully
        {
            if(!completedMissions) // add it to the completed Missions linkedlist
            {
                completedMissions = m;
                completedMissionsTail = completedMissions;
                completedMissions->next = NULL;
            }
            else{
                completedMissionsTail->next = m;
                completedMissionsTail = completedMissionsTail->next;
                completedMissionsTail->next = NULL;
            }
        }
        else // if the mission is NOT executed successfully
        {
            if(!nextMissions){ // add it behind the next Missions linkedlist
                nextMissions = m;
                nextMissionsTail = nextMissions;
                nextMissions->next = NULL;
            }
            else{
                nextMissionsTail->next = m;
                nextMissionsTail = nextMissionsTail->next;
                nextMissionsTail->next = NULL;
            }
        }
        cash += m->calculateProfit(ticketPrice); // calculate the profit whatever happens (success/failure)
    }

    else // if we DONT have any mission to execute 
    {
        cout << "No available mission to execute!" << endl;
    }
}

ostream& operator << (ostream& o, Agency a)
{
    Mission* ptr = NULL;
    o << "Agency name: " << a.name << ", Total cash: " << a.cash << ", Ticket Price: " << a.ticketPrice << endl;


    o << "Next Missions:" << endl; // printing next missions of agency

    if( a.nextMissions ) // if there are next missions
    {
        ptr = a.nextMissions;
        while( ptr ) 
        {
            o << "Mission number: " << ptr->getMissionNumber() << " Mission name: " << ptr->getName() << " Cost: " << ptr->getCost() << endl;
            ptr = ptr->next;
        }
    }
    else o << "No missions available." << endl;
    

    o << "Completed Missions:" << endl; // printing completed missions of agency

    if( a.completedMissions ) // if there are completed missions
    {
        ptr = a.completedMissions;
        while( ptr )
        {
            o << "Mission number: " << ptr->getMissionNumber() << " Mission name: " << ptr->getName() << " Cost: " << ptr->getCost() << endl;
            ptr = ptr->next;
        }
    }
    else o << "No missions completed before." << endl;
    
    return o;
}

