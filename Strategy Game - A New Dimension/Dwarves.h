//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <string.h>
#include "Faction.h"
using namespace std;


class Dwarves: public Faction
{
public:    
    Dwarves();                           //constructor
    Dwarves(string, int, int, int, int); //constructor

    //wanted methods:
    void PerformAttack(); 
    void ReceiveAttack(string, int, int); 
    int PurchaseWeapons(int); 
    int PurchaseArmors(int); 
    void Print();
};

