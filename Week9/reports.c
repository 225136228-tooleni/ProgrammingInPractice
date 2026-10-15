#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    printf("Employees: %d\n", getEmployeeCount());
    printf("Total payroll: %.2f\n", calculatePayrollTotal());
}

void budgetReport(void)
{
    printf("Budget balance: %.2f\n", calculateBudgetBalance());
}
