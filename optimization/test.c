#include <stdio.h>
#include <stdbool.h>
#define MATRIX_LENGTH 3
//***************************  my X/O GAME *****************************************
//*************************** by main.c    *****************************************   
void showMatrix(char (matrix) [MATRIX_LENGTH][MATRIX_LENGTH]);
void fillingMatrix(char (matrix) [MATRIX_LENGTH][MATRIX_LENGTH]);
void fillingMatrixByPlayer(char (matrix) [MATRIX_LENGTH][MATRIX_LENGTH] , char player , int pos , bool *exist);
void returnPos(int pos , int *i , int *j);
bool whoisWinner(char matrix [MATRIX_LENGTH][MATRIX_LENGTH] , bool *isWinPlayer1 ,bool *isWinPlayer2 );
int main() {
    char matrix[MATRIX_LENGTH][MATRIX_LENGTH] ;
    fillingMatrix(matrix);
    int time = 1 , pos;
    bool exist , isWinPlayer1 , isWinPlayer2 ;
    printf("*****************************\n");
    printf("*** PLAYER 1 PLAYS WITH X ***\n");
    printf("*** PLAYER 2 PLAYS WITH O ***\n"); 
    printf("*****************************\n");    
    isWinPlayer1 = false ;
    isWinPlayer2 = false ; 
    int scorePlayer1 = 0 , scorePlayer2 = 0;  
    while (time  < 10 )
    {   
        exist = false ;
        printf("\n\n");        
        showMatrix(matrix);

        if (time % 2 != 0)
        {
            printf("\nPLAYER 1 : ");
            scanf("%d", &pos);
            fillingMatrixByPlayer(matrix, 'X' ,pos , &exist);
            if (exist == true)
            {
                do
                {
                    printf("\n***** ENTER ANOTHER POSITION ! ***** : \n");
                    printf("\nPLAYER 1 : ");
                    scanf("%d", &pos);
                    fillingMatrixByPlayer(matrix, 'X' ,pos , &exist); 
                } while (exist == true);
            
            }
            
        }
        else
        {
            printf("\nPLAYER 2 : ");
            scanf("%d", &pos);
            fillingMatrixByPlayer(matrix, 'O' ,pos , &exist);
            if (exist == true)
            {
                do
                {
                    printf("\n****** ENTER ANOTHER POSITION ! ***** : \n");
                    printf("\nPLAYER 2 : ");
                    scanf("%d", &pos);
                    fillingMatrixByPlayer(matrix, 'O' ,pos , &exist); 
                } while (exist == true);
            
            }            
        }

        whoisWinner(matrix ,&isWinPlayer1 , &isWinPlayer2);
        if (isWinPlayer1==true || isWinPlayer2==true)
        {
            showMatrix(matrix);
            printf("\n\n");
            if (isWinPlayer1 == true)
            {
                printf("*******************************\n");
                printf("****** PLAYER 1 WINS !!! ******\n");
                printf("*******************************\n");                
                scorePlayer1++;
                break;
            }
            if (isWinPlayer2 == true)
            {
                printf("*******************************\n");                
                printf("****** PLAYER 2 WINS !!! ******\n");
                printf("*******************************\n");                
                scorePlayer2++;
                break;
            }
        }
        
        time ++ ;
        if (time == 10 && isWinPlayer1==false && isWinPlayer2==false)
        {
            printf("********** DRAW ***********\n");
        }
        

    }
    

    printf("\n\n\n");
    printf("************************\n");
    printf("******* RESULTS ********\n");
    printf("************************\n");    
    printf("***** PLAYER 1 : %d *****\n", scorePlayer1);
    printf("***** PLAYER 2 : %d *****\n" , scorePlayer2);
    printf("************************\n");        
    printf("\n\n\n ******END*********\n");








    return 0 ;
}
// ***************************** END MAIN **************************************
void fillingMatrix(char (matrix) [MATRIX_LENGTH][MATRIX_LENGTH]) {
    for (int i = 0; i < MATRIX_LENGTH; i++)
    {
        for (int j = 0; j < MATRIX_LENGTH; j++)
        {
            matrix[i][j] = ' ';
        }
        
    }
    
}

void showMatrix(char (matrix) [MATRIX_LENGTH][MATRIX_LENGTH]) {
   for (int i = 0; i < MATRIX_LENGTH; i++)
    {
        for (int j = 0; j < MATRIX_LENGTH; j++)
        {
            if (j < 2)
            {
            printf(" %c |" , matrix[i][j]);
            }else {
                printf(" %c \n" , matrix[i][j]);
            }
            
        }
        if (i < 2)
        {
            printf("------------\n");
        }
        
        
    }
}
void fillingMatrixByPlayer(char (matrix) [MATRIX_LENGTH][MATRIX_LENGTH] , char player , int pos ,bool *exist) {
    int i , j ;
    returnPos(pos , &i , &j);
    if (matrix[i][j] == ' ')
    {
        *exist = false ;
        matrix[i][j] = player ;
    }else {
        *exist = true ;
    }
    


}
void returnPos(int pos , int *i , int *j) {
    if ( pos >=1 && pos <=3)
    *i = 0 ;

    if ( pos >=4 && pos <=6)
    *i = 1 ;
    
    if ( pos >=7 && pos <=9)
    *i = 2 ;
        

    if ( pos == 1 || pos == 4 || pos == 7)
    *j = 0 ;

    if ( pos == 2 || pos == 5  || pos ==8 )
    *j = 1 ;
    
    if ( pos == 3 || pos == 6 || pos == 9)
    *j = 2 ;        
}



bool whoisWinner(char matrix [MATRIX_LENGTH][MATRIX_LENGTH] , bool *isWinPlayer1 ,bool *isWinPlayer2 ) {

    if (matrix[0][0] == matrix[0][1] == matrix[0][2] || matrix[0][0] == matrix[1][0] == matrix[2][0] || matrix[0][0] == matrix[1][1] == matrix[2][2] || matrix[0][2] == matrix[1][1] == matrix[2][0] || matrix[0][2] == matrix[1][2] == matrix[2][2] ||matrix[2][0] == matrix[2][1] == matrix[2][2])  {
        if (matrix[0][0] == 'X')
        {
            *isWinPlayer1 = true;

        }
        if (matrix[0][0] == 'O')
        {
            *isWinPlayer1 = true;
        }
        
        
    }    
}