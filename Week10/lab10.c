#include <stdio.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int addEmployee(Employee list[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("List is full.\n");
        return count;
    }
    printf("ID: ");
    scanf("%d", &list[count].id);
    printf("Name (one word): ");
    scanf("%29s", list[count].name);
    printf("Salary: ");
    scanf("%lf", &list[count].salary);
    return count + 1;
}

void displayEmployees(const Employee list[], int count)
{
    int i;
    printf("\n%-6s %-12s %10s\n", "ID", "Name", "Salary");
    for (i = 0; i < count; i++) {
        printf("%-6d %-12s %10.2f\n", list[i].id, list[i].name, list[i].salary);
    }
    printf("Records: %d\n", count);
}

void saveText(const Employee list[], int count)
{
    int i;
    FILE *fp = fopen("data/employees.txt", "w");
    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }
    for (i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n", list[i].id, list[i].name, list[i].salary);
    }
    fclose(fp);
    printf("Saved %d records to data/employees.txt\n", count);
}

int loadText(Employee list[])
{
    int count = 0;
    FILE *fp = fopen("data/employees.txt", "r");
    if (fp == NULL) {
        perror("data/employees.txt");
        return 0;
    }
    while (count < MAX_RECORDS &&
           fscanf(fp, " %d|%29[^|]|%lf",
                  &list[count].id, list[count].name, &list[count].salary) == 3) {
        count++;
    }
    fclose(fp);
    printf("Loaded %d records from data/employees.txt\n", count);
    return count;
}

void saveBinary(const Employee list[], int count)
{
    size_t written;
    FILE *fp = fopen("data/employees.dat", "wb");
    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }
    written = fwrite(list, sizeof list[0], (size_t)count, fp);
    if (written != (size_t)count) {
        perror("Error writing employees");
    }
    fclose(fp);
    printf("Saved %zu records to data/employees.dat\n", written);
}

int loadBinary(Employee list[])
{
    size_t n;
    FILE *fp = fopen("data/employees.dat", "rb");
    if (fp == NULL) {
        perror("data/employees.dat");
        return 0;
    }
    n = fread(list, sizeof list[0], MAX_RECORDS, fp);
    fclose(fp);
    printf("Loaded %zu records from data/employees.dat\n", n);
    return (int)n;
}

int main(void)
{
    Employee employees[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n--- MFMS Employee Storage ---\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Save (text)\n");
        printf("4. Load (text)\n");
        printf("5. Save (binary)\n");
        printf("6. Load (binary)\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: count = addEmployee(employees, count); break;
            case 2: displayEmployees(employees, count); break;
            case 3: saveText(employees, count); break;
            case 4: count = loadText(employees); break;
            case 5: saveBinary(employees, count); break;
            case 6: count = loadBinary(employees); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
