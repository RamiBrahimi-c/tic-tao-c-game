#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#define MATRIX_LENGTH 3
//************************** mode pc keyboard *****************************
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
    srand(time(0));
    
    int mytime = 1 , pos;
    bool exist , isWinPlayer1 , isWinPlayer2 ;
    printf("*****************************\n");
    printf("*** PLAYER 1 PLAYS WITH X ***\n");
    printf("*** PLAYER 2 (computer) PLAYS WITH O ***\n"); 
    printf("*****************************\n");    
    isWinPlayer1 = false ;
    isWinPlayer2 = false ; 
    int scorePlayer1 = 0 , scorePlayer2 = 0;  
    while (mytime  < 10 )
    {   
        //Sleep(5000);
        exist = false ;
        printf("\n\n");        
        showMatrix(matrix);

        if (mytime % 2 != 0)
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
              exist = false;  
            printf("\nPLAYER 2 : ");
    //        scanf("%d", &pos);
            pos = rand() % 10 ;
            fillingMatrixByPlayer(matrix, 'O' ,pos , &exist);
            if (exist == true)
            {
                do
                {
                    printf("\n****** ENTER ANOTHER POSITION ! ***** : \n");
                    printf("\nPLAYER 2 : ");
      //              scanf("%d", &pos);
                     pos = rand() % 10 ;
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
        
        mytime ++ ;
        if (mytime == 10 && isWinPlayer1==false && isWinPlayer2==false)
        {
            printf("\n");
            printf("********** DRAW ***********\n");
            printf("\n");
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
    int i =-1, j ;
    returnPos(pos , &i , &j);
    if (matrix[i][j] == ' ' && i != -1 && j != -1)
    {
        *exist = false ;
        matrix[i][j] = player ;
    }else {
        *exist = true ;
    }
    


}
void returnPos(int pos , int *i , int *j) {
*i = -1 ; *j = -1 ;  
    if ( pos >=1 && pos <=3)
    *i = 2 ;

    if ( pos >=4 && pos <=6)
    *i = 1 ;
    
    if ( pos >=7 && pos <=9)
    *i = 0 ;
        

    if ( pos == 1 || pos == 4 || pos == 7)
    *j = 0 ;

    if ( pos == 2 || pos == 5  || pos ==8 )
    *j = 1 ;
    
    if ( pos == 3 || pos == 6 || pos == 9)
    *j = 2 ;        
}

bool whoisWinner(char matrix [MATRIX_LENGTH][MATRIX_LENGTH] , bool *isWinPlayer1 ,bool *isWinPlayer2 ) {
    int i =0, j ;
    bool endOfCheck = false ;
    while ( i < MATRIX_LENGTH && endOfCheck== false)
    {
        j = 0;   
        while ( j < MATRIX_LENGTH && endOfCheck == false)
        {
            if (i == 0 && j == 0 && matrix[i][j] != ' ' && endOfCheck == false) // position 1
            {
                char check = matrix[i][j] ;
                if (check == matrix[i][j+1] && check == matrix[i][j+2] && endOfCheck == false) // 1 & 2 & 3
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    break;
                    
                }
                if (check == matrix[i+1][j] && check == matrix[i+2][j] && endOfCheck == false) // 1 & 4 & 7
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    break;
                    
                }
                if (check == matrix[i+1][i+1] && check == matrix[i+2][i+2] && endOfCheck== false) // 1 & 3 & 9
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    break;
                }                
                

            }
            if (i == 0 && j == 1 && matrix[i][j] != ' ' && endOfCheck==false) // position 2
            {
                char check = matrix[i][j] ;
                if (check == matrix[i+1][j] && check == matrix[i+2][j] && endOfCheck==false) // 2 & 5 & 8
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    
                }
 
                

            }
            if (i == 0 && j == 2 && matrix[i][j] != ' ') // position 3
            {
                char check = matrix[i][j] ;
                if (check == matrix[i+1][j-1] && check == matrix[i+2][j-2] && endOfCheck==false) // 3 & 5 & 7
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    
                }
                if (check == matrix[i+1][j] && check == matrix[i+2][j] && endOfCheck==false) // 3 & 6 & 9 
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    
                }   
                

            }
            if (i == 1 && j == 0 && matrix[i][j] != ' ' && endOfCheck==false) // position 4
            {
                char check = matrix[i][j] ;
                if (check == matrix[i][j+1] && check == matrix[i][j+2] && endOfCheck==false) // 4 & 5 & 6
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    
                }
 
                

            }             
            if (i == 2 && j == 0 && matrix[i][j] != ' ' && endOfCheck==false) // position 7
            {
                char check = matrix[i][j] ;
                if (check == matrix[i][j+1] && check == matrix[i][j+2] && endOfCheck==false) // 7 & 8 & 9
                {
                    endOfCheck = true ;
                    if (check == 'X')
                    {
                        *isWinPlayer1 = true;
                    } else {
                        *isWinPlayer2 = true ;
                    }
                    
                }
  
            }                                                
             j++ ;
        }
     i = i + 1 ;
    }
    
}