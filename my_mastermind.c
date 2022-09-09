#include "my_additional.c"
int main(int argc, char* argv[]){
    int wp = 0;
    int mp = 0;
    int attempts = 10;
    int c = 0;
    int t = 0;
    char code[100000];
    for(int i = 1; i < argc; i++){
        if(mystrcmp(argv[i], "-c")){
            c = i + 1;
        }
        if(mystrcmp(argv[i], "-t")){
            t = i + 1;
            attempts = atoi(argv[t]);
        }
    }
    
    if(c == 0){
        secretcode(code);add
    }else{
        mystrcpy(code, argv[c]);
    }
    printf("Will you find the secret code?\n");
    for(int i = 0; i < attempts; i++){
        wp = 0;
        mp = 0;
        printf("---\n");
        printf("Round %d\n", i);
        int correctInp;
        char buf[100000];
        do{
            correctInp = 1;
            printf(">");
            scanf("%s", buf);
            if(correct(buf) == 0){
                correctInp = 0;
            }

            if(correctInp == 0){
                printf("Wrong input!\n");
            }
        }while(correctInp != 1);

        for(int i = 0; i < 4; i++){
            if(code[i] == buf[i]){
                wp++;
            }else if(indexOf(code, buf[i]) != 0 && code[i] != buf[i]){
                mp++;
            }
        }
        if(wp == 4){
            printf("Congratz! You did it!\n");
            return 0;
        }else{
            printf("Well placed pieces: %d\n", wp);
            printf("Misplaced pieces: %d\n", mp);
        }
    }
}