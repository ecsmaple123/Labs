/* You Li 2019-02-01
 * Lab4.c
 * A C Program that calcualtes the mid Riemann Sums of 
 * the function 2(x^2)-7x-2 with the user entered
 * bounds and step size.
 */


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define eps 1e-3 //Defining a constant to be used in one of the functions


//Declaring the function prototypes.
bool compareDoubles (double A, double B);
bool validateInput(double left, double right, int n);
double evalFunc(double x);
double calculateSum(double inputBegin, double inputStep, double inputEnd);


int main() {
	int numberRect = 0; 
	double lowerBound = 0, upperBound = 0;
	double stepSize = 0;
	double leftSum = 0, rightSum = 0, midSum = 0;
	double tempNumberRect = 0; //Temporary value used to check if the number of rectangles is an integer.
	
	
	//A do while is used here to make sure that the original statement is printed at least once,
	//if the inputs are validated, the program will move on, otherwise it will keep demanding the
	//user for valid input.
	do {
		
        printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
        printf("To exit enter 0 0 0\n");
        scanf("%lf %lf %lf", &lowerBound, &upperBound, &tempNumberRect);
		
		//Checking if number of rectangle is integer.
		numberRect = (int) tempNumberRect;
		
		//If the int value is not equal to the double value, it means that the input has decimals.
		if(tempNumberRect != numberRect) {
			//Make the validInput function return false to restart the loop.
			numberRect = -1;	
		}
		
	} while(!validateInput(lowerBound, upperBound, numberRect));
	
	stepSize = (upperBound - lowerBound) / numberRect; //Calculating step size.
	
	//Left sum is calcualted from left most x value to upper bound minus one stepsize.
	//However, upperBound is used here due to the fact that increments are by stepSize,
	//the function will not include the y value at upperBound as it equal to the upper 
	//bound, therefore the use of upperBound - stepSize is not needed.
    leftSum = calculateSum(lowerBound, stepSize, upperBound);
	
	//Similarly, right sum starts at one step size above lower bound, and must be written
	//as  upperBound + stepSize to include the end value of Y.
    rightSum = calculateSum(lowerBound + stepSize, stepSize, upperBound + stepSize);
	
	//Similar to right sum, except with stepSize being halved.
    midSum = calculateSum(lowerBound + stepSize / 2, stepSize, upperBound + stepSize / 2);
	
	//Printing out results.
	printf("With Step Size: %.4lf\n", stepSize);
	printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
	printf("Bound between %.2lf and %.2lf, using %d rectangles is as follows\n\n", lowerBound, upperBound, numberRect);
	printf("Mid point evaluation approximate: %.4lf\n", midSum);
	printf("Left point evaluation approximate: %.4lf\n", leftSum);
	printf("Right point evaluation approximate: %.4lf\n", rightSum);
	
	
	return 0;
}

/* This function returns true if the values entered 
 * by the user are suitable for further calculations
 * and false otherwise.
 */
 
bool validateInput(double left, double right, int n){
	

	//if statement catching if user entered 0 0 0, which terminates the program.
	if(compareDoubles(left, 0) && compareDoubles(right, 0) && n == 0) {
		printf("Invalid inputs...\n\n");
		printf("Terminating main!\n");
		exit(0);
	}
	
	//Catching invalid inputs.
	if(left < -10.0 ||  right > 10.0 || right <= left || n <= 0) {
		printf("Invalid inputs...\n");
		return false;
	} else {
		return true;
	}
	
}

/* This function evaluates the Y value 
 * of the function 2(x^2)-7x-2 at a 
 * given x value.
 */
double evalFunc(double x) {
	return 2 * pow(x,2) - 7*x - 2;
}

/* This function returns true if the 
 * two doubles entered are equal and 
 * fasle otherwise. This is necessary 
 * because comparing equality of doubles
 * in C can result in unexpected returns.
 */
bool compareDoubles (double A, double B) {
	
	//if the difference between the two values
	//is small enough, they are deemed equal.
	//eps is choosed based on the scale of the
	//inputs
	return fabs(A - B) < eps;
	
}

/* This function calcualtes the Riemann Sum from the given inputs.
 * Mid, left and right can all be calculated through this function\
 * by manipulating the inputs.
 */
double calculateSum(double inputBegin, double inputStep, double inputEnd){
    
    double outputResult = 0;//The result that will be returned.
	
	//for loop that runs through all the x values, seperated by the step size
	//input by the user/
	
    for(; !compareDoubles(inputBegin, inputEnd); inputBegin += inputStep) {
		
		//Taking the Y value of the function at current x using evalFunc
		//and storing the total sum into the output.
        outputResult += evalFunc(inputBegin);
    }
	
	//Return the final result of the Riemann sum
    return outputResult * inputStep;
}