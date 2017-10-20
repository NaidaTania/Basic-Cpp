/*
Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)

Write a program that allows the user to enter the grade scored in a programming class (0-100).
If the user scored a 100 then notify the user that they got a perfect score.

★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A

★★ Modify the program so that it will notify the user of their letter grade
0-59 F 60-69 D 70-79 C 80-89 B 90-100 A
*/

#include <iostream>

using namespace std;

int main(){
    int grade=-1;
    char letterGrade;
    cout << "Enter your grade:" << endl;

    cout << ">> ";
    cin >> grade;

    while(grade<0 or grade>100){
        cout << "Invalid input. Please try again." << endl;
        cout << ">> ";
        cin >> grade;
    }

    //Convert the grades to letters
    if(grade == 100){
        letterGrade = 'Z';
    }
    else if(grade < 100 and grade >= 90){
        letterGrade = 'A';
    }
    else if(grade < 90 and grade >= 80){
        letterGrade = 'B';
    }
    else if(grade < 80 and grade >= 70){
        letterGrade = 'C';
    }
    else if(grade < 70 and grade >= 60){
        letterGrade = 'D';
    }
    else{
        letterGrade = 'E';
    }

    switch(letterGrade){
        case 'Z':
        cout << "You scored A" << endl;
        cout << "CONGRATULATIONS!";
        break;
        default:
        cout << "You scored " << letterGrade << endl;
    }
}