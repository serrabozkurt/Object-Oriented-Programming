#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "GreatWarrior.h"


using namespace std;


// LAND CLASS'S METHODS

Land::Land() // constructor
{
    name = ""; 
    holding = ""; 
    next = NULL;
}   

Land::Land(string n, string h) // constructor
{
    name = n;
    holding = h;
    next = NULL;
}


Land::Land(Land &land){ //copy constructor
    name = land.getName();
    holding = land.getHolding();
    next = land.next;
}


// CHARACTER CLASS'S METHODS:

Character::Character(string namee, int manpoww, int goldd, int numoflandss) // constructor
{
    name = namee;
    manpower = manpoww; gold = goldd; numOfLands = numoflandss;
    lands = NULL;
}

Character::Character(Character &c1) // copy constructor
{  
    this->gold = c1.getGold();
    this->manpower = c1.getManpower();
    this->numOfLands = 0;
    this->name = c1.getName();

    Land* x = c1.getLands();

    for(int i = 0; i < c1.getNumOfLands(); i++)
    {
        Land* newL = new Land(*x);
        this->addLand(newL);
        x = x->next;
    }
}

void Character::getTaxes(){
    Land* ptr = lands;
    while(ptr)
    {
        if(ptr->getHolding() == "village")
            gold += 5;

        if(ptr->getHolding() == "castle")
            gold += 7;

        if(ptr->getHolding() == "city")
            gold += 10;
    
        ptr = ptr->next;
    }
}

void Character::addLand(Land *land)
{
    if(!land){
        cout << "PLEASE PROVIDE A VALID LAND TO ADD TO THE CHARACTER!!" << endl;
        return;
    }

    if (numOfLands != 0)
    {
        Land* ptrLand = lands;

        for(int i = 0; i < (numOfLands - 1); i++)
            ptrLand = ptrLand->next;
        
        ptrLand->next = land;
        numOfLands++;
    }
    else
    {
        lands = land;
        numOfLands = 1;
    }
}

Land* Character::removeLand(string landName){
    
    numOfLands -= 1;
    Land* toReturn = lands;

    if(lands->getName() == landName)
    {
        if (numOfLands == 0)
            lands = NULL;

        else lands = lands->next;

        return toReturn;
    }

    while( toReturn->next->next && (toReturn->next->getName() != landName) )
        toReturn = toReturn->next;
    
    Land* landPtr = toReturn;

    if ( toReturn->next->getName() == landName )
    {
        toReturn = toReturn->next;

        if( toReturn->next )
            landPtr->next = toReturn->next;

        else landPtr->next = NULL;

        return toReturn;
    }
    else{
        cout << "PLEASE PROVIDE A VALID LAND TO REMOVE FROM THE CHARACTER!!" << endl;
    }
    return NULL;
}

Character::~Character() //destructor
{
    for(int i = 0; i < (numOfLands - 1); i++)
    {
        Land* landPtr = lands;
        lands = lands->next;
        delete landPtr;
    }
    delete lands;
}



// CHARACTERLIST CLASS'S METHODS


void CharacterList::addCharacter(Character* newChar)
{
    if(!newChar)
    {
        cout << "PLEASE PROVIDE A VALID CHARACTER TO ADD TO THE CHARACTER LIST!!" << endl;
        return; 
    }
    
    if (size == 0){
        characters = newChar;
        size = 1;
    }
    else
    {
        size++;

        Character *newHead = new Character [size];

        for (int i = 0; i < (size - 1); i++)
            newHead[i] = characters[i];
        
        newHead[size - 1] = *newChar;
        characters = newHead;
    }
}

void CharacterList::delCharacter(string name)
{
    size--;
    Character *newHead = new Character [size];
    int i = 0;

    while((i < size) && (characters[i].getName() != name))
    {
        newHead[i].setName(characters[i].getName());
        newHead[i].setGold(characters[i].getGold());
        newHead[i].setManpower(characters[i].getManpower());
        newHead[i].setNumOfLands(characters[i].getNumOfLands());
        newHead[i].setLands(characters[i].getLands());
        characters[i].setLands(NULL);
        characters[i].setNumOfLands(0);
        i++;
    }
        
    
    if(i == size && characters[i].getName() != name)
    {
        cout << "PLEASE PROVIDE A VALID CHARACTER TO DELETE FROM THE CHARACTER LIST!!" << endl;
        return; 
    }

    for (i; i < size; i++)
    {
        newHead[i].setName(characters[i+1].getName());
        newHead[i].setGold(characters[i+1].getGold());
        newHead[i].setManpower(characters[i+1].getManpower());
        newHead[i].setNumOfLands(characters[i+1].getNumOfLands());
        newHead[i].setLands(characters[i+1].getLands());
        characters[i+1].setLands(NULL);
        characters[i+1].setNumOfLands(0);
    }
    
    delete [] characters;

    characters = newHead;
}

Character* CharacterList::getPlayer(string name){
    int i = 0;
    while((i < size) && (characters[i].getName() != name))
        i++;

    if(i >= size)
    {
        cout << "PLEASE PROVIDE A VALID CHARACTER NAME TO GET THE CORRESPONDING PLAYER!!" << endl;
        return NULL;
    }
    return (characters+i);
}

Character* CharacterList::getLandOwner(string land)
{
    Character* curCharacter;
    Land* curLand;

    for(int j = 0; j < size; j++)
    {
        curCharacter = characters+j;
        curLand = curCharacter->getLands();

        for(int i = 0; i < curCharacter->getNumOfLands(); i++)
        {
            if(curLand->getName() == land)
                break;

            curLand = curLand->next;
        }
        
        if(curLand && (curLand->getName() == land))
            break;
    }

    if(curLand && (curLand->getName() == land))
        return curCharacter;
    
    cout << "PLEASE PROVIDE A VALID LAND NAME TO GET THE OWNER OF IT!!" << endl;
    return NULL;
}

CharacterList::~CharacterList(){
    delete [] characters;
}

