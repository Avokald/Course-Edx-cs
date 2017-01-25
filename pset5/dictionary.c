/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    char ch;
    int k = 0;
    dict *temp = root;
    if (temp == NULL) return 5;
    for (int i = 0, j = strlen(word); i < j; i++){
        if ( isalpha(word[i]) ){
            ch = tolower(word[i]);
            k = (((int)ch)-19 )%26;
        }
        else if (word[i] == '\''){
            k = 26;
        }
        if (temp->children[k] != NULL){
            temp = (temp->children[k]);
        }
        else {
            return false;
        }
    }
    if (temp != NULL){
        if (temp->is_word == true){
                return true;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    couW = 0;
    char ch;
    root = malloc( sizeof(dict) );
    for (int i = 0; i < 27; i++){
        root->children[i] = NULL;
    }
    root->is_word = NULL;
    rootwork = root;
    FILE *dp = fopen(dictionary, "r");
    int index = 0;
    dict *temp = root;
    
    while (( ch = fgetc(dp) ) != EOF){
        if (isalpha(ch) || (ch == '\'') || (ch == '\0') || (ch == ' ') || (ch == '\n')){
            if ( ((ch == ' ') || (ch == '\n') || ( ch == '\0')) && (index > 0) ){
                temp->is_word = true;
                couW++;
                index = 0;
                temp = root;
            }
            else if ( (ch == '\'') || (isalpha(ch)) ){
                int k = 0;
                //k - position of character in array. a - 0, z - 25.  \'  - 26
                
                if(isalpha(ch)){
                    ch = tolower(ch);
                    k = (int) ( ch-19 )%26; 
                }
                else if( ch == '\''){
                    k = 26;
                }
                
                if (temp->children[k] == NULL){
                    temp->children[k] = malloc( sizeof(dict) );
                    temp->children[k]->is_word = NULL;
                    for (int z = 0; z < 27; z++){
                        temp->children[k]->children[z] = NULL;
                    }
                    if (temp->children[k] == NULL){
                        unload();
                        return false;
                    }
                }
                
                temp = (temp->children[k]);
                index++;
            }
        }
    }
    fclose(dp);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    
    return couW;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
 
bool unload(void)
{
    // TODO
    for (int i = 0; i < 27; i++){
        dict *temp2 = rootwork;
        if (rootwork->children[i] != NULL){
            rootwork = (rootwork->children[i]);
            if(unload()){
                rootwork = temp2;
                rootwork->children[i] = NULL;
            }
        }
        
        else if ( rootwork->children[i] == NULL){
            continue;
        }
        if (rootwork == NULL){
            return true;
        }
        
    
    }
    if (rootwork != NULL){
        if (rootwork->children[26] == NULL){
            free(rootwork);
            return true;
    
        }
    }
    return false;
}
