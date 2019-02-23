/* You Li 2019-02-15
 * Lab5Part1.c
 * A C Program that encrypts a input number 
 * by adding 4 to every digit and shifting 
 * every digit one to the right.
 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>



/* This function takes in the input
 * from a user and stores it in the 
 * address *num
 */
void input(int *num){
	
	bool validInput = false; //Loop control 
	double tempNum = 0;
	
	while(!validInput) {
		
		printf("Please enter an integer greater than 99999: ");
		scanf("%lf", &tempNum);
		
		*num = (int) tempNum;
		
		if (*num <= 99999 || *num != tempNum){
			
			printf("Incorrect input.\n");
			
		} else {
			printf("The number entered is %d\n", *num);
			validInput = true;
		}
	
	}
	
}
//This function adds 4 to every digit of the number
int add4(int num) {
	
	//The array is initialized as 11 in consideration of maximum
	// integer digits and ending marker created by sprintf
    char numArray[11]; 
    int i = 0; //Loop control
	int currentDigit = 0, lengthArray = 0, returnInt = 0;
	
    sprintf(numArray, "%d", num); //sprintf prints the integer value into a char array.
	
    lengthArray = strlen(numArray); //strlen returns the length of the string
	
	//Looping through every digit 
    for (i = 0; i<lengthArray; ++i) {
		
		// - '0' covert the char to a int, also could be done with atoi
        currentDigit = numArray[i] - '0';
        currentDigit += 4;
		
        if (currentDigit >= 10) currentDigit -= 10;
		
		//converting back to char and storing the value
        numArray[i] = currentDigit + '0';
    }
	
	//strtoimax coverts the char array to a int used to return.
    returnInt = strtoimax (numArray, NULL, 10);
    return returnInt;
	
}

//This function shifts one digit to the left
int shift(int num) {
	
    char numString[11], outString[11];
    int i = 0;
	int lengthArray = 0, returnInt = 0;
    

    memset(outString, 0x00,11); //Initializing the output array
    sprintf(numString, "%d", num);
	
    lengthArray = strlen(numString);

	//i < lengthArray ignores the last value, which should be 
	//the first digit of the return value
    for (i = 0; i < lengthArray-1; i++) {
        outString[i] = numString[i + 1];
    }
	
	//Last digit is handled here
    outString[i] = numString[0];

    returnInt =  strtoimax (outString, NULL, 10);
    return returnInt;
}

//This function prints out the given adn the results.
void printOutput(int encryptNum, int originalNum){
	printf("Original number: %d\n", originalNum);
	printf("Encrypted number: %d\n", encryptNum);
}

