/* You Li 2019-02-15
 * Lab5Part3.c
 * A C Program that uses Zeller's algorithm
 * to calculate the day of the week of a given
 * date.
 */

#include <stdio.h>


 
//This function stores the input of the user.
void inputDate(int *day, int *month, int *year) {
    
    printf("Please enter a date: ");
	
	//& not needed here for scanf
    scanf("%d/%d/%d", day, month, year);
    return;
}

//This function does Zeller's algorithm calculations.
void calculateDay(int day, int month, int year) {
	
    // Year is needed at the end so creating a temp value that can be altered for calculations.
    int tempYear = year;
    int aMonth,bDay,cYear,dCentury;
	int w,x,y,z,r; //Zeller's algorithm parts.
    
    bDay = day;
    
	//Handling the month value
    switch(month) {
      case 1 :
         aMonth = 11;
         tempYear--;
         break;
      case 2 :
         aMonth = 12;
         tempYear--;
         break;
      default :
        aMonth = month - 2;
   }
  
	//Below are Zeller's algorithm 
    cYear = tempYear % 100;
    dCentury = tempYear / 100;
    
    w = (13 * aMonth - 1) / 5;
    x = cYear / 4;
    y = dCentury / 4;
    z = w + x + y + bDay + cYear - 2 * dCentury;
    r = z % 7;
    
    if(r < 0) {
        r += 7;
    }
    
	//Printing final results
    printf("The day %d/%d/%d is a ",day,month,year);
    
    switch(r) {
        case 1: 
            printf("Monday.\n");
            break;
        case 2: 
            printf("Tuesday.\n");
            break;
        case 3: 
            printf("Wednesday.\n");
            break;
        case 4: 
            printf("Thursday.\n");
            break;
        case 5: 
            printf("Friday.\n");
            break;
        case 6: 
            printf("Saturday.\n");
            break;
        case 0: 
            printf("Sunday.\n");
            break;
   }
    
    
}