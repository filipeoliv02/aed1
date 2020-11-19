#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pr01.h"
#include "pr00.h"


int main(int argc, char *argv[]) {
    int c, lo, hi, middle, n, search, array[100];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("Enter value to find\n");
    scanf("%d", &search);

    lo = 0;
    hi = n - 1;                     //porque o array comeca a contar em 0
    middle = (lo + hi) / 2;

    while (lo <= hi) {
        if (array[middle] < search)
            lo = middle + 1;
        else if (array[middle] == search) {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        } else
            hi = middle - 1;

        middle = (lo + hi) / 2;
    }
    if (lo > hi)
        printf("Not found! %d isn't present in the list.\n", search);
    return 0;
}

