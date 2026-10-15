#include <stdio.h>
#include "utilities.h"

int readInt(void)
{
    int n;
    scanf("%d", &n);
    return n;
}

double readDouble(void)
{
    double d;
    scanf("%lf", &d);
    return d;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
