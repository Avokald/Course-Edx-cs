#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argv[1] < 0 || argc != 2){
        printf("Error");
        return 1;
    }
    int key = atoi(argv[1]);

    string s = GetString();
    for ( int i = 0, j = strlen(s); i < j; i++){
        
        if ( isupper(s[i]) && isalpha(s[i]) ){
            printf("%c", (char) ('A' + ( (s[i] + key + 13)%26) ) );
        }
        else if (isalpha(s[i]) && islower(s[i]) ){
            printf("%c", (char) ('a' + ((s[i] + key + 7)%26)) );
        }
        else {
            printf("%c", s[i]);
        }
        
    }
    printf("\n");
    return 0;
}