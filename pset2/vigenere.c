#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main( int argc, string argv[] ){
    if ( (argc != 2) ){
        
        printf("Error, need second parametre (word)\n");
        return 1;
    }
    for (int i = 0, j = strlen(argv[1]); i < j; i++){
            if ( !isalpha(argv[1][i]) ){
                printf("Error, need second parametre notr ofot\n");
                return 1;
            }
        }
    string sen = GetString();
    
    for (int i = 0, j = strlen(sen), m = strlen(argv[1]), k = 0; i < j; i++){
        if (isupper(sen[i])){
            if ( isupper( argv[1][k%m] ) ){
                printf("%c", (char) ( 'A' +( ( sen[i] + 13 + ( ( argv[1][k%m] +13)%26 ) )%26) ) );
                k++;
            }
            else if ( islower( argv[1][k%m] ) ){
                printf("%c", (char) ( 'A' +( ( sen[i] + 13 + ( ( argv[1][k%m] + 7)%26 ) )%26) ) );
                k++;
            }
            else if ( !isalpha ){
                continue;
            }
        }
        else if ( islower(sen[i])){
            if ( isupper( argv[1][k%m] ) ){
                printf("%c", (char) ( 'a' +( ( sen[i] + 7 + ( ( argv[1][k%m] +13)%26 ) )%26) ) );
                k++;
            }
            else if ( islower( argv[1][k%m] ) ){
                printf("%c", (char) ( 'a' +( ( sen[i] + 7 + ( ( argv[1][k%m] + 7)%26 ) )%26) ) );
                k++;
            }
            else if ( !isalpha ){
                continue;
            }
        }
        else {
            printf("%c", sen[i]);
        }

    }
    printf("\n");
    return 0;
}