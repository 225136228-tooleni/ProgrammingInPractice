#include <stdio.h>

int main() {
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    /* ================= A. EMPLOYEE SALARIES ================= */

    /* Capture 50 salaries */
    for (int i = 0; i < 50; i++) {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    /* Display all salaries */
    printf("\nEmployee Salaries\n");
    for (int i = 0; i < 50; i++) {
        printf("%.2f\n", salaries[i]);
    }

    /* Average, highest, lowest */
    float total = 0;
    float highest = salaries[0];
    float lowest = salaries[0];

    for (int i = 0; i < 50; i++) {
        total = total + salaries[i];

        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    printf("\n--- Salary Report ---\n");
    printf("Average salary: %.2f\n", total / 50);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    /* Linear search */
    float search;
    int found = 0;

    printf("\nEnter a salary to search for: ");
    scanf("%f", &search);

    for (int i = 0; i < 50; i++) {
        if (salaries[i] == search) {
            found = 1;
            printf("Value found at position %d\n", i);
            break;
        }
    }

    if (!found) {
        printf("Value not found.\n");
    }

    /* ================= B. DEPARTMENT BUDGETS ================= */

    /* Capture 10 budgets */
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter budget %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    /* Display budgets */
    printf("\nDepartment Budgets\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    /* Total and average */
    float totalBudget = 0;
    for (int i = 0; i < 10; i++) {
        totalBudget = totalBudget + budgets[i];
    }
    printf("\nTotal budget: %.2f\n", totalBudget);
    printf("Average budget: %.2f\n", totalBudget / 10);

    /* Bubble sort, lowest to highest */
    float temp;
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nSorted budgets (lowest to highest):\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    /* ================= C. VEHICLE REGISTRATIONS ================= */

    /* Capture 20 registrations */
    printf("\n");
    for (int i = 0; i < 20; i++) {
        printf("Enter vehicle registration: ");
        scanf("%19s", registrations[i]);
    }

    /* Display all registrations */
    printf("\nVehicle Registrations\n");
    for (int i = 0; i < 20; i++) {
        printf("%s\n", registrations[i]);
    }

    /* Search for a registration number */
    char target[20];
    int regFound = 0;

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", target);

    for (int i = 0; i < 20; i++) {
        int j = 0;

        /* compare character by character until they differ or the string ends */
        while (registrations[i][j] == target[j] && registrations[i][j] != '\0') {
            j++;
        }

        /* if both strings ended at the same point, they match */
        if (registrations[i][j] == target[j]) {
            regFound = 1;
            printf("Registration found at position %d\n", i);
            break;
        }
    }

    if (!regFound) {
        printf("Registration not found.\n");
    }

    return 0;
}
