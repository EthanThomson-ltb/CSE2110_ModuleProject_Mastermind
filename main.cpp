#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool winCondition(int in1,int in2,int in3, int ran1, int ran2, int ran3) {
    if(in1 == ran1 && in2 == ran2 && in3 == ran3) {
        return true;
    }
    return false;
}

bool inputVal(int inMain, int in1, int in2, int in3) {
    if (inMain < 111 || inMain > 999) {
        return false;
    }
    if (in1 == 0 || in2 == 0 || in3 == 0) {
        return false;
    }
    return true;
}

int main() {
    cout << "Welcome to Mastermind!" << endl << "I am thinking of a 3 digit number, no repeated digits." << endl <<
            "Can you guess what I'm thinking? You have 10 guesses..." << endl;

    srand(time(nullptr));
    int ran1 = 1 + rand () % 9;
    int ran2 = 1 + rand () % 9;
    int ran3 = 1 + rand () % 9;
    cout << ran1 << " " << ran2 << " " << ran3 << endl;


    int in1 = 0,in2 = 0,in3 = 0;
    int inMain;
    int i = 0;
    while (winCondition(in1, in2, in3, ran1, ran2, ran3) == false) {

        cout << endl << "Enter your 3 digit guess using 1-9 only: ";
        cin >> inMain;
        i++;
        in3 = inMain % 10;
        in2 = (inMain / 10) % 10;
        in1 = (inMain / 100) % 10;
        if (inputVal(inMain, in1, in2, in3)) {
            cout << "Guess " << i << ": " << inMain << "    ";


        } else {
            cout << "Please enter as a valid number" << endl;
        }
    }
    cout << endl << endl << "Congratulations! You took " << i << " guesses.";

    return 0;
}