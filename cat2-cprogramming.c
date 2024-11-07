#include <stdio.h>

double calculate_gross_pay(double hours_worked, double hourly_wage) {
    double regular_hours = 40;
    double overtime_hours = 0;
    double regular_pay, overtime_pay, gross_pay;

    
    if (hours_worked > regular_hours) {
        overtime_hours = hours_worked - regular_hours;
        regular_hours = 40;
    }

    regular_pay = regular_hours * hourly_wage;
    overtime_pay = overtime_hours * hourly_wage * 1.5; 

    
    gross_pay = regular_pay + overtime_pay;

    return gross_pay;
}

double calculate_taxes(double gross_pay) {
    double tax = 0.0;

    // Tax calculation
    if (gross_pay <= 600) {
        tax = gross_pay * 0.15; 
    } else {
        tax = 600 * 0.15 + (gross_pay - 600) * 0.20;  
    }

    return tax;
}

double calculate_net_pay(double gross_pay, double tax) {
    return gross_pay - tax;
}

int main() {
    double hours_worked, hourly_wage, gross_pay, tax, net_pay;

    
    printf("Enter the hours worked in a week: ");
    scanf("%lf", &hours_worked);
    printf("Enter the hourly wage: ");
    scanf("%lf", &hourly_wage);

    
    gross_pay = calculate_gross_pay(hours_worked, hourly_wage);

    
    tax = calculate_taxes(gross_pay);

    
    net_pay = calculate_net_pay(gross_pay, tax);

    
    printf("\nGross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", tax);
    printf("Net Pay: $%.2f\n", net_pay);

    return 0;
}
