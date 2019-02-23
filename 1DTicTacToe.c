#include <stdio.h>
#include <stdbool.h>
/**
 * Call this function to display the game board on the terminal.
 *
 * @param board An array that represents the current state of the game.
 * @param playerA A number that represents Player A.
 * @param playerB A number that represents Player B.
 */
void printBoard(int board[], int playerA, int playerB) {    
    int i = 0;
    printf("\n");
    /*
    if (playerA == 0 && playerB == 0){
        playerA++;
        playerB++;
    }
    
    if (playerA == 0) {
        board[playerB -1] = 66;
        
    } else if (playerB == 0) {
        board[playerA -1] = 65;
    }
    */
    for (;i < 9; i++){
        
        if(board[i] > 9) {
            printf(" %c",board[i]);
        } else {
            printf(" %d", board[i]);
        }
        
        if (i == 2 || i == 5 || i == 8) {
            printf("\n");
        }
    }
    printf("\n");
    
}

/**
 * Call this function to accept valid input from the user via the keyboard.
 *
 * Valid input from the user is a number between 1 and 9, which represents
 * a location on the game board. In addition, that location must not have
 * already been claimed by Player A or Player B.
 *
 * This function will only return once valid input has been entered by the
 * user.
 *
 * @param board An array that represents the current state of the game.
 * @param playerA A number that represents Player A.
 * @param playerB A number that represents Player B.
 *
 * @return An index to the array that is valid.
 */
int requestValidInput(int board[], int playerA, int playerB) {
    // TODO: Implement this function.
    int tempInput = 0;
    bool valid = false;
    
    while(!valid){
        
        scanf("%d",&tempInput);
        valid = true;
    
        if(tempInput < 1 || tempInput > 9) {
            printf("Invalid input, please try again.\n");
            valid = false;
        } else if(board[tempInput-1] > 9){
            printf("That position has already been played, please try again.\n");
            valid = false;
        }
        
    }
    
    tempInput--;

    return tempInput; // TODO: Fix me.
}

/**
 * Call this function to check who, if anyone, has won the game.
 *
 * @param board An array that represents the current state of the game.
 * @param playerA A number that represents Player A.
 * @param playerB A number that represents Player B.
 *
 * @return 0 if neither Player A nor Player B has won the game. Otherwise,
 *         the function will return the player who has won.
 */
int checkForWinner(int state[], int playerA, int playerB) {
    // TODO: Implement this function.
    if (state[0] == state[1] && state[0] == state[2]) {
        if(state[0] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[3] == state[4] && state[3] == state[5]) {
        if(state[3] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[6] == state[7] && state[6] == state[8]) {
        if(state[6] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[0] == state[3] && state[0] == state[6]) {
        if(state[0] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[1] == state[4] && state[1] == state[7]) {
        if(state[1] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[2] == state[5] && state[2] == state[8]) {
        if(state[2] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[0] == state[4] && state[0] == state[8]) {
        if(state[0] == playerA){
            return playerA;
        } else return playerB;
    }
    
    if (state[2] == state[4] && state[2] == state[6]) {
        if(state[2] == playerA){
            return playerA;
        } else return playerB;
    }
    

    return 0; // TODO: Fix me.
}

bool checkTie(int board[]) {
    int i = 0;
    for(;i < 9; i++){
        if(board[i] <= 9) {
            return false;
        }
    }
    
    return true;
     
}


int main(void) {
    // TODO: See Algorithm 1 in the lab handout to get you started here.
    int board[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int playerA = 65, playerB = 66;
    int currentPlayer = playerA;
    int input = 0, win = 0;
    bool gameOver = false;
    
    while(!gameOver) {
    
        printf("The current state of the Tic-tac-toe Board:\n");
        printBoard(board,0,0);
    
        printf("It is Player %c's turn.\n", currentPlayer);
        printf("Please enter a valid position to play.\n");
    
        input = requestValidInput(board, playerA, playerB);
        
        if (currentPlayer == playerA) {
            board[input] = 65;
            currentPlayer = playerB;
        } else if (currentPlayer == playerB) {
            board[input] = 66;
            currentPlayer = playerA;
        }
        
        win = checkForWinner(board, playerA, playerB);
        
        if (win == playerA) {
            printf("Player A wins!\n");
            gameOver = true;
        } else if (win == playerB) {
             printf("Player B wins!\n");
            gameOver = true;
        } else if(checkTie(board)) {
            printf("It's a draw!\n");
            gameOver = true;
        }
    
    
    }
    
    printBoard(board, playerA, playerB);
    return 0;
}