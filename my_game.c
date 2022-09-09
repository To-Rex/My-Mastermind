#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int dig(char *inp);
void wellplacedpieces(char *inp, char *code);
void misplacedpieces(char *inp, char *code);

void mastermind(char *code, int attempts)
{
    
    printf("Will you find the secret code?\n---\n");
    
    char input[5];
    
    for (int i = 0; i < attempts; i++)
    {
        printf("Round %i\n>",i);
        scanf("%s", input);
        
        if (dig(input))
        {
            if (strcmp(input, code) == 0)
            {
                
                printf("Congratz! You did it!\n");
                break;
            }
           
            wellplacedpieces(input, code);
            misplacedpieces(input, code);
            printf("---\n");
            
            if (i == attempts - 1)
            {
                printf("Failure!!!\n");
                printf("The secret code was %s\n", code);
            }
        }
        else
        {
            
            printf("Wrong input!\n");
        }
    }
}


int dig(char *inp)
{   for (int i = 0, len = strlen(inp); i < len; ++i)
    {
        if (!isdigit(inp[i]))
        {
            return 0;
        }
    }
    return 1;
}


void wellplacedpieces(char *inp, char *code)
{
    int c = 0;
    for (int i = 0, len = strlen(code); i < len; i++)
    {
        if (inp[i] == code[i])
        {
            c++;
        }
    }
    printf("Well placed pieces: %i\n", c);
}


void misplacedpieces(char *inp, char *code)
{
    int c = 0;
    for (int i = 0, len = strlen(code); i < len; i++)
    {
        if (inp[i] == code[i])
        {
            c++;
        }
    }
    int w = 0;
    for (int i = 0, len = strlen(code); i < len; i++)
    {
        for (int j = 0, leng = strlen(inp); j < leng; j++)
        {
            if (code[i] == inp[j])
            {
                w++;
            }
        }
    }
    printf("Misplaced pieces: %i\n", w-c);
}