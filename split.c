/*******************************************************************************
*
* Program: Split Function in C
* 
* Description: A split function that splits a string into an array of substrings
* based on separator character using C. This function is similar to the 
* split function in Python. 
* Can handle empty strings, multiple separators. 
* 
*
* Author: Lotfi Rafik Bouchafa
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split(char *string, char seperators, int* nb_tokens);

int main(){

    // test the function
    char s[] = "Adele (75798);75798;Adele;12973223;20\n";
    int count_strings = 0;
    char **split_strings = split(s, ';', &count_strings);

    printf("Nb token found %d\n", count_strings);

    // print out the substrings, which should be each word of the sentence above
    for (int i = 0; i < count_strings; i++)
        printf("%s\n", split_strings[i]);

    // free the dynamically allocated space for each string
    for (int i = 0; i < count_strings; i++)
        free(split_strings[i]);

    // free the dynamically allocated space for the array of pointers to strings
    free(split_strings);
}

// Separates the string into substrings, splitting the string into substrings 
// based on the separator character.  The function returns an
// array of pointers to strings, dynamically allocated on the heap, and it 
// effectively "returns" the number of these strings via pass-by-pointer using 
// the parameter count.  
// Time complexity : O(2n) with n being length of string to split
char **split(char *string, char seperator, int* nb_tokens){
    // get the length of the string
    int len = strlen(string);
    int i,j = 0;

    *nb_tokens = 0;

    // First loop to find out how many tokens there is
    while (i < len){
        while(i < len && string[i] != seperator){
            i++;
            j++;
        }
        // ****** Token found *****
        *nb_tokens = *nb_tokens + 1;

        // skip current separator
        i++;
    }

    
    // Maximum token's length is the len of the string (i.e string contains no separators)
    char token[len];
    
    // allocate space for a dynamically allocated array of *nb_tokens* number of 
    // pointers to strings
    char **tokens = malloc(sizeof(char*) * *nb_tokens);
    
    // Reinitialize count variables
    *nb_tokens = 0;
    i = 0;
    j = 0;

    // Second loop to extract tokens
    while (i <= len){
        // Initialize token
        token[0] = '\0';
        
        j = 0;
        while(i < len && string[i] != seperator){
            token[j] = string[i];
            i++;
            j++;
        }
        // ****** Token found *****

        // add a null terminator on to the end of token to terminate the string
        token[j] = '\0';

        tokens[*nb_tokens] = strdup(token);

        *nb_tokens = *nb_tokens + 1;

        // skip current separator
        i++;
    }
    
    // return our array of strings  
    return tokens;
}
