#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    int capacity = 2;
    int count = 0;
    int newCapacity;
    int i;
    int searchId;
    int foundFlag = 0;
    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    employees = malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0) {
        printf("Name (one word): ");
        scanf("%29s", e.name);
        printf("Salary: ");
        scanf("%lf", &e.salary);

        if (count == capacity) {
            newCapacity = capacity * 2;
            bigger = realloc(employees, newCapacity * sizeof(Employee));
            if (bigger == NULL) {
                printf("Out of memory!\n");
                free(employees);
                return 1;
            }
            employees = bigger;
            capacity = newCapacity;
            printf(" (grown to %d slots)\n", capacity);
        }

        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    for (i = 0; i < count; i++) {
        printf("%d %s N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("Employees: %d | Capacity: %d\n", count, capacity);

    printf("\nSearch employee by ID (0 to skip): ");
    scanf("%d", &searchId);
    if (searchId != 0) {
        for (i = 0; i < count; i++) {
            if (employees[i].id == searchId) {
                printf("Found: %d %s N$%.2f\n", employees[i].id, employees[i].name,
                       employees[i].salary);
                foundFlag = 1;
                break;
            }
        }
        if (!foundFlag) {
            printf("Employee %d not found.\n", searchId);
        }
    }

    free(employees);
    employees = NULL;
    return 0;
}
