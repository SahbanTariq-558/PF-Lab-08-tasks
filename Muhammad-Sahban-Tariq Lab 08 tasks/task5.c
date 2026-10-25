#include <stdio.h>

void printGrid(int (*grid)[5])
{
    int r, c;

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++)
            printf("%d ", grid[r][c]);

        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col)
{
    int r, c, count = 0;

    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < 5 && c >= 0 && c < 5) {
                if (!(r == row && c == col) && (grid[r][c] & 1))
                    count++;
            }
        }
    }

    return count;
}

void nextGeneration(int (*grid)[5])
{
    int r, c, neighbours;

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            neighbours = countNeighbours(grid, r, c);

            if (grid[r][c] & 1) {
                if (neighbours == 2 || neighbours == 3)
                    grid[r][c] |= 2;
            } else {
                if (neighbours == 3)
                    grid[r][c] |= 2;
            }
        }
    }

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++)
            grid[r][c] >>= 1;
    }
}

int main()
{
    int grid[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int generations, g;

    do {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &generations);

        if (generations < 0 || generations > 50)
            printf("Invalid number\n");
    } while (generations < 0 || generations > 50);

    printf("Generation 0:\n");
    printGrid(grid);

    for (g = 1; g <= generations; g++) {
        nextGeneration(grid);
        printf("Generation %d:\n", g);
        printGrid(grid);
    }

    return 0;
}