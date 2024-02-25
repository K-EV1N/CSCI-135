/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1, Task C.
This program will read a text file and reads each line of directions, compare it in the if statements, and moves down to the next line after a ";"
then it will keep looping to see where you are at in the maze, if you are at row 4, col 5, you are out of the maze, if not, you are stuck  */

#include <iostream> 
#include <string>
using namespace std;

int main () {
    int maze[6][6] = {
   1,0,1,1,1,1,
   1,0,0,0,1,1,
   1,0,1,0,0,1,
   1,0,1,0,1,1,
   1,0,0,0,0,0,
   1,1,1,1,1,1
};
string s;
int row, col;
row = 0;     //sets the row 
col = 1;     //sets the column


while (getline(cin, s, ';')) { // While the reading operation is a success
    for(int i = 0; i < s.size(); i++) {     //reads each letter 
        char direction = s[i];     //stores the letter that its currently reading into direction
        if(direction == 'R') {
            if(col != 5 && maze[row][col+1] == 0) {     //if col != 5 AND location of maze[row][col+1] is 0, move to the right by 1. 
                col++;
            }
        }
        else if(direction == 'L') {
            if(col != 0 && maze[row][col-1] == 0) {     //if col != 0 AND location of maze[row][col-1] is 0, move to the left by 1.
                col--;
            }
        }
        else if(direction == 'U') {
            if(row != 0 && maze[row-1][col] == 0) {     //if row != 0 AND location of maze[row-1][col] is 0, the row moves up by 1.
                row--;
            }
        }
        else if(direction == 'D') {
            if(row != 5 && maze[row+1][col] == 0) {     //if row != 5 AND location of maze[row+1][col] is 0, the row moves down by 1.
                row++;
            }
        }
        
    }
    if (row == 4 && col == 5) {     //this is the exit of the maze so if its true, it will print out "you made it out".
    cout << "You got out of the maze." << endl;
}   else {
    cout << "You are stuck." << endl;
    }

    
}
    return 0;
}