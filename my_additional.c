#include "my_mastermind.h"
int len(char* arr){
    int c = 0;
    while(*(arr + c) != '\0'){
        c++;
    }
    return c;
}

int indexOf(char* arr, char c){
    for(int i = 0; i < len(arr); i++){
        if(arr[i] == c){
            return 1;
        }
    }
    return 0;
}
int correct(char* arr){
    int x = 1;
    if(len(arr) > 4 || len(arr) < 4)
        return 0;
    for(int i = 0; i < len(arr); i++){
        if(arr[i] < '0' || arr[i] > '7'){
            x = 0;
        }
        for(int j = 0; j < i; j++){
            if(arr[i] == arr[j]){
                x = 0;
            }
        }
    }
    if(x)
        return 1;
    else
        return 0;
}

int mystrcmp(char *a, char* b){
    for(int i = 0; i < len(a); i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

void secretcode(char* code){
    srand(time(NULL));
    int i = 0;
    while(i < 4){
        char r = rand() % 8 + '0';
        if(indexOf(code, r) == 0){
            code[i] = r;
            i++;
        }
    }
}

char* mystrcpy(char* destination, char* source)
{
    for(int i = 0; i < len(source); i++){
        destination[i] = source[i];
    }
    return destination;
}