//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <cstring>
#include "Faction.h"

using namespace std;

class Merchant
{
    Faction *firstFaction, *secondFaction, *thirdFaction;
    int startingWeaponPoints, startingArmorPoints, revenue, weaponPoints, armorPoints;
    
public:
    Merchant();            // constructor
    Merchant(int, int);    // constructor

    //wanted methods
    void AssignFactions(Faction*,Faction*,Faction*);
    bool SellWeapons(string, int);
    bool SellArmors(string, int);
    void EndTurn();

    //getter and setter methods 

    int getStartingWeaponPoints(){return startingWeaponPoints;}
    void setStartingWeaponPoints(int n){startingWeaponPoints = n;}

    int getStartingArmorPoints(){return startingArmorPoints;}
    void setStartingArmorPoints(int n){startingArmorPoints = n;}

    int GetRevenue(){return revenue;}
    void SetRevenue(int n){revenue = n;}

    int GetWeaponPoints(){return weaponPoints;}
    void setWeaponPoints(int n){weaponPoints = n;}

    int GetArmorPoints(){return armorPoints;}
    void SetArmorPoints(int n){armorPoints = n;}
        
    Faction* getFirstFaction(){return firstFaction;}
    void setFirstFaction(Faction* n){firstFaction = n;}

    Faction* getSecondFaction(){return secondFaction;}
    void setSecondFaction(Faction* n){secondFaction = n;}

    Faction* getThirdFaction(){return thirdFaction;}
    void setThirdFaction(Faction* n){thirdFaction = n;}

};
