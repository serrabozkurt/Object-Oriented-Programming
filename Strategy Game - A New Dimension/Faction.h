//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#pragma once
#include <iostream> 
#include <stdlib.h>
#include <cstring>
using namespace std;

class Faction
{
    string name;
    Faction *firstEnemy, *secondEnemy;
    int numOfUnits, attackPoint, healthPoint, unitRegen, totalHealth;
    bool flag;
    
public:
    Faction();                              // constructor
    Faction(string, int, int, int, int);    // constructor

    //wanted methods
    void AssignEnemies(Faction*, Faction*);
    virtual void PerformAttack() = 0;
    virtual void ReceiveAttack(string, int, int) = 0;
    virtual int PurchaseWeapons(int) = 0;
    virtual int PurchaseArmors(int) = 0;
    virtual void Print();
    void EndTurn();
    
    bool IsAlive(){return flag;}

    //getter and setter methods 
    string getName(){return name;}
    void setName(string n){name = n;}

    int getNumOfUnits(){return numOfUnits;}
    void setNumOfUnits(int n){numOfUnits = n;}

    int getAttackPoint(){return attackPoint;}
    void setAttackPoint(int n){attackPoint = n;}

    int getHealthPoint(){return healthPoint;}
    void setHealthPoint(int n){healthPoint = n;}

    int getUnitRegen(){return unitRegen;}
    void setUnitRegen(int n){unitRegen = n;}

    int getTotalHealth(){return totalHealth;}
    void setTotalHealth(){totalHealth = numOfUnits * healthPoint;}
    
    Faction* getFirstEnemy(){return firstEnemy;}
    void setFirstEnemy(Faction* n){firstEnemy = n;}

    Faction* getSecondEnemy(){return secondEnemy;}
    void setSecondEnemy(Faction* n){secondEnemy = n;}
};
