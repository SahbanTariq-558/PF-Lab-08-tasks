#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[])
{
    int r, c;

    for (r = 0; r < rows; r++) {
        totals[r] = 0;

        for (c = 0; c < 3; c++)
            totals[r] += marks[r][c];
    }
}

int findTopper(const int *totals, int rows)
{
    int i, topIndex = 0;

    for (i = 1; i < rows; i++) {
        if (*(totals + i) > *(totals + topIndex))
            topIndex = i;
    }

    return topIndex;
}

int main()
{
    int marks[3][3];
    int totals[3];
    int r, c, topper;

    for (r = 0; r < 3; r++) {
        printf("Enter marks for Student %d (3 subjects): ", r + 1);

        for (c = 0; c < 3; c++)
            scanf("%d", &marks[r][c]);
    }

    computeTotals(marks, 3, totals);

    for (r = 0; r < 3; r++)
        printf("Total for Student %d: %d\n", r + 1, totals[r]);

    topper = findTopper(totals, 3);

    printf("Student %d is the topper with total %d\n",
           topper + 1, totals[topper]);

    return 0;
}