/* You Li 2019-01-18
 * Lab1.c
 * A C program that takes the input of the
 * user, then prints the product, difference
 * and sum of roots of the inputed numbers with
 * two decimals.
 */
 

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    double Num1=0, Num2=0; 
	//Initialize two doubles to store the inputs of the user
	
	printf("Enter two positive numbers: ");
    //Demands the user for the input 
	
    scanf("%lf %lf", &Num1, &Num2);
	//Assigns the input to the declared variables
	
    printf("The product is: %.2lf, the difference is: %.2lf\
	and the sum of roots is: %.2lf", Num1*Num2, Num1-Num2,sqrt(Num1)+sqrt(Num2));
	//The final print statement to output the answers.
    
	return 0;
}