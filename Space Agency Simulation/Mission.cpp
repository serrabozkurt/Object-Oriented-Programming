//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Mission.h"

using namespace std;

// MISSION CLASS'S METHODS:

Mission::Mission() // constructor
{
    name = "AA-00";

    numMissions++;
    missionNumber = numMissions; 

    cost = 0; 
    faultProbability = 0;
    completed = false;

    passengers = NULL;
    crew = NULL;

    ptail = NULL;
    ctail = NULL;
    next = NULL;
}

Mission::Mission(string n, int c, int f) // constructor
{
    if ((n.size() == 5)) // if the name contains 5 letters, we can contionue checking its format
    {
        string x = n.substr(0, 2); // getting the first 2 letters to x

        if( ("AA" <= x) && (x <= "ZZ") && (n[2] == '-') && ('0' <= n[3]) && (n[3] <= '9') && ('0' <= n[4]) && (n[4] <= '9') )
            name = n;
        else {
            cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
            name = "AA-00";
        }
    }
    else
    {
        cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
        name = "AA-00";
    } 

    numMissions++;
    missionNumber = numMissions;

    cost = c; 
    faultProbability = f;

    passengers = NULL;
    crew = NULL;

    ptail = NULL;
    ctail = NULL;
    next = NULL;
}

string Mission::getName(){
    return name;
}

void Mission::setName(string n) // the name we pick should also fit the name requirements written in pdf
{
    if ((n.size() == 5)) // if the name contains 5 letters, we can contionue checking its format
    {
        string x = n.substr(0, 2); // getting the first 2 letters to x

        if( ("AA" <= x) && (x <= "ZZ") && (n[2] == '-') && ('0' <= n[3]) && (n[3] <= '9') && ('0' <= n[4]) && (n[4] <= '9') )
            name = n;
        
        else {
            cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
            name = "AA-00";
        } 
    }
    else{
        cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
        name = "AA-00";
    } 
}

int Mission::getCost(){
    return cost;
}

int Mission::getMissionNumber(){
    return missionNumber;
}

void Mission::operator += (Astronaut *a)
{
    if( !crew ) // if the crew linkedlist is empty, meaning its head points to NULL 
    {
        crew = a; // head of the linkedlist will be the provided astronaut
        crew->next = NULL;
        ctail = crew; // tail and head will be the same
        return;
    }

    // if the linkedlist is not empty, we would continue from this line:

    ctail->next = a;      // add the new astronaut to linkedlists tail
    ctail = ctail->next;  // make it the new tail
    ctail->next = NULL;   // set its next to NULL
}

void Mission::operator += (Passenger *p)
{
    if( !(p->getTicket()) ) // if the passenger does not have a ticket, we cant continue adding that to the mission
    {
        cerr << "Passenger " << p->getName() << " " << p->getSurname() << " does not have a valid ticket!" << endl;
        return;
    }

    if( !passengers )  // if the passengers linkedlist is empty, meaning its head points to NULL 
    {
        passengers = p; // head of the linkedlist will be the provided passenger
        passengers->next = NULL;
        ptail = passengers; // tail and head will be the same
        return;
    }
    
    // if the linkedlist is not empty, we would continue from this line:
    ptail->next = p;      // add the new astronaut to linkedlists tail
    ptail = ptail->next;  // make it the new tail
    ptail->next = NULL;   // set its next to NULL
}

bool Mission::executeMission()
{
    int x = rand() % 101; // possibility of the fauşt will be a number between 0-100, so modulus will be gotten wrt 101

    if( x > faultProbability && faultProbability != 100) // if we dont fail
    {
        cout << "MISSION " << name << " SUCCESSFUL!" << endl;

        Astronaut* a = crew; // this astronaut pointer will point each crew member one by one

        while(a) // make each astronaut in the crew list complete their missions
        {   
            a->completeMission(); 
            cout << "Astronaut " << a->getName() << " " << a->getSurname() << " successfully completed " << a->getNumMissions() << " missions." << endl;
            a = a->next;
        }
        
        completed = true;
    }
    else  // if we fail
    {
        cout << "MISSION " << name <<" FAILED!" << endl << "Agency reschedules the mission." << endl;
        completed = false;
    }
    return completed; // return whether the mission is completed or not
}

int Mission::calculateProfit(int ticketPrice)
{
    int profit = 0; // our initial profit is 0

    if(completed) // if we completed the mission, it means we can get money from each passenger
    {
        Passenger* a = passengers; // this passenger pointer will point each passenger one by one
        
        while(a)  // reeive payment from each passenger in the list
        {
            a->setTicket(false); // remove the ticket from passenger 
            profit += ticketPrice;
            a = a->next;
        }
    }
    return (profit - cost);
}

