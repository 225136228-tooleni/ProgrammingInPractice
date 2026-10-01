#include <stdio.h>
#include <string.h>

int main()
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];
    char searchName[100];
    char backup[100];
    char description[300];

    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";

    /* ===== TASK 1: Basic Supplier Details ===== */
    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    /* ===== TASK 2: String Length ===== */
    printf("\nSupplier name length: %zu\n", strlen(supplierName));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    /* ===== TASK 3: Supplier Search ===== */
    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(searchName, supplier1) == 0 || strcmp(searchName, supplier2) == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    /* ===== TASK 4: Copying Supplier Information ===== */
    strcpy(backup, supplierName);
    printf("\nOriginal: %s\n", supplierName);
    printf("Backup  : %s\n", backup);

    /* ===== TASK 5: Construct a Supplier Description ===== */
    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");
    printf("\n%s\n", description);

    return 0;
}
