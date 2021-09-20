//////////////////////////////////
/*    <Seniha Serra Bozkurt>    */
/*         <150190710>          */ 
//////////////////////////////////

#include "GreatWarrior.h"
#include "GreatWarrior.cpp" //INCLUDE THIS BEFORE SENDING!!
#include <iomanip>
#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std; 

/*	Define necessary classes and attributes in GreatWarrior.h and GreatWarrior.cpp */

/*	= Fill in the blanks in this main.cpp file. The parts that you need to implemented are specified below.
    = Please write your code between ///// FILL HERE ///// lines.
    = The expressions you need to print out with cout operation are given in necessary format.
    = You can use them directly by filling the variable parts.
*/

void listCharacters(CharacterList&);
void listLands(CharacterList&);
void readData(string, CharacterList&);
void printGameMenu();
bool endOfTurn(Character&, int);

int main() {
    cout << "Welcome to the Great Warriors. Create your character and attack other lands to be a great warrior.\n" << endl;

    CharacterList charList;             // list object to store the characters

    string fileName = "characters.txt"; // read characters.txt file
    readData(fileName, charList);

    /* creating player's character */
    string name, land, general;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter name of your capital: ";
    cin >> land;

    cout << "Enter name of your general: ";
    cin >> general;


    ///// FILL HERE /////

    /*  Create your constant general object and your own character object,
        then add your character into characters list */

    Character* me = new Character(name, 3, 20, 0);
    Land* myLand = new Land(land, "village");
    me->addLand(myLand);
    charList.addCharacter(me);
    bool call = true;

    ///// FILL HERE /////


    // In-game loop 
    int choice = 0, round = 0;
    while (choice != 6) {
        printGameMenu();

        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "You have rested in your palace." << endl;
            cout << "You've talked with your general " << general << "." << endl;
            call = endOfTurn(*me, round);
            round++;
            break;
        }
        case 2: {
            listLands(charList);
            cout << "Enter name of the land to attack." << endl;

            string land;
            cin >> land;

            ///// FILL HERE /////

            /*	Get the attacked player and execute the attack considering the manpower each side has:

                -	If you won, attacked side will lose all manpower and the attacked land will be yours. 
                    You will also lose some manpower (as much as attacked lose).
                    Print this: cout << "You've won the battle and conquered " << land << "." << endl;

                -	If you lose, you will lose all your manpower.
                    Print this: cout << "You've lost the battle and " << __number of manpower you lost__ << " manpower." << endl;
            */

            Character* landOwner = charList.getLandOwner(land);

            if(!landOwner)
                break;
            
            if (landOwner->getName() == me->getName())
            {
                cout << "PLEASE DONT FIGHT WITH YOUR OWN LAND!!" << endl;
                break;
            }
            
            int landOwnersManpower = landOwner->getManpower();
            int myManpower = me->getManpower();

            if(landOwnersManpower > myManpower)
            {
                // landOwner->setManpower(landOwnersManpower - myManpower); // no need, as the message board says
                me->setManpower(0);
                cout << "You've lost the battle and " << myManpower << " manpower." << endl;
            }
            else
            {
                landOwner->setManpower(0);
                me->setManpower(myManpower - landOwnersManpower);
                me->addLand(landOwner->removeLand(land));

                if(landOwner->getNumOfLands() == 0){
                    string nn = landOwner->getName();
                    cout<<nn<<endl;
                    charList.delCharacter(nn);
                }

                cout << "You've won the battle and conquered " << land << "." << endl;
            }
            call = endOfTurn(*me, round);

            ///// FILL HERE /////

            round++;
            break;
        }
        case 3:{
            cout << "How much manpower do you need? (1 manpower=5 gold)" << endl;

            int order;
            cin >> order;

            ///// FILL HERE /////

            /* Check if you have enough money to get the requested manpower:

                - 	If you have, you got the manpower you want.
                    Print this: cout << "Order successful. You have " << __number of manpower you have after purchase__ << " manpower." << endl;

                -	If you do not, print this: cout << "You do not have enough money." << endl;
            */

            int myGolds = me->getGold();

            if( myGolds >= (order * 5) )
            {
                me->setGold(myGolds - (order * 5));
                me->setManpower(me->getManpower() + order);
                cout << "Order successful. You have " << me->getManpower() << " manpower." << endl;
            }
            else
                cout << "You do not have enough money." << endl;

            ///// FILL HERE /////

            round++;
            break;
        }
        case 4:{
            listCharacters(charList);
            break;
        }
        case 5:{
            listLands(charList);
            break;
        }
        case 6:
            break;
        
        default:
            cout << "You entered an invalid value. Try again." << endl;
        }

        ///// FILL HERE /////
        
        /*	Check if the game is over in two cases:

            -	Call the endOfTurn function which is defined below in the code.
                endOfTurn function executes the necessary end of turn process and
                returns a bool value which indicates if you can continue the game or not.

            -	Terminate the program if you are the only great warrior left.
                Print this: cout << __your player name__ << " is the only great warrior now." << endl;
        */
        
        if (!call || charList.getSize() == 1 || choice == 6)
        {
            if((charList.getSize() == 1) && call)
                cout << me->getName() << " is the only great warrior now." << endl;
                
            return 0;
        }

        ///// FILL HERE /////
    }
    
    return 0;
}

void readData(string fileName, CharacterList& charList) {

    fstream dataFile(fileName.c_str());

    if (dataFile.is_open()) {

        string word;
        while (dataFile >> word) {

            string name, title;
            int money, manpower, numOfLands;

            name = word;
            dataFile >> manpower;
            dataFile >> money;
            dataFile >> numOfLands;

            ///// FILL HERE /////

            /* Create a new character with read data */

            Character* newChar = new Character(name, manpower, money, 0);
            
            ///// FILL HERE /////

            string landName, holding;

            for (int i = 0; i < numOfLands; i++) {
                dataFile >> landName;
                dataFile >> holding;

                ///// FILL HERE /////
                
                /* Create a new land object with read data and assign the land to the character you have created */
                
                Land* landPtr =  new Land(landName, holding);
                newChar->addLand(landPtr);

                ///// FILL HERE /////
            }

            ///// FILL HERE /////

            /* Add the character into character list */

            charList.addCharacter(newChar);

            ///// FILL HERE /////

        }

        dataFile.close();
    }
    else cout << "Unable to open the file" << endl;

    return;
}

void printGameMenu() {
    cout << endl;
    cout << "1. Stay in your palace" << endl;
    cout << "2. Attack to a land" << endl;
    cout << "3. Buy manpower" << endl;
    cout << "4. List characters" << endl;
    cout << "5. List lands" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void listCharacters(CharacterList& charList) {
    cout << endl;

    ///// FILL HERE /////

    /* Print out the names of each character in character list in a loop */

    for(int i = 0; i < charList.size; i++)
        cout << charList.characters[i].getName() << endl;
    
    ///// FILL HERE /////

}

void listLands(CharacterList& charList) {
    cout << endl;

    ///// FILL HERE /////

    /*	Loop over each character in characters list and print out their lands*/ 

    for(int i = 0; i < charList.size; i++)
    {
        string currentName = charList.characters[i].getName();
        Land* landPtr = charList.characters[i].getLands();

        for(int j = 0; j < charList.characters[i].getNumOfLands(); j++)
        {
            cout << landPtr->getName() << " " << landPtr->getHolding() << " owned by " << currentName << endl;
            landPtr = landPtr->next;
        }
    }

    ///// FILL HERE /////

    cout << endl;
}

bool endOfTurn(Character& player, int round) { //return a bool value that indicates if the game is over or not.

    ///// FILL HERE /////

    /* End of turn evaluations:
        -	Collect taxes and feed soldiers

        -	Check the number of lands you have and if you do not have any lands left, the game is over
            Print this:	cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
                        cout << endl;
                        cout << "GAME OVER." << endl;

        -	Check the number of manpower you have and if you do not have any manpower left, you lose one of your lands randomly.
            Print this:	cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;

        -	Check the amount of money you have, if you do not have enough money to feed your soldiers you lose
            the soldiers that you cannot feed. 1 gold for each soldier is needed. If you have 5 gold and 6 soldiers 1 soldier will
            run away from your army.
            Print this: cout << __number of runaway soldiers__ << " soldiers run away from your army because you don't have enough gold to feed them." << endl;

        -	At last, print your status in the following format:
            cout << "Turn " << round << ": " << " " << __name of your player__ << " has " << __number of lands you have__
        << " land(s), " << __number of manpower you have__ << " manpower and " << __number of golds you have__ << " golds." << endl;

    */

    (&player)->getTaxes(); // getting the taxes

    if((&player)->getNumOfLands() <= 0) // if we lost all our lands
    {
        cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
        cout << endl;
        cout << "GAME OVER." << endl;
        return false;
    }

    if ((&player)->getManpower() == 0) // if we don't have enough soldier
    {
        cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;
        Land* toDelete = (&player)->removeLand((&player)->getLands()->getName());
        delete toDelete;
    }
    
    (&player)->setGold((&player)->getGold() - (&player)->getManpower()); // feeding all of the soldiers

    if((&player)->getGold() < 0) // if we can't feed the army due to lack of gold, we'll feed as much soldier as we can
    {
        int lostSoldier = -(&player)->getGold();
        (&player)->setManpower((&player)->getManpower() - lostSoldier);
        (&player)->setGold(0);
        cout << lostSoldier << " soldiers run away from your army because you don't have enough gold to feed them." << endl;
    }
    cout << "Turn " << round << ": " << " " << (&player)->getName() << " has " << (&player)->getNumOfLands()
        << " land(s), " << (&player)->getManpower() << " manpower and " << (&player)->getGold() << " golds." << endl;
    
    return true;

    ///// FILL HERE /////

}
