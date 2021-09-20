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


class Elves: public Faction
{
public:    
    Elves();                           //constructor
    Elves(string, int, int, int, int); //constructor

    //wanted methods:
    void PerformAttack(); 
    void ReceiveAttack(string, int, int); 
    int PurchaseWeapons(int); 
    int PurchaseArmors(int); 
    void Print();
};



