#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;

    do {
        printf("\nMunicipal Financial Management System\n");
        printf("1. Add employee\n");
        printf("2. List employees\n");
        printf("3. Add budget\n");
        printf("4. Employee report\n");
        printf("5. Budget report\n");
        printf("0. Exit\n");
        printf("Choice: ");
        choice = readInt();

        if (choice == 1) addEmployee();
        else if (choice == 2) listEmployees();
        else if (choice == 3) addBudget();
        else if (choice == 4) employeeReport();
        else if (choice == 5) budgetReport();
        else if (choice != 0) printf("Invalid option.\n");
    } while (choice != 0);

    return 0;
}
