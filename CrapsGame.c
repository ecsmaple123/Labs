/* You Li 2019-02-15
 * Lab5Part2.c
 * A C Program that plays games of Craps
 * until the user desires to stop, also keeps 
 * track of wins and losses.
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


//This function returns the sum of the two dice
// when rolling.
int rollDice(void){
    
    int die1 = 0, die2 = 0;
    
	//From 0 to 5, adding 1 making it from 1 to 6
    die1 = ( (rand() % 6) + 1);
    die2 = ( (rand() % 6) + 1);
    
    return die1 + die2;
}

//This function plays one game
bool playGame(void) {
    
    int rollOne = 0, rollAfter = 0;
    
    
	//First roll
    rollOne = rollDice();
    printf("You rolled: %d\n", rollOne);
    
	//Checking first roll win and lose conditions
    if(rollOne == 7 || rollOne == 11) {
        printf("You win!\n");
        return true;
    }
    
    if(rollOne == 2 || rollOne == 3 || rollOne == 12) {
        printf("You lose!\n");
        return false;
    }
    
    printf("Your point is: %d\n", rollOne);
    
	//Following rolls
    while(rollAfter != rollOne &&  rollAfter != 7 ){
        
        rollAfter = rollDice();
        printf("You rolled: %d\n", rollAfter);
	}
    
	//Checking result
	if (rollAfter == 7){
            
		printf("You lose!\n");
		return false;
            
	} else if (rollAfter == rollOne) {
            
		printf("You win!\n");
		return true;
	}
	
	return 0;
}

//This function calls the playGame function and 
//keeps track of win records.
void winLoss(void){
    
    int win = 0, loss = 0;
    char response = ' '; //Loop control 
	
	
	//toupper converts the char into an uppercase
    while(toupper(response) != 'N') {
		
		//playGame used as condition control as it returns a boolean
		if(playGame()) {
			win++;
		} else {
			loss++;
		}
		
		
	    printf("Play again? ");
		response = getchar(); //getchar gets a singular char input 
		
		//Flushing the buffer of getchar if the user wishes to continue playing.
		if(toupper(response) != 'N'){
			while((response = getchar()) != '\n' && response != EOF);
		}
	}
	
	//Final records
	printf("\nWins: %d\n",win);
	printf("Losses: %d\n",loss);
	
} 
