//Program that checks if an inputed word is a palindrome

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 10
#define min 3

char *invertString(char *string, int len) {

    int k = len - 1;
    char *newString = (char *) malloc(len * sizeof(char));

    for(int i = 0; i < len;i++)
    {
        newString[k] = string[i];
        k--;
    }

    return newString;
}

int main() {
    
    char string[max+1];
    int len = 0, stop = 0;

    printf("-- PROGRAMA QUE VERIFICA SE UMA PALAVRA E UM PALINDROMO --\n");

    while(stop == 0) {
        
        do{
            printf("Digite uma palavra com um numero de letras superior a %d e inferior a %d, ou ENTER para sair:\n", min, max);
            fgets(string, max+1, stdin);

            if (string[0] == '\n') { 
                stop = 1;
                break;      
            }else{
                string[strcspn(string, "\n")] = '\0'; // remove o caractere '\n' do final da string
            }

            len = strlen(string);
        }
        while(len > max+1 || len < min+1);

        char *invertedString = invertString(string, len);

        if(stop == 0)
        {
            if(strcmp(invertedString, string) == 0)
            {
                printf("A palavra %s é um palindromo\n\n", string);
            }
            else
            {
                printf("A palavra %s não é um palindromo\n\n", string); 
            }

            free(invertedString);
        }

    }
    
    return 0;
}
