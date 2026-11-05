#include <stdio.h>
#include "records.h"

static Employee employees[MAX_RECORDS];
static Supplier suppliers[MAX_RECORDS];
static Asset assets[MAX_RECORDS];
static Budget budgets[MAX_RECORDS];
static Project projects[MAX_RECORDS];
static int employeeCount = 0;
static int supplierCount = 0;
static int assetCount = 0;
static int budgetCount = 0;
static int projectCount = 0;

static void readDate(Date *d, const char *label)
{
    printf("%s (day month year): ", label);
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

/* ---------- Employees ---------- */
static void addEmployee(void)
{
    Employee *e;
    if (employeeCount >= MAX_RECORDS) {
        printf("Employee list is full.\n");
        return;
    }
    e = &employees[employeeCount];
    printf("ID: ");               scanf("%d", &e->id);
    printf("Name (one word): ");  scanf("%29s", e->name);
    printf("Department: ");       scanf("%19s", e->department);
    printf("Salary: ");           scanf("%lf", &e->salary);
    employeeCount++;
}

static void displayEmployees(void)
{
    int i;
    printf("\n%-6s %-12s %-12s %10s\n", "ID", "Name", "Department", "Salary");
    for (i = 0; i < employeeCount; i++) {
        printf("%-6d %-12s %-12s %10.2f\n", employees[i].id, employees[i].name,
               employees[i].department, employees[i].salary);
    }
}

/* ---------- Suppliers ---------- */
static void addSupplier(void)
{
    Supplier *s;
    if (supplierCount >= MAX_RECORDS) {
        printf("Supplier list is full.\n");
        return;
    }
    s = &suppliers[supplierCount];
    printf("ID: ");               scanf("%d", &s->id);
    printf("Name (one word): ");  scanf("%39s", s->name);
    printf("Email: ");            scanf("%39s", s->email);
    printf("Phone: ");            scanf("%14s", s->phone);
    printf("Town: ");             scanf("%19s", s->town);
    supplierCount++;
}

static void displaySuppliers(void)
{
    int i;
    printf("\n%-6s %-15s %-22s %-12s %-10s\n", "ID", "Name", "Email", "Phone", "Town");
    for (i = 0; i < supplierCount; i++) {
        printf("%-6d %-15s %-22s %-12s %-10s\n", suppliers[i].id, suppliers[i].name,
               suppliers[i].email, suppliers[i].phone, suppliers[i].town);
    }
}

/* ---------- Assets ---------- */
static void addAsset(void)
{
    Asset *a;
    if (assetCount >= MAX_RECORDS) {
        printf("Asset list is full.\n");
        return;
    }
    a = &assets[assetCount];
    printf("ID: ");                      scanf("%d", &a->id);
    printf("Description (one word): ");  scanf("%39s", a->description);
    printf("Value (N$): ");              scanf("%lf", &a->value);
    readDate(&a->acquired, "Acquired");
    assetCount++;
}

static void displayAssets(void)
{
    int i;
    printf("\n%-6s %-15s %12s %s\n", "ID", "Description", "Value (N$)", "Acquired");
    for (i = 0; i < assetCount; i++) {
        printf("%-6d %-15s %12.2f %02d/%02d/%d\n", assets[i].id, assets[i].description,
               assets[i].value, assets[i].acquired.day, assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

/* ---------- Budgets ---------- */
static void addBudget(void)
{
    Budget *b;
    if (budgetCount >= MAX_RECORDS) {
        printf("Budget list is full.\n");
        return;
    }
    b = &budgets[budgetCount];
    printf("Department: ");  scanf("%19s", b->department);
    printf("Allocated: ");   scanf("%lf", &b->allocated);
    printf("Spent: ");       scanf("%lf", &b->spent);
    budgetCount++;
}

static void displayBudgets(void)
{
    int i;
    printf("\n%-12s %12s %12s %12s\n", "Department", "Allocated", "Spent", "Balance");
    for (i = 0; i < budgetCount; i++) {
        printf("%-12s %12.2f %12.2f %12.2f\n", budgets[i].department,
               budgets[i].allocated, budgets[i].spent,
               budgets[i].allocated - budgets[i].spent);
    }
}

/* ---------- Projects ---------- */
static void addProject(void)
{
    Project *p;
    if (projectCount >= MAX_RECORDS) {
        printf("Project list is full.\n");
        return;
    }
    p = &projects[projectCount];
    printf("ID: ");                  scanf("%d", &p->id);
    printf("Title (one word): ");    scanf("%39s", p->title);
    printf("Budget: ");              scanf("%lf", &p->budget);
    readDate(&p->startDate, "Start date");
    readDate(&p->endDate, "End date");
    projectCount++;
}

static void displayProjects(void)
{
    int i;
    printf("\n%-6s %-15s %12s %-12s %-12s\n", "ID", "Title", "Budget", "Start", "End");
    for (i = 0; i < projectCount; i++) {
        printf("%-6d %-15s %12.2f %02d/%02d/%d   %02d/%02d/%d\n", projects[i].id,
               projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month,
               projects[i].startDate.year, projects[i].endDate.day,
               projects[i].endDate.month, projects[i].endDate.year);
    }
}

/* ---------- Binary file: employees ---------- */
static void saveEmployees(void)
{
    size_t written;
    FILE *fp = fopen("employees.dat", "wb");
    if (fp == NULL) {
        perror("employees.dat");
        return;
    }
    written = fwrite(employees, sizeof employees[0], (size_t)employeeCount, fp);
    fclose(fp);
    printf("Saved %zu employees.\n", written);
}

static void loadEmployees(void)
{
    size_t n;
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        perror("employees.dat");
        return;
    }
    n = fread(employees, sizeof employees[0], MAX_RECORDS, fp);
    fclose(fp);
    employeeCount = (int)n;
    printf("Loaded %zu employees.\n", n);
}

int main(void)
{
    int choice;

    do {
        printf("\n=== MFMS ===  (Employees: %d, Suppliers: %d, Assets: %d, Budgets: %d, Projects: %d)\n",
               employeeCount, supplierCount, assetCount, budgetCount, projectCount);
        printf(" 1. Add employee      2. Display employees\n");
        printf(" 3. Add supplier      4. Display suppliers\n");
        printf(" 5. Add asset         6. Display assets\n");
        printf(" 7. Add budget        8. Display budgets\n");
        printf(" 9. Add project      10. Display projects\n");
        printf("11. Save employees   12. Load employees\n");
        printf(" 0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  addEmployee();      break;
            case 2:  displayEmployees(); break;
            case 3:  addSupplier();      break;
            case 4:  displaySuppliers(); break;
            case 5:  addAsset();         break;
            case 6:  displayAssets();    break;
            case 7:  addBudget();        break;
            case 8:  displayBudgets();   break;
            case 9:  addProject();       break;
            case 10: displayProjects();  break;
            case 11: saveEmployees();    break;
            case 12: loadEmployees();    break;
            case 0:  printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
