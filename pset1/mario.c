#include <stdio.h>
#include <cs50.h>

int main(void){
    int num_lvl;
    do {
        printf("Height: \n");
        num_lvl = GetInt() + 1;
    } while ((num_lvl <=0) || (num_lvl >24));
    
    for (int i = num_lvl-1; i > 0; --i){
    //    int a = num_lvl;
        for (int j = 1; j < i; j++){
            printf(" ");
        }
        for (int k = i; k < num_lvl+1; k++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}