#include <stdio.h>
#include <stdbool.h>
#define MATRIX_LENGTH 3


int main()  {

    printf("********* PLAYER 1 WILL START WITH (X) **********\n");
    int pos , gameNum=0; 
    bool gameOver ;
    char player1 = 'X', player2 = 'O' ;
    while (true)
    {
        gameNum++;
        printf("***** Round %d *****\n",gameNum);
        gameOver = false ;
        while (gameOver == false)
        {
            do
            {
                printf("enter the position : ");
                scanf("%d" , &pos);
            } while (pos > 9 || pos < 1);
            
        }
        
        

        
    }
    

    return 0 ;
}
