/* You Li 2019-02-01
 * Lab3.c
 * A C program that takes the input of the
 * user as price of coffee, amount of money available 
 * to buy coffee and the number of coupons to redeem
 * free coffee. It then runs a few calculations to
 * determine the total amount of coffee bought, free
 * coffee redeemed, leftover coupons and average money 
 * spent on coffee.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	double priceCoffee = 0;
	double amountMoney = 0;
	double averagePrice = 0;
	int numberCoupon = 0;
	int boughtCoffee = 0;
	int freeCoffee = 0;
	int totalCoffee = 0; 
	int currentCoupon = 0;
	int tempCoffee = 0; //A temporary variable that is only used in calculations
	
	
	//The following lines demand input from the user
	//to proceed with calculations, the inputs are
	//checked to make sure of their validity.
	printf("How much does a coffee cost?\n");
	scanf("%lf", &priceCoffee);
	
	
	if(priceCoffee < 0.01){
		printf("Invalid Input.\n");
		return 0;
	}
	
	printf("How many coupons does it take to get a free coffee?\n");
	scanf("%d", &numberCoupon);
	
	if(numberCoupon <= 1){
		printf("Invalid Input.\n");
		return 0;
	}
	
	printf("How much money do you have to spend on coffee this month?\n");
	scanf("%lf", &amountMoney);
	
	if(amountMoney <= 0){
		printf("Invalid Input.\n");
		return 0;
	}
	
	
	//The amount of coffee bought with money is calculated
	boughtCoffee = amountMoney / priceCoffee;
	
	//Amount of starting coupons
    currentCoupon = boughtCoffee;
    
    while(currentCoupon >= numberCoupon){
		/* By using tempCoffee to save the initial redeemed coffee,
		* the program is able to save the new amount of coupons
		* after the current redemption, restarting the loop if 
		* necessary. freeCoffee tracks the total amount of coffee
		* redeemed.
		*/
        tempCoffee = currentCoupon / numberCoupon;
        freeCoffee += tempCoffee;
		//Here, the % shows the leftover coupons from initial redemption,
		//currentCoupon is then updated with the leftover plus the coupons
		// received from redeemed coffee.
        currentCoupon = currentCoupon % numberCoupon + tempCoffee;
    }
	
	//Final calculations for other results.
    totalCoffee = boughtCoffee + freeCoffee;
	averagePrice = (priceCoffee * boughtCoffee) / totalCoffee;
	amountMoney -= priceCoffee * boughtCoffee;
	
	
	//Printing out the results.
	printf("This month, you can purchase %d coffees at $%.2lf each.\n", boughtCoffee, priceCoffee);
	
	if(freeCoffee == 0){
		printf("You will not be able to redeem any additional coffees from coupons this month.\n");
	} else 
		printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", freeCoffee);
	
	
	printf("At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n", amountMoney, currentCoupon);
	printf("On average, you spent $%.2lf on each cup of coffee this month.\n", averagePrice);
	
		return 0;
}