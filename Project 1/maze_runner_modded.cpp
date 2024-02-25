/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1, Task D.
This program will read a text file containing a 10 by 10 array with all the directions in there. Once it reads the first ';', it will go to the
starting position and will read the directions, then it will compare all the directions and see if you are in or outside the maze.  */

#include <iostream>
#include <string>
using namespace std;

int main() {
    int maze[10][10];
    int start_row;
    int start_col;
    int exit_row;
    int exit_col;
    int row, col;
    char semi;
    
    string current_input;

    for(int row = 0; row < 10; row++) {     //the array we made is empty, this nested for loop loops through all the rows and columns and reads the
        for(col = 0; col < 10; col++ ) {    // .txt file and inputs the vaues onto our empty array.
            cin >> maze[row][col];
        }
    }

    cin >> start_row;     //reads the starting row from the .txt file which is 1
    cin >> start_col;     //reads the starting col from the .txt file which is 0
    cin >> exit_row;     //reads the exit row from the .txt file which is 9
    cin >> exit_col;     //reads the exit row from the .txt file which is 1
    cin >> semi;     //reads the character from the .txt file which is the first ;

    if(semi == ';') {     //if it runs to the first semicolon, it will set the row and column to the starting point.
        row = start_row;
        col = start_col;
    }

    while(cin >> current_input) {
        for(int i = 0; i < current_input.size(); i++) {
            char directions = current_input[i];
            if(directions == 'R') {
                if(col != 9 && maze[row][col+1] == 0) {     //if col != 9 AND location of maze[row][col+1] is 0, move to the right by 1. 
                    col++;
                }
            }
            if(directions == 'L') {
                if(col != 0 && maze[row][col-1] == 0) {     //if col != 0 AND location of maze[row][col-1] is 0, move to the left by 1.
                    col--;
                }
            }
            if(directions == 'U') {
                if(row != 0 && maze[row-1][col] == 0) {     //if row != 0 AND location of maze[row-1][col] is 0, the row moves up by 1.
                    row--;
                }
            }
            if(directions == 'D') {
                if(row != 9 && maze[row+1][col] == 0) {     //if row != 9 AND location of maze[row+1][col] is 0, the row moves down by 1.
                    row++;
                }
            }
            if(directions == ';') {
                if(row == exit_row && col == exit_col) {     //checks to see if the row and exit is at the exit
                    cout << "You got out of the maze." << endl;
                } else {
                    cout << "You are stuck in the maze." << endl;
                }
                row = start_row;     //sets the row back to the starting point
                col = start_col;     //sets the column back to the starting point
            }

        }

    }
    return 0;
}