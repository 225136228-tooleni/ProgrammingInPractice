#include <stdio.h>

#define MAX_EMPLOYEES 5

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

void swapWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void displaySalaries(const double salaries[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];
    int i;
    for (i = 1; i < n; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
    }
    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        total += salaries[i];
    }
    return total / n;
}

void giveRaise(double salaries[], int n, double percent)
{
    int i;
    for (i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id)
{
    int i;
    for (i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }
    return NULL;
}

int main(void)
{
    double a = 18500.50;
    double b = 21000.75;
    double salaries[3] = {15000.00, 18500.50, 21000.75};
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna", 21000.75}
    };
    int count = 3;
    int id;
    double newSalary;
    Employee *found;

    printf("--- Part B: swap salaries ---\n");
    swapWrong(a, b);
    printf("After swapWrong:    A = %.2f, B = %.2f\n", a, b);
    swapSalaries(&a, &b);
    printf("After swapSalaries: A = %.2f, B = %.2f\n", a, b);

    printf("\n--- Part C: arrays and functions ---\n");
    printf("Before raise:\n");
    displaySalaries(salaries, 3);
    printf("Highest: N$%.2f | Average: N$%.2f\n",
           findHighest(salaries, 3), calculateAverage(salaries, 3));
    giveRaise(salaries, 3, 10.0);
    printf("After 10%% raise:\n");
    displaySalaries(salaries, 3);

    printf("\n--- Part D: update employee salary ---\n");
    printf("Employee ID to update (0 to stop): ");
    scanf("%d", &id);
    while (id != 0) {
        found = findEmployee(staff, count, id);
        if (found != NULL) {
            printf("New salary for %s: ", found->name);
            scanf("%lf", &newSalary);
            updateSalary(found, newSalary);
            printf("Updated: %d | %s | N$%.2f\n", found->id, found->name, found->salary);
        } else {
            printf("Employee %d not found.\n", id);
        }
        printf("Employee ID to update (0 to stop): ");
        scanf("%d", &id);
    }

    return 0;
}
