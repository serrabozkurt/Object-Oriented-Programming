//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Faction.h"

using namespace std;

Faction::Faction() // constructor
{
    name = "";
    firstEnemy = NULL; secondEnemy = NULL;
    numOfUnits = 0; attackPoint = 0; healthPoint = 0; unitRegen = 0; 
    this->setTotalHealth();
    flag = true;
}

Faction::Faction(string n, int u, int a, int h, int r):Faction() // constructor, using the base constructor
{   
    name = n;
    numOfUnits = u; attackPoint = a; healthPoint = h; unitRegen = r; 
    this->setTotalHealth();
}

void Faction::AssignEnemies(Faction* e1, Faction* e2) 
{
    /* assigning the enemy factions to given faction:
        - if faction is orcs, enemies are dwarves and elves, 
        - if faction is dwarves, enemies are orcs and elves, 
        - if faction is elves, enemies are orcs and dwarves, 
    by using the ternary operator (one liner if statement) */

    if(name == "Orcs")
    {
        firstEnemy = (e1->getName() == "Dwarves") ? e1 : e2;
        secondEnemy = (e1->getName() == "Elves") ? e1 : e2;
    }
    else if(name == "Dwarves")
    {
        firstEnemy = (e1->getName() == "Orcs") ? e1 : e2;
        secondEnemy = (e1->getName() == "Elves") ? e1 : e2;
    }
    else
    {
        firstEnemy = (e1->getName() == "Orcs") ? e1 : e2;
        secondEnemy = (e1->getName() == "Dwarves") ? e1 : e2;
    }
}

void Faction::Print() // printing the given information in the wanted format
{
    cout << left << setw(22) << "Faction Name: " << name << endl;
    cout << left << setw(22) << "Status: " << (flag ? "Alive" : "Defeated") << endl;
    cout << left << setw(22) << "Number of Units: " << numOfUnits << endl;
    cout << left << setw(22) << "Attack Point: " << attackPoint << endl;
    cout << left << setw(22) << "Health Point: " << healthPoint << endl;
    cout << left << setw(22) << "Unit Regen Number: " << unitRegen << endl;
    cout << left << setw(22) << "Total Faction Health: " << totalHealth << endl;
}

void Faction::EndTurn() // ending the turn
{
    if(numOfUnits < 0) numOfUnits = 0; // negative member number is not possible
    
    if(numOfUnits == 0) // if member number is zero, we are dead
        flag = false;
    else numOfUnits += unitRegen; // else, new people will be born

    this->setTotalHealth();
}

