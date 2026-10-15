#include <stdio.h>
#include "budget.h"
#include "utilities.h"

double budget = 0;

void addBudget(void)
{
    printf("Budget amount: ");
    budget += readDouble();
}

double calculateBudgetBalance(void)
{
    return budget;
}
