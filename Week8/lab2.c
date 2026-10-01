#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define EMPLOYEE_COUNT 5

/* Supplier storage (global so the supplier functions can share it) */
char names[MAX_SUPPLIERS][100];
char emails[MAX_SUPPLIERS][100];
char phones[MAX_SUPPLIERS][30];
char towns[MAX_SUPPLIERS][50];
int supplierCount = 0;

int employeeIDs[EMPLOYEE_COUNT] = {101, 102, 103, 104, 105};

/* Reusable calculation functions */
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

/* Menu and option functions */
void displayMenu();
void runSalary();
void runVAT();
void runBudget();
void runEmployeeSearch();
void supplierManagement();

/* Supplier functions */
void addSupplier();
void displaySupplier();
void searchSupplier();

/* Input helpers */
int readInt();
float readFloat();

int main()
{
    int choice;

    do
    {
        displayMenu();
        choice = readInt();
        if (choice == -1)
        {
            choice = 6;
        }

        switch (choice)
        {
        case 1:
            runSalary();
            break;
        case 2:
            runVAT();
            break;
        case 3:
            runBudget();
            break;
        case 4:
            runEmployeeSearch();
            break;
        case 5:
            supplierManagement();
            break;
        case 6:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

/* ---------- Calculation functions ---------- */

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}

/* ---------- Menu and option functions ---------- */

void displayMenu()
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void runSalary()
{
    float basic, housing, transport;

    printf("Basic salary: ");
    basic = readFloat();
    printf("Housing allowance: ");
    housing = readFloat();
    printf("Transport allowance: ");
    transport = readFloat();

    printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
}

void runVAT()
{
    float amount;

    printf("Enter amount: ");
    amount = readFloat();
    printf("VAT: %.2f\n", calculateVAT(amount));
}

void runBudget()
{
    float revenue, expenses, result;

    printf("Enter revenue: ");
    revenue = readFloat();
    printf("Enter expenses: ");
    expenses = readFloat();

    result = calculateBudget(revenue, expenses);
    printf("Budget balance: %.2f\n", result);

    if (result > 0)
    {
        printf("SURPLUS\n");
    }
    else if (result < 0)
    {
        printf("DEFICIT\n");
    }
    else
    {
        printf("BALANCED\n");
    }
}

void runEmployeeSearch()
{
    int id, position;

    printf("Enter employee ID: ");
    id = readInt();
    position = searchEmployee(id, employeeIDs, EMPLOYEE_COUNT);

    if (position != -1)
    {
        printf("Employee found at position %d.\n", position);
    }
    else
    {
        printf("Employee not found.\n");
    }
}

void supplierManagement()
{
    int choice;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");

        choice = readInt();
        if (choice == -1)
        {
            choice = 4;
        }

        switch (choice)
        {
        case 1:
            addSupplier();
            break;
        case 2:
            displaySupplier();
            break;
        case 3:
            searchSupplier();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

/* ---------- Supplier functions ---------- */

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full (%d suppliers).\n", MAX_SUPPLIERS);
        return;
    }

    printf("Enter supplier name: ");
    fgets(names[supplierCount], sizeof(names[supplierCount]), stdin);
    names[supplierCount][strcspn(names[supplierCount], "\n")] = '\0';

    printf("Enter email: ");
    fgets(emails[supplierCount], sizeof(emails[supplierCount]), stdin);
    emails[supplierCount][strcspn(emails[supplierCount], "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phones[supplierCount], sizeof(phones[supplierCount]), stdin);
    phones[supplierCount][strcspn(phones[supplierCount], "\n")] = '\0';

    printf("Enter town: ");
    fgets(towns[supplierCount], sizeof(towns[supplierCount]), stdin);
    towns[supplierCount][strcspn(towns[supplierCount], "\n")] = '\0';

    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    if (supplierCount == 0)
    {
        printf("No suppliers added yet.\n");
        return;
    }

    printf("\n--- SUPPLIER DETAILS ---\n");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
    }
}

void searchSupplier()
{
    char searchName[100];
    char description[300];
    int found = 0;

    if (supplierCount == 0)
    {
        printf("No suppliers added yet.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            printf("Supplier found.\n");
            printf("Name : %s\n", names[i]);
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town : %s\n", towns[i]);

            strcpy(description, names[i]);
            strcat(description, " operates in ");
            strcat(description, towns[i]);
            strcat(description, ".");
            printf("%s\n", description);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}

/* ---------- Input helpers ---------- */

/* Returns the number typed, 0 if invalid, -1 if input has ended */
int readInt()
{
    char line[50];
    int value = 0;

    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        return -1;
    }
    if (sscanf(line, "%d", &value) != 1)
    {
        return 0;
    }
    return value;
}

float readFloat()
{
    char line[50];
    float value = 0;

    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        return 0;
    }
    sscanf(line, "%f", &value);
    return value;
}
