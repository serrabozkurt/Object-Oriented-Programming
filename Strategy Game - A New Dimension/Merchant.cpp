//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Merchant.h"

using namespace std;

Merchant::Merchant() // constructor
{
    firstFaction = NULL;
    secondFaction = NULL; 
    thirdFaction = NULL;
    startingWeaponPoints = 0;
    startingArmorPoints = 0; 
    revenue = 0; 
    this->EndTurn(); // ending the turn to set the weapon and armor points' values to their starting values
}

Merchant::Merchant(int w, int a):Merchant() // constructor
{
    startingWeaponPoints = w;
    startingArmorPoints = a; 
    this->EndTurn(); // ending the turn to set the weapon and armor points' values to their starting values
}

void Merchant::AssignFactions(Faction* e1, Faction* e2, Faction* e3)
{
    /* assingning the enemy factions in such a way that:
        - the first faction = orcs
        - the second faction = dwarves
        - the third faction = elves
    by using the ternary operator (one liner if statement) */

    if(e1->getName() == "Orcs")
    {
        firstFaction = e1;
        secondFaction = (e2->getName() == "Dwarves") ? e2 : e3;
        thirdFaction = (e2->getName() == "Elves") ? e2 : e3;
    }
    else if(e1->getName() == "Dwarves")
    {
        secondFaction = e1;
        firstFaction = (e2->getName() == "Orcs") ? e2 : e3;
        thirdFaction = (e2->getName() == "Elves") ? e2 : e3;
    }
    else
    {
        thirdFaction = e1;
        firstFaction = (e2->getName() == "Orcs") ? e2 : e3;
        secondFaction = (e2->getName() == "Dwarves") ? e2 : e3;
    }
}

bool Merchant::SellWeapons(string n, int w)
{
    if(w == 0) return false;

    Faction* customer; // creating a customer faction
     
    // deciding who the given customer faction is, who are we in business with:
    if(n == "Orcs") customer = firstFaction;
    else if(n == "Dwarves") customer = secondFaction;
    else customer = thirdFaction;

    if(customer->IsAlive()) // if the customer faction is alive, we will try to do the transaction (trade)
    {
        if(weaponPoints < w) // if we dont have enough weapons
        {
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false; // we cant sell anything
        }

        revenue += customer->PurchaseWeapons(w); // else we will sell the weapons to customer
        weaponPoints -= w;
        cout << "Weapons sold!" << endl;
        return true;
    }
    cout << "The faction you want to sell weapons is dead!" << endl; // is customer is not alive, no transaction happened
    return false;
}

bool Merchant::SellArmors(string n, int a)
{
    if(a == 0) return false;
    
    Faction* customer; // creating a customer faction

    // deciding who the given customer faction is, who are we in business with:
    if(n == "Orcs") customer = firstFaction;
    else if(n == "Dwarves") customer = secondFaction;
    else customer = thirdFaction;

    if(customer->IsAlive()) // if the customer faction is alive, we will try to do the transaction (trade)
    {
        if(armorPoints < a) // if we dont have enough armors
        {
            cout << "You try to sell more armors than you have in possession." << endl;
            return false; // we cant sell anything
        }

        revenue += customer->PurchaseArmors(a); // else we will sell the armors to customer
        armorPoints -= a;
        cout << "Armors sold!" << endl;
        return true;
    }
    cout << "The faction you want to sell armor is dead!" << endl; // is customer is not alive, no transaction happened
    return false;
}

void Merchant::EndTurn() // assigning the weaponpoints and armorpoints to their starting values
{
    weaponPoints = startingWeaponPoints;
    armorPoints = startingArmorPoints;
}

