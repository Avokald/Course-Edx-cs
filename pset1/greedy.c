#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float money;
    int stuff;
    int count = 0;
    do{
        printf("Value: \n");
        money = GetFloat();
    } while (money < 0);
   
        stuff = (int) (round(money*100));
        count += floor(stuff/25);
        stuff = stuff % 25;
        count += floor(stuff/10);
        stuff %= 10;
        count += floor(stuff/5);
        stuff %= 5;
        count += stuff;

    printf("%d\n", count);
    return 0;
}