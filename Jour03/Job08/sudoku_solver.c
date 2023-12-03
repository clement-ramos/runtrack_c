#include <stdio.h>

// Function to check if a number is safe to be placed in a cell
int is_safe(int grid[9][9], int row, int col, int num) {
    // Check if the number is already used in the same row or column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check the subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// recursive function to solve the sudoku
int solve_sudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // search for an empty cell
            if (grid[row][col] == 0) {
                // Try all possible numbers
                for (int num = 1; num <= 9; num++) {
                    if (is_safe(grid, row, col, num)) {
                        // Assign the number if it is safe
                        grid[row][col] = num;

                        if (solve_sudoku(grid)) {
                            return 1;  // find a solution
                        }

                        // Cancel the assignment if it is not a solution
                        grid[row][col] = 0;
                    }
                }

                return 0;  // No solution found
            }
        }
    }

    return 1;  // All cells are filled
}

int sudoku_solver(int grid[9][9]) {
    return solve_sudoku(grid);
}

int main() {
    int sudoku_grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (sudoku_solver(sudoku_grid)) {
        // Print the solution
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku_grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Aucune solution trouvée.\n");
    }

    return 0;
}
