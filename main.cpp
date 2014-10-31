#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

using namespace std;

//-----Functions for Craps (Move them to their own .h and .cpp later-----
int rollD6(){ //Returns rand num from 1 - 6
    int roll = rand() % (7 - 1) + 1;
    return roll;
}

void roll2D6(int &d1, int &d2){
    d1 = rollD6();
    d2 = rollD6();
    return;
}

int point(int sum){ //takes in sum of the last dice roll while point was OFF
    if( (sum == 4) || (sum == 5) || (sum == 6) ||
        (sum == 8) || (sum == 9) || (sum == 10) ){
	    return sum; //Point is a valid num, return that num back
	}
    return -1; //Point is not a valid num, return -1 to signify point is Black(OFF)
}

bool pointOn(int sum){
    if((point(sum) == -1)){ //Point returns -1 flag, so point is Off
	 return false;
    }
    return true; //Else point is On with a valid value, return true
}

int main(){
    //These functions will aim to return minimal ints/strings so they can be
    //implemented later on into a more "full" program that doesn't simply
    //print to the command line. This is intended to work out the logistics
    //of the craps game and algorithm. It should be noted that this program 
    //will not use truly random numbers, nor will it aim to teach a player
    //the game of craps; in order to play, you need to know how to play
    //beforehand.
    srand(time(0)); //Provides more random nums

    int d1;
    int d2;
    string input; //holds user input

    while(1){ //Loop until user exits
        cout << "$ "; //Prompt - FIXME - remove later/replace with something better? 
	cin >> input;
	
	if(input == "bet"){
	    
	}else if(input == "exit"){
	    cout << "Exiting..." << endl; //FIXME - Add an "are you sure" option?
	    return 0;
	}
	//Consider using enum and a string map to create switch statements
    }

    return 0;//Needed anymore? - FIXME - Dead code
}
