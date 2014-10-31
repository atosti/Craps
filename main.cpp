#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

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
    if((point(sum) == -1)){ //if point returns -1 flag, then the point is off
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
    int a = 0;
    int b = 0;
    roll2D6(a, b);
    cout << a << " " << b << endl;


    return 0;
}
