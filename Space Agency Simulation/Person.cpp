//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

using namespace std;


// PERSON CLASS'S METHODS

Person::Person() // constructor
{   
    name = ""; //"Neil";  
    surname = ""; //"Armstrong"; 
}

Person::Person(string n, string s) // constructor
{ 
    name = n; 
    surname = s;
}

string Person::getName(){
    return name;
}

string Person::getSurname(){
    return surname;
}

void Person::setName(string n){
    name = n;
}

void Person::setSurname(string s){
    surname = s;
}



// PASSENGER CLASS'S METHODS:

Passenger::Passenger(){  //constructor
    cash = 0; 
    ticket = false; 
    this->setName("");
    this->setSurname("");
    next = NULL;
}

Passenger::Passenger(string n, string s, int c) //constructor
{
    if( c < 0 )
    {
        cash = 0;
        cerr << "Passenger cash can’t be negative. It is set to 0." << endl;
    }
    else cash = c; 
    
    this->setName(n);
    this->setSurname(s);
    ticket = false;
    next = NULL;
}

Passenger::Passenger(string n, string s) //constructor
{
    cash = 0; 
    this->setName(n);
    this->setSurname(s);
    ticket = false;
    next = NULL;
}

bool Passenger::getTicket(){ 
    return ticket;
}

void Passenger::setTicket(bool t){
    ticket = t;
}

bool Passenger::buyTicket(int price)
{
    if(price <= cash) // if the passenger has enough money to buy ticket
    {
        cash -= price;
        ticket = true; // passenger will buy the ticket
    }
    else ticket = false; // if not, no ticket
    
    return ticket; // return whether the ticket is bought or not
}



// ASTRONAUT CLASS'S METHODS:

Astronaut::Astronaut(){ //constructor
    numMissions = 0;
    next = NULL;
}

Astronaut::Astronaut(string n, string s, int c) //constructor
{
    this->setName(n);
    this->setSurname(s);
    
    if(c < 0) // wanted condition in the pdf 
    {
        cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
        numMissions = 0;
    }
    else numMissions = c;
    next = NULL;
}

Astronaut::Astronaut(string n, string s) //constructor
{
    this->setName(n);
    this->setSurname(s);
    numMissions = 0;
    next = NULL;
}

int Astronaut::getNumMissions(){
    return numMissions;
}

void Astronaut::completeMission(){
    numMissions++;
}



