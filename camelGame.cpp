// Alexis Muñoz, Angel Gonzalez
// 6 November 2015
// Camel Game
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;
int THIRST = 0; //gain 1 per turn (expect when you drink), lose if it goes to 7

int USERMILES= 0;
int NATIVEMILES= -20;
int TIREDNESS= 0; //if camel is over 8 of tiredness (increases 2x when traveling fast, increases normally when normal speed), it’ll have a chance to pass out and lose 2 turns?(increases 1 a turn)
int CANTEEN = 3;
const int GAMEMILES = 200;

void gitIntro();
//prints intro

char gitChoice();
//if Q is returned, the int main blows up

void gitEnemyMiles();
//advances AI at the end of most functions, unless it’s a random event from heatwave

void gitCanteen();
// just subtracts 1 from the canteen, error if you have no more water to drink (doesn’t waste a turn, so probably add gitChoice() at the end of the function to choose again

void gitStatus();
//miles traveled
//thirst/tiredness
//angry mob behind him miles
//canteen charges left

//Angel Functions unless it rekts me
void gitOasis();
//rand() % 20 + 1
//if it’s 1, refill canteen, fully rests camel and player

void gitFullMiles();
//function that determines if the player travels 15-30
//should have a chance at making a random event happen 

void gitMidMiles();
//function that makes the player travel 5-15
//void gitRest(); 
//asks the user if they want to rest for the night
//print camel is happy
//reset camel tiredness to 0
//reset thirst to 100
//increase native miles 7-14
void gitRested();

int main(){
    srand(time(0));
    bool done = false;
    char choice;
    gitIntro();
    
    while (done == false)
    {   
        
        if (NATIVEMILES >= USERMILES)
        {
            cout << "Natives caught up (should've warded the jungle)" << endl;
            done = true;
            
        }
        if (THIRST == 6)
        {
            cout << "Died of thirst (should've warded Baron)" << endl;
            done = true;
        }
        if (TIREDNESS == 8)
        {
            cout << "Your camel is dead from exhaustion (you animal abuser)" << endl;
            done = true;
        }
        if (THIRST == 4 || THIRST == 5)
        {
            cout << "Ughh... feel thirsty" << endl;
        }
        if (TIREDNESS >= 5 && TIREDNESS <= 7)
        {
            cout << "Your camel is feeling tired" << endl;
        }
        if (USERMILES - NATIVEMILES <= 15)
        {
                cout << "Natives are closing in!" << endl;
        }
           choice = gitChoice();
        choice = toupper(choice);
        
        if (choice == 'Q')
        {
            done = true;
        }
        while (choice == 'A' && done == false)
        {
            if (CANTEEN == 0)
            {
                cout << "Your canteen is empty, nothing to drink from" << endl;
            }
            else
            {
                cout << "You drink from your canteen" << endl;
                CANTEEN--;
            }
            choice = gitChoice();
            toupper(choice);           
        }
        if (done == false)
        {
            if (choice == 'B')
            {
            gitMidMiles();
            }
            else if (choice == 'C')
            {
                gitFullMiles();
            }
            else if (choice == 'D')
            {   
                gitRested();
            
            }
            else if (choice == 'E')
            {
                gitStatus();
            }
        }
    }
    return 0;
}    
void gitIntro()
{
    cout << "Welcome to Camel!" << endl;
       cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
       cout << "The natives want their camel back and are chasing you down! Survive " << endl;
       cout << "your desert trek and out run the natives." << endl;

    return;
}
char gitChoice(){
    char userChoice;
    cout << "A. Drink from your canteen.\n";
    cout << "B. Ahead moderate speed.\n";
    cout << "C. Ahead full speed.\n";
    cout << "D. Stop and rest.\n";
    cout << "E. Status check.\n";
    cout << "Q. Quit\n";
    cin >> userChoice;
    
    return userChoice;       
}
void gitCanteen(){
    int canteen;
    return;
}
void gitStatus(){

    int milesBehind = USERMILES - NATIVEMILES;
    cout << "You have traveled " << USERMILES << "." << endl;
    cout << "Your camel's tiredness is " << TIREDNESS << "." << endl;
    cout << "The natives are " << milesBehind << "miles behind you." << endl;
    cout << "Your canteen has " << CANTEEN << " drinks left." << endl;
    
    return;
}
void gitOasis(){
    int fullRest = rand() % 19 + 1;
    //if it’s 1, refill canteen, fully rests camel and player
    
    if (fullRest == 1)
    {
        CANTEEN = 3;
        THIRST = 0;
        TIREDNESS = 0;
    }
    return;
}
void gitFullMiles()
{
    int traveling = rand() % 14 + 16;
    int AItraveling = rand() % 6 + 7;
    int randomEffect = rand() % 3 + 1;
    
    if (randomEffect = 1)
    {
        if ( randomEffect = 2 )
        {
            cout << "Camel was recklessly going too fast!" << endl;
            cout << "It trips and spranged it's ankle on sand" << endl;
            traveling -= 5;//travels 5 miles less due to random effect
            cout << "You traveled for " << traveling << " miles" << endl;
            USERMILES += traveling;
            TIREDNESS += 1;
            
            NATIVEMILES += AItraveling;
            
            return;
        }
        else if ( randomEffect = 3 )
        {
            cout << "Heat wave, can't travel in this weather!" << endl;
            cout << "You rest for the day" << endl;
            
            THIRST = 0;
            TIREDNESS = 0;
            
            return;
        }
        else if ( randomEffect = 4 )
        {
            cout << "Fell off the camel because you went too fast!" << endl;
            traveling -= 10; // travel 10 miles less
            cout << "You traveled for " << traveling << " miles" << endl;
            USERMILES += traveling;
            TIREDNESS += 1;
            NATIVEMILES += AItraveling;
            return;
        }
       
    }
    
    cout << "You traveled for " << traveling << "miles" << endl;
    
    USERMILES += traveling;
    TIREDNESS += 2;
    
    NATIVEMILES += AItraveling;
    
    return;
}
void gitMidMiles()
{
    int traveling = rand() % 10 + 5;
    
    cout << "You traveled for " << traveling << endl;
    
    USERMILES += traveling;
    TIREDNESS += 1;
    
    int AItraveling = rand() % 6 + 7;
    NATIVEMILES += AItraveling;
    
    return;
}
void gitRested()
{

    cout << "Your camel is happy to know it has a caring master now" << endl;
    cout << "It'll be fully rested by morning" << endl;
    TIREDNESS = 0;
    
    int AItraveling = rand() % 6 + 7;
    NATIVEMILES += AItraveling;
    
    return;
}
/*~ Random events? 25% chance?
Camel went too fast! sprained it’s back
Heat wave, both parties don’t move and thirst/tiredness increases
Fell off the camel because you went too fast, travel (1-5) and loose the turn*/

