#include <iostream>
using namespace std;

int grid[9][9] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

// Print the Sudoku board
void printGrid() {
    for(int r=0; r<9; r++) {
        for(int c=0; c<9; c++) {
            cout << grid[r][c] << " ";
            if((c+1)%3==0 && c!=8) cout << "| ";
        }
        cout << endl;
        if((r+1)%3==0 && r!=8) cout << "---------------------\n";
    }
}

// Check if it's safe to put 'num' in grid[row][col]
bool isSafe(int row, int col, int num) {
    for(int i=0;i<9;i++) {
        if(grid[row][i]==num || grid[i][col]==num) return false;
    }
    int startRow = row - row%3, startCol = col - col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[startRow+i][startCol+j]==num) return false;
    return true;
}

// Find an empty cell, return true if found
bool findEmpty(int &row, int &col) {
    for(row=0; row<9; row++)
        for(col=0; col<9; col++)
            if(grid[row][col]==0) return true;
    return false;
}

// Backtracking Sudoku solver
bool solveSudoku() {
    int row, col;
    if(!findEmpty(row,col)) return true; // Base case: solved

    for(int num=1; num<=9; num++) {
        if(isSafe(row,col,num)) {
            grid[row][col] = num;
            if(solveSudoku()) return true;
            grid[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    cout << "--- Unsolved Sudoku ---\n";
    printGrid();

    if(solveSudoku()) {
        cout << "\n--- Solved Sudoku ---\n";
        printGrid();
    } else {
        cout << "\nNo solution exists.\n";
    }
    return 0;
}
