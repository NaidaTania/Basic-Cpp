/*
Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)

Write a program that presents the user w/ a choice of your 5 favorite beverages
(Coke, Water, Sprite, ... , Whatever).
Then allow the user to choose a beverage by entering a number 1-5.
Output which beverage they chose.

★ If you program uses if statements instead of a switch statement, modify it to use a switch statement.
If instead your program uses a switch statement, modify it to use if/else-if statements.

★★ Modify the program so that if the user enters a choice other than 1-5
then it will output "Error. choice was not valid, here is your money back."
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Welcome to Yuki's drink stall" << endl;
    string arrayDrinks[5] = {"Orange Juice","Coke","Lemonade","Beer","Ice Cream"};
    int choiceDrink;
    int count=0;

    for(int drink=1;drink<6;drink++){
        cout << drink << ". " << arrayDrinks[drink-1] << endl;
    }

    cout << "Pick the number of your favorite drink!" << endl;
    cout << ">> ";
    cin >> choiceDrink;

    while((choiceDrink < 1 || choiceDrink > 5) && count < 4){
        cout << "That is an invalid option. Please try again." << endl;
        cout << ">> ";
        cin >> choiceDrink;
        count++;
    }

    switch (choiceDrink){
        case(1):
        cout << "You have ordered " << arrayDrinks[0] << endl;
        cout << "That will be $2.30" << endl;
        break;
        case(2):
        cout << "You have ordered " << arrayDrinks[1] << endl;
        cout << "That will be $3.40" << endl;
        break;
        case(3):
        cout << "You have ordered " << arrayDrinks[2] << endl;
        cout << "That will be $1.70" << endl;
        break;
        case(4):
        cout << "You have ordered " << arrayDrinks[3] << endl;
        cout << "That will be $5.55" << endl;
        break;
        case(5):
        cout << "You have ordered " << arrayDrinks[4] << endl;
        cout << "That will be $1.15" << endl;
        break;
        default:
        cout << "You have broken the machine" << endl;
        cout << "BAI" << endl;

    }

    cout << "\nNow welcome to Shio's drink stall!" << endl;
    string shio_drinks[5] = {"Salt","70\% salt","50\% salt","20\% salt","no salt for you"};

    int shio_choice;

    for(int drink=1;drink<6;drink++){
        cout << drink << ". " << shio_drinks[drink-1] << endl;
    }

    cout << "Choose the number of your favorite drink!" << endl;
    cout << ">> ";
    cin >> shio_choice;

    if(shio_choice < 1 || shio_choice > 5){
        cout << "Error. choice was not valid, here is your money back." << endl;
        cout << "Lol jk haha." << endl;
    }
    else{
        cout << "You have ordered " <<  shio_drinks[shio_choice] << endl;
        cout << "Take it and gettout." << endl;
        cout << "kthxbai" << endl;
    }

}