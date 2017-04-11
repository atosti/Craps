/* This is software meant to simulate and analyze various dice craps strategies.
*/

#include <iostream> //inout
#include <ctime> //time
#include <cstdlib> //rand, srand

#define OFF 0
#define ON  1

using namespace std;

bool POINT = OFF; //The point, OFF/ON for active bets
unsigned int POINT_NUM = 0;

//Rolls a pair of dice
unsigned int roll(){
    unsigned int result = 0, d1 = 0, d2 = 0; //Dice 1, 2
    d1 = (rand() % 6) + 1;
    d2 = (rand() % 6) + 1;
    result = d1 + d2;
    return result;
}

bool is_valid_point(unsigned int num){
    if ((num == 4) ||
        (num == 5) ||
        (num == 6) ||
        (num == 8) ||
        (num == 9) ||
        (num == 10)){
            return true;
    }
    return false;
}

bool is_seven(unsigned int num){
    if(num == 7){
        return true;
    }
    return false;
}

void point_handler(unsigned int curr){
    if((!POINT) && (is_valid_point(curr))){
            POINT = ON;
            POINT_NUM = curr;
            //cout << "New point: " << POINT_NUM << endl;
        }else if (POINT && is_seven(curr)){
            POINT = OFF;
            POINT_NUM = 0;
            //cout << "Craps!" << endl;
        }else if(POINT && (curr == POINT_NUM)){
            POINT = OFF;
            POINT_NUM = 0;
            //cout << "Point made!" << endl;
        }
}

//Handles rolling specified num of dice
void roll_handler(unsigned int rolls){
    unsigned int curr = 0;
    for(unsigned int i = 0; i < rolls; i++){
        curr = roll();
        point_handler(curr);
        //cout << "Roll #" << i + 1 << ": " << curr << endl;
    }
    return;
}

int main(){
    srand(time(0));
    unsigned int rolls = 0;
    
    cout << "Welcome! Number of rolls to test? ";
    cin >> rolls;
    cout << endl;
    roll_handler(rolls);
    
    
    
    return 0;
}
