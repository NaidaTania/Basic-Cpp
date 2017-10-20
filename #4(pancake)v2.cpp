/*
Pancake Glutton

Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
arrays

Write a program that asks the user to enter the number of pancakes eaten
for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
Once the data has been entered the program must analyze
the data and output which person ate the most pancakes for breakfast.

★ Modify the program so that it also outputs which person ate the least number of pancakes for breakfast.

★★★★ Modify the program so that it outputs a list in order of number of pancakes eaten of all 10 people.
i.e.
Person 4: ate 10 pancakes
Person 3: ate 7 pancakes
Person 8: ate 4 pancakes
...
Person 5: ate 0 pancakes
*/

#include <iostream>
#include <string>

using namespace std;

bool swapAsc(int num1, int num2);
bool swapDsc(int num1, int num2);

int main(){
    int pancake_numbers[10];
    string pancake_eaters[10];
    int temp;
    string temp2;

    for (int name = 0; name<10;name++){
        cout << "Who is eating pancake?" << endl;
        cout << ">> ";
        cin >> pancake_eaters[name];
        cout << "How many pancakes does " << pancake_eaters[name] << " eat?" << endl;
        cout << ">> ";
        cin >> pancake_numbers[name];
    }

    //Bubble sort
    for(int loop = 0;loop<10;loop++){
        for(int index = 1;index<10;index++){
            if(swapDsc(pancake_numbers[index-1],pancake_numbers[index])){
                //Swap the numbers
                temp = pancake_numbers[index-1];
                pancake_numbers[index-1] = pancake_numbers[index];
                pancake_numbers[index] = temp;

                //Swap the eaters
                temp2 = pancake_eaters[index-1];
                pancake_eaters[index-1] = pancake_eaters[index];
                pancake_eaters[index] = temp2;
            }
        }
    }

    for(int index = 0;index<10;index++){
        cout << pancake_eaters[index] << " ate ";
        cout << pancake_numbers[index] << " pancakes" << endl;
    }
}

bool swapAsc(int num1, int num2){
    if(num1 > num2){
        return true;
    }
    return false;
}

bool swapDsc(int num1, int num2){
    if(num1 < num2){
        return true;
    }
    return false;
}
