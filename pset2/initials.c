#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void){
    string c = GetString();
    for (int i = 0, g = strlen(c); i < g; i++){
        if (!isalpha(c[i-1]) && isalpha(c[i])){
            printf("%c", toupper(c[i]));
        }
       /* else if(isalpha(c[i]) && !isalpha(c[i-1])){
            printf("%c ", toupper(c[i]));
            
        }*/
    }
    printf("\n");
    return 0;    
}


