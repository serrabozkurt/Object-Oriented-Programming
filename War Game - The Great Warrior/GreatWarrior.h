
//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <cstring>
using namespace std;


class Land{
    string name, holding;
    
public:
    Land* next;

    Land();                           // constructor
    Land(string, string);             // constructor
    Land(Land &);                     // copy constructor

    //getter mothods i decided to use
    string getName(){return name;}
    string getHolding(){return holding;}

    ~Land(){;} // destructor
};


class Character{
    string name;
    int manpower, gold, numOfLands;
    Land *lands; // head of Lands linked list

public:
       
    //constructor
    Character(){ name = ""; manpower = 3; gold = 20; numOfLands = 0; lands = NULL; } 

    Character(string, int, int, int);  // constructor
    Character(Character &);            // copy constructor

    //wanted methods:
    void getTaxes();
    void addLand(Land*);
    Land* removeLand(string);

    //getter and setter mothods i decided to use
    string getName(){return name;}
    int getManpower(){ return manpower;}
    int getGold(){ return gold;}
    int getNumOfLands(){ return numOfLands;}
    Land* getLands(){return lands;}

    void setManpower(int n){manpower = n;}
    void setGold(int n){gold = n;}
    void setName(string n){name = n;}
    void setLands(Land* n){lands = n;}
    void setNumOfLands(int n){numOfLands = n;}

    ~Character(); // destructor
};


class CharacterList
{
    Character* characters;
    int size;

    friend void listCharacters(CharacterList& charList);
    friend void listLands(CharacterList& charList);

public:
    CharacterList(){characters = NULL; size = 0;} //constructor

    // wanted methods:
    void addCharacter(Character*);
    void delCharacter(string );
    Character* getPlayer(string);
    Character* getLandOwner(string);
    
    // getter method i decided to use
    int getSize(){return size;}

    ~CharacterList(); // destructor
};



