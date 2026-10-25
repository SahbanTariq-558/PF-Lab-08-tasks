#include <stdio.h>

int square(int x)
{
    return x * x;
}

int negate(int x)
{
    return -x;
}

int isEven(int x)
{
    return x % 2 == 0;
}

int isPositive(int x)
{
    return x > 0;
}

void applyToArray(int *arr, int n, int (*fn)(int))
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = fn(arr[i]);
}

int countIf(const int *arr, int n, int (*pred)(int))
{
    int i, count = 0;

    for (i = 0; i < n; i++) {
        if (pred(arr[i]))
            count++;
    }

    return count;
}

void printGeneric(void *data, char type, int n)
{
    int i;

    if (type == 'i') {
        int *values = (int *)data;

        for (i = 0; i < n; i++)
            printf("%d ", values[i]);
    } else if (type == 'f') {
        float *values = (float *)data;

        for (i = 0; i < n; i++)
            printf("%.2f ", values[i]);
    } else if (type == 'c') {
        char *values = (char *)data;

        for (i = 0; i < n; i++)
            printf("%c ", values[i]);
    } else {
        printf("Invalid type '%c' for printGeneric\n", type);
        return;
    }

    printf("\n");
}

int main()
{
    int arr[] = {3, -2, 8, -5, 6};
    float decimals[] = {1.50, 2.25};
    char letters[] = {'A', 'B', 'C'};
    int n;

    do {
        printf("Enter n (1-5): ");
        scanf("%d", &n);

        if (n < 1 || n > 5)
            printf("Invalid n\n");
    } while (n < 1 || n > 5);

    printf("Original: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);

    printf("After negate: ");
    printGeneric(arr, 'i', n);

    printf("Positive values after negate: %d\n",
           countIf(arr, n, isPositive));
    printf("Even values after negate: %d\n",
           countIf(arr, n, isEven));

    printf("Float print (type f): ");
    printGeneric(decimals, 'f', 2);

    printf("Char print (type c): ");
    printGeneric(letters, 'c', 3);

    printGeneric(arr, 'x', n);

    return 0;
}