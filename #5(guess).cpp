/*
Bracketing Search
Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
psudo random numbers

Write a program that calculates a random number 1 through 100.
The program then asks the user to guess the number.
If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
The program must let the user continue to guess until the user correctly guesses the number.

★ Modify the program to output how many guesses it took the user to correctly guess the right number.

★★ Modify the program so that instead of the user guessing a number the computer came up with,
the computer guesses the number that the user has secretely decided.
The user must tell the computer whether it guesed too high or too low.

★★★★ Modify the program so that no matter what number the user thinks of (1-100)
the computer can guess it in 7 or less guesses.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

bool CheckPrev(int prev,int now);
bool GameBreak(int upper,int lower);

int main(){
    srand(time(NULL));
    int random_number;
    int guess;
    int num_of_guesses = 1;

    random_number = rand()%100 + 1;

    //cout << random_number << endl;

    cout << "Guess the number!" << endl;
    cout << ">> ";
    cin >> guess;

    while(guess != random_number){
        num_of_guesses++;
        if(guess>random_number){
        cout << "Too high!" << endl;
        }
        else {
            cout << "Too low!" << endl;
        }

        cout << "Guess again!" << endl;
        cout << ">> ";
        cin >> guess;
    }

    cout << "Correct!" << endl;
    cout << "The number is " << guess << endl;
    cout << "It only took you " << num_of_guesses
         << " guesses to guess it!" << endl;

    //Modification
    //note: doesn't have a thing to check if com guess the same number from before
    //but com won't guess the same number multiple times

    int user_rando;
    int com_answer;
    char high_low;
    cout << "\nLet's play another round!" << endl;
    cout << "This time, choose a random number! (1-100)" << endl;
    cout << ">> ";
    cin >> user_rando;

    while(user_rando<0 || user_rando > 100){
        cout << "Nooooo don't cheat!" << endl;
        cout << "Pick another number yo!" << endl;
        cout << ">> ";
        cin >> user_rando;
    }

    int high_limit = 100;
    int low_limit = 1;
    int tries = 0;
    int prev_ans = 0;

    com_answer = rand()%high_limit + low_limit;

    while(com_answer != user_rando && tries < 7){

        prev_ans = com_answer;

        cout << "I think the number is " << com_answer
             << " !" << endl;
        cout << "Too high (H) or too low(L)?" << endl;
        cout << ">> ";
        cin >> high_low;

        cout << "Okay, I will try again!\n" << endl;

        if(high_low == 'H'){
            high_limit = com_answer;
            cout << "Between " << low_limit
                 << " and " << high_limit << endl;
            //cout << "My previous guess is " << prev_ans << endl;
            if (GameBreak(high_limit,low_limit)){
                cout << "Oh no you lied!" << endl;
                tries = 7;
                break;
            }
            while(CheckPrev(prev_ans,com_answer)){
                com_answer = rand()%(high_limit-low_limit + 1) + low_limit;
            }
        }
        else if(high_low == 'L'){
            low_limit = com_answer;
            cout << "Between " << low_limit
                 << " and " << high_limit << endl;
            //cout << "My previous guess is " << prev_ans << endl;;
            if (GameBreak(high_limit,low_limit)){
                cout << "Oh no you lied!" << endl;
                tries = 7;
                break;
            }
            while(CheckPrev(prev_ans,com_answer)){
                com_answer = rand()%(high_limit-low_limit + 1) + low_limit;
            }
        }
        else{
            do{
                cout << "Don't tease meeeeee~" << endl;
                cout << "Too high (H) or too low(L)?" << endl;
                cout << ">> ";
                cin >> high_low;
            }
            while(high_low != 'H' && high_low != 'L');
        }

        tries++;
    }

    if(user_rando > high_limit || user_rando < low_limit){
        cout << "You don't play properly!" << endl;
        cout << "But I am a computer, so I get it anyway." << endl;
    }
    else{
        cout << "Oh I got it!" << endl;
    }
    cout << "It's " << user_rando << " !" << endl;
    cout << "\nThanks for playing!" << endl;

}

bool CheckPrev(int prev,int now){
    if(prev == now){
        return true;
    }
    return false;
}

bool GameBreak(int upper,int lower){
    if(upper == lower){
        return true;
    }
    return false;
}



