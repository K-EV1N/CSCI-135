/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1, Task A.
This program will ask the user for a input and it will print out the direction corresponding to each letter.  */

#include <iostream>
using namespace std;

int main() {
    string s;
    while(cin >> s) { // While the reading operation is a success
        if (s == "R") {     //if s equals to "R" from the user input
            cout << "Right" << endl;     //it will print out "Right"
        } else if (s == "D") {     //if s equals to "D" from the user input
            cout << "Down" << endl;     //it will print out "Down"
        } else if (s == "L") {     //if s equals to "L" from the user input
            cout << "Left" << endl;     //it will print out "Left"
        } else if (s == "U") {     //if s equals to "U" from the user input
            cout << "Up" << endl;     //it will print out "Up"
        }
    }
    return 0;
}
