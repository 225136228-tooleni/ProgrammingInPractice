#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

/* Supplier storage (global so the supplier functions can share it) */
char names[MAX_SUPPLIERS][100];
char emails[MAX_SUPPLIERS][100];
char phones[MAX_SUPPLIERS][30];
char towns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* Supplier functions */
void addSupplier();
void displaySupplier();
void searchSupplier();

/* Financial functions */
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

/* Menu function */
void displayMenu();

/* Input helpers */
int readInt();
float readFloat();

int main()
{
    int choice;
    float amount, basic, housing, transport, revenue, expenses, result;

    do
    {
        displayMenu();
        choice = readInt();
        if (choice == -1)
        {
            choice = 7;
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
            printf("Enter amount: ");
            amount = readFloat();
            printf("VAT: %.2f\n", calculateVAT(amount));
            break;
        case 5:
            printf("Basic salary: ");
            basic = readFloat();
            printf("Housing allowance: ");
            housing = readFloat();
            printf("Transport allowance: ");
            transport = readFloat();
            printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
            break;
        case 6:
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
            break;
        case 7:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

/* ---------- Menu function ---------- */

void displayMenu()
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

/* ---------- Financial functions ---------- */

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
