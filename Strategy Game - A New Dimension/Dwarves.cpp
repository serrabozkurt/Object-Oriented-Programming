//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Dwarves.h"

using namespace std;


// constructors:
Dwarves::Dwarves():Faction(){}
Dwarves::Dwarves(string n, int u, int a, int h, int r):Faction(n, u, a, h, r){} 

void Dwarves::PerformAttack() 
{
    // performing the attack to ALIVE enemies, 
    // according to the given criterion in pdf 
    
    Faction *o = this->getFirstEnemy();
    Faction *e = this->getSecondEnemy();
    
    int attack = this->getAttackPoint();
    int unit = this->getNumOfUnits() / 2;

    if (o->IsAlive() && e->IsAlive()) // if both are alive:
    {
        e->ReceiveAttack(this->getName(), unit, attack);
        o->ReceiveAttack(this->getName(), unit, attack);
        return;
    }

    if ( o->IsAlive() ) o->ReceiveAttack(this->getName(), this->getNumOfUnits(), attack);
    if ( e->IsAlive() ) e->ReceiveAttack(this->getName(), this->getNumOfUnits(), attack);
}

void Dwarves::ReceiveAttack(string n, int units, int attackpt)
{
    //receiving attack from enemies and decreasing the number of units according to the given criteria in pdf
    this->setNumOfUnits(this->getNumOfUnits() - (units * attackpt / this->getHealthPoint()));
}

int Dwarves::PurchaseWeapons(int w)
{
    // purchasing weapons and increasing the attack point according to pdf
    this->setAttackPoint(this->getAttackPoint() + w);
    return 10*w;
}

int Dwarves::PurchaseArmors(int a)
{
    // purchasing armors and increasing the health point according to pdf
    this->setHealthPoint(this->getHealthPoint() + a*2);
    return a*3;
}

void Dwarves::Print()
{
    cout << '"' << "Taste the power of our axes!" << '"' << endl; // printing statements special to dwarves
    // then calling the print function defined under the Faction class, to print statements common in every faction
    Faction::Print(); 
}


