#include <iostream>
#include <ctime>
using namespace std;

//Checks whether the player's input matches the answer
bool winCondition(int in1,int in2,int in3, int ran1, int ran2, int ran3) {
    if(in1 == ran1 && in2 == ran2 && in3 == ran3) {
        return true;
    }
    return false;
}

//Validates that the player has inputted a possible number
bool inputVal(int inMain, int in1, int in2, int in3) {
    if (inMain < 111 || inMain > 999) {
        return false;
    }
    if (in1 == 0 || in2 == 0 || in3 == 0) {
        return false;
    }
    return true;
}

//Prints the "Green-Yellow_Red" thingymabob
void printColours(int in1,int in2,int in3, int ran1, int ran2, int ran3) {
    if (in1 == ran1) {
        cout << "Green ";
    }
    if (in2 == ran2) {
        cout << "Green ";
    }
    if (in3 == ran3) {
        cout << "Green ";
    }
    if (in1 == ran2 || in1 == ran3) {
        cout << "Yellow ";
    }
    if (in2 == ran1 || in2 == ran3) {
        cout << "Yellow ";
    }
    if (in3 == ran1 || in3 == ran2) {
        cout << "Yellow ";
    }
    if (in1 != ran1 && in1 != ran2 && in1 != ran3 && in2 != ran1 && in2 != ran2 && in2 != ran3 && in3 != ran1 && in3 != ran2 && in3 != ran3) {
        cout << "Red";
    }
}


int main() {
    cout << "Welcome to Mastermind!" << endl << "I am thinking of a 3 digit number, no repeated digits." << endl <<
            "Can you guess what I'm thinking? You have 10 guesses...";


    //Generates three random digits with no repeated digits
    //I wanted to make this a function, but it's weirdly simpler when it stays in the main.
    srand(time(nullptr));
    int ran1 = 1 + rand () % 9;
    int ran2 = 1 + rand () % 9;
    int ran3 = 1 + rand () % 9;
    while (ran2 == ran1) {
        ran2 = 1 + rand () % 9;
    }
    while (ran3 == ran1 || ran3 == ran2) {
        ran3 = 1 + rand () % 9;
    }

    //Main game loop
    int in1 = 0,in2 = 0,in3 = 0;
    int inMain;
    int i = 0;
    while (winCondition(in1, in2, in3, ran1, ran2, ran3) == false) {

        //Generates the three integer digits based off of the player input
        cout << endl << endl << "Enter your 3 digit guess using 1-9 only: ";
        cin >> inMain;
        i++;
        in3 = inMain % 10;
        in2 = (inMain / 10) % 10;
        in1 = (inMain / 100) % 10;

        if (inputVal(inMain, in1, in2, in3)) {
            cout << "Guess " << i << ": " << inMain << "    ";

            //Prints the "Green-Yellow_Red" thingymabob
            printColours(in1, in2, in3, ran1, ran2, ran3);

        } else {
            cout << "Please enter as a valid number";
        }
    }
    cout << endl << endl << "Congratulations! You took " << i << " guesses.";

    return 0;
}