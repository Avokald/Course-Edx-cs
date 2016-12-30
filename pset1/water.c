#include <stdio.h>
#include <cs50.h>

int main(void){
    int time_shower;
    printf("Give me time: \n");
    time_shower = GetInt(); 
    int num_bottles;
    num_bottles = time_shower * 192.0 / 16.0;
    printf("Number of bottles: %d\n", num_bottles);
    return 0;
}