/* You Li 2019-01-26
 * Lab2.c
 * A C program that takes the input of the
 * user as price of item, interest rate per year 
 * and months for payment, then calculates 
 * the monthly payment and the total cost of the item.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	//Initializes the variables and constants that will be used in the program
    const int months = 12;
	const int percent = 100;
    double inputCost = 0;
	double inputInterest = 0;
	double inputMonths = 0;
	double monthlyPayment = 0;
	double totalCost = 0;
    
	//Demands the user for the various inputs
	printf("Enter the purchase price of the item: ");
    scanf("%lf", &inputCost);
    
	printf("Enter the interest rate per year as a percentage: ");
    scanf("%lf", &inputInterest);
	
	//As the interest rate is taken as a percentage and per year,
	//it needs to be converted to a decimal montly value.
    inputInterest /= months * percent;
    
    printf("Enter the number of months for repayment: ");
    scanf("%lf", &inputMonths);
    
	//Calculating the monthly payment using the given formula.
    monthlyPayment = inputInterest / (1 - pow(1 + inputInterest, -inputMonths)) * inputCost;
	
	//Calculating the  total cost of the item
    totalCost =  monthlyPayment * inputMonths;
    
	//Printing out the results.
    printf("The monthly payment is: %.2lf\n",monthlyPayment);
    printf("The total cost of the purchase is: %.2lf\n", totalCost);
	
    return 0;
}