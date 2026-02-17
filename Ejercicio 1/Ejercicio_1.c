#include <stdio.h>
/*variables*/
int lenght;
int width;
int result;
/*VARIABLES*/
int main(){
    printf("Hello, this program will calculate the area of a given rectangle, even squares!\n\nPlease, give me the length of the rectangle:  ");
    scanf("%d", &lenght);
    printf("Perfect!\n\nNow give me the width of the rectangle:  ");
    scanf("%d", &width);
    if(lenght==width){
        result= lenght*lenght;
        printf("The resulting area is %d", result); 
        //printf("square");
    }
    else if(lenght!=width){
        result = width*lenght;
        printf("The resulting area is %d", result);
        //printf("rectangle");
    }
    else{
        printf("Error!");
        return -1;
    }
    return 0;
}