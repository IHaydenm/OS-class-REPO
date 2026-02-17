#include <stdio.h>
#include <stdlib.h>
/*functions*/
int calc_Factorial( int fact_num );
/*FUNCITONS*/
int main(){
    /*variables*/
    int fact_num;
    /*VARIABLES*/
    printf("Hello\nThis program will calculate the factorial of a number you give.\nPlease, give me the number you want to get the factorial of:  ");
    scanf("%d", &fact_num);
    printf("The factorial result is: %d" , calc_Factorial(fact_num));
    return 0;
}

int calc_Factorial( int fact_num ){    
    /*variables*/
    int fact_result = 1;
    /*VARIABLES*/
    for (int i=0; i<fact_num; i++){
        fact_result = (i+1) * fact_result;
        /*debug:
            printf("fact_result: %d \n", fact_result);
        */
    }
    return fact_result;
}