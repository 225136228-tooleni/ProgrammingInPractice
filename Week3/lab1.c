#include <stdio.h>

int main() {
    //Delaring Variable
    double salary=0.00;
    double housingAllowance=0.00;
    double transportAllowance=0.00;
    double tax=0.00;
    double grossSalary=0.00;
    double netSalary=0.00;

    //1. Ask user for salary
    printf("Enter salary: ");
    scanf("%lf", &salary);

    //2. Ask user for housing allowance
    printf("Enter Housing Allowance: ");
    scanf("%lf", &housingAllowance);

    //3. Ask user for Transport allowance
    printf("Enter Transport allowance: ");  
    scanf("%lf", &transportAllowance);

    //4. Ask user for tax
    printf("Enter tax: ");
    scanf("%lf", &tax);

    //5. Calculate and output Gross Salary
    grossSalary = salary + housingAllowance + transportAllowance;
    printf("\nGross Salary: %.2f\n", grossSalary);

    //6. Calculate and display net salary
    netSalary = grossSalary - tax;
    printf("Net Salary: %.2f\n", netSalary);
return 0;
}
