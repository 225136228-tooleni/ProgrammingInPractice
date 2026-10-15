#include <stdio.h>
#include "employees.h"
#include "utilities.h"

#define MAX 100

int ids[MAX];
char names[MAX][50];
double salaries[MAX];
int count = 0;

void addEmployee(void)
{
    if (count >= MAX) {
        printf("List is full.\n");
        return;
    }
    printf("ID: ");
    ids[count] = readInt();
    printf("Name: ");
    scanf("%49s", names[count]);
    printf("Salary: ");
    salaries[count] = readDouble();
    count++;
}

void listEmployees(void)
{
    int i;
    for (i = 0; i < count; i++) {
        printf("%d %s %.2f\n", ids[i], names[i], salaries[i]);
    }
}

double calculatePayrollTotal(void)
{
    double total = 0;
    int i;
    for (i = 0; i < count; i++) {
        total += salaries[i];
    }
    return total;
}

int getEmployeeCount(void)
{
    return count;
}
