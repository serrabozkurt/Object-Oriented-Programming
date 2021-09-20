//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Elves.h"

using namespace std;


// constructors:
Elves::Elves():Faction(){}
Elves::Elves(string n, int u, int a, int h, int r):Faction(n, u, a, h, r){} 

void Elves::PerformAttack()
{
    // performing the attack to ALIVE enemies, 
    // according to the given criterion in pdf 
    
    Faction *d = this->getSecondEnemy();
    Faction *o = this->getFirstEnemy();
    
    int attack = this->getAttackPoint();
    int unit1 = this->getNumOfUnits() * 3 / 5;
    int unit2 = this->getNumOfUnits() - unit1;

    if (d->IsAlive() && o->IsAlive()) // if both are alive:
    {
        o->ReceiveAttack(this->getName(), unit1, attack);
        d->ReceiveAttack(this->getName(), unit2, (attack * 3 / 2));
        return;
    }

    if ( d->IsAlive() ) d->ReceiveAttack(this->getName(), unit1 + unit2, (attack * 3 / 2));
    if ( o->IsAlive() ) o->ReceiveAttack(this->getName(), unit1 + unit2, attack);
}

void Elves::ReceiveAttack(string n, int units, int attackpt)
{
    //receiving attack from enemies and decreasing the number of units according to the given criteria in pdf
    
    if(n == "Orcs") attackpt = attackpt * 5 / 4;
    if(n == "Dwarves") attackpt = attackpt * 3 / 4;

    this->setNumOfUnits(this->getNumOfUnits() - (units * attackpt / this->getHealthPoint()));
}

int Elves::PurchaseWeapons(int w)
{
    // purchasing weapons and increasing the attack point according to pdf
    this->setAttackPoint(this->getAttackPoint() + w*2);
    return 15*w;
}

int Elves::PurchaseArmors(int a)
{
    // purchasing armors and increasing the health point according to pdf
    this->setHealthPoint(this->getHealthPoint() + a*4);
    return 5*a;
}

void Elves::Print()
{
    cout << '"' << "You cannot reach our elegance." << '"' << endl;
    // then calling the print function defined under the Faction class, to print statements common in every faction
    Faction::Print(); 
}

