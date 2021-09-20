//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Orcs.h"

using namespace std;


// constructors:
Orcs::Orcs():Faction(){}
Orcs::Orcs(string n, int u, int a, int h, int r):Faction(n, u, a, h, r){} 


void Orcs::PerformAttack()
{
    // performing the attack to ALIVE enemies, 
    // according to the given criterion in pdf 
    
    Faction *d = this->getFirstEnemy();
    Faction *e = this->getSecondEnemy();
    
    int attack = this->getAttackPoint();
    int unit1 = this->getNumOfUnits() * 7 / 10;
    int unit2 = this->getNumOfUnits() - unit1;

    if (d->IsAlive() && e->IsAlive()) // if both are alive:
    {
        e->ReceiveAttack(this->getName(), unit1, attack);
        d->ReceiveAttack(this->getName(), unit2, attack);
        return;
    }

    if ( d->IsAlive() ) d->ReceiveAttack(this->getName(), unit1 + unit2, attack);
    if ( e->IsAlive() ) e->ReceiveAttack(this->getName(), unit1 + unit2, attack);
}

void Orcs::ReceiveAttack(string n, int units, int attackpt)
{
    //receiving attack from enemies and decreasing the number of units according to the given criteria in pdf

    if(n == "Elves") attackpt = attackpt * 3 / 4;
    if(n == "Dwarves") attackpt = attackpt * 4 / 5;

    this->setNumOfUnits(this->getNumOfUnits() - (units * attackpt / this->getHealthPoint()));
}

int Orcs::PurchaseWeapons(int w)
{
    // purchasing weapons and increasing the attack point according to pdf
    this->setAttackPoint(this->getAttackPoint() + w*2);
    return 20*w;
}

int Orcs::PurchaseArmors(int a)
{
    // purchasing armors and increasing the health point according to pdf
    this->setHealthPoint(this->getHealthPoint() + a*3);
    return a;
}

void Orcs::Print()
{
    cout << '"' << "Stop running, you'll only die tired!" << '"' << endl;
    // then calling the print function defined under the Faction class, to print statements common in every faction
    Faction::Print(); 
}


