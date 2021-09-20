
//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <string.h>
using namespace std;


class Person{
    string name, surname;
    
public:
    Person(); // constructor

    Person(string, string);  // constructor

    //getter and setter methods 

    string getName();
    string getSurname();
    void setName(string);
    void setSurname(string);

};

class Passenger: public Person
{
    int cash;
    bool ticket;

public:
    Passenger* next;

    Passenger(); //constructor
    Passenger(string, string); //constructor
    Passenger(string, string, int); //constructor

    //getter and setter methods
    bool getTicket();
    void setTicket(bool);
    
    // wanted method:
    bool buyTicket(int);
    
};


class Astronaut: public Person
{
    int numMissions;

public:
    Astronaut* next;
    
    Astronaut();                    //constructor
    Astronaut(string, string);      //constructor
    Astronaut(string, string, int); //constructor

    //wanted methods:
    void completeMission();
    
    //getter and setter methods
    int getNumMissions();
};



