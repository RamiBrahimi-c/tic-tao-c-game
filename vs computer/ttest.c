#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()  {
    srand(time(0));
    int val = rand() % 10 ;


    printf("rand value : %d \n", val);










    return 0 ;
}