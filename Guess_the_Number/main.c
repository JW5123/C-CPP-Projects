#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
int computer = 0, player = 0;
int mode(){
    int num = 0, inp;
    printf("Input gamemode: [1]Simple [2]Normal [3]Difficult [4]Customize:\n");
    scanf("%d", &inp);
    if(inp == 1)
        num = 25;
    else if(inp == 2)
        num = 15;
    else if(inp == 3)
        num = 5;
    else{
        printf("Input you want to play times: ");
        scanf("%d", &num);
    }
    return num;
}
void PlayGame(){
    srandom((unsigned)time(NULL) + getpid());
    int number = random() % 10 + 1;
    int guess = 0, num = 0;
    num = mode();
    while(num--){
        printf("Guess Number 0-100: ");
        scanf("%d", &guess);
        if(num == 0)
            break;
        if(guess > number)
            printf("Guess to Big!\n");
        else if(guess < number)
            printf("Guess to small!\n");
        else{
            printf("Guess right!\n");
            break;
        }
        printf("[%d] opportunities remaining\n", num);
    }
    if(!num){
        printf("╔════════════╗\n"
               "║ You lose!! ║\n"
               "╚════════════╝\n");
        computer++;
    }
    else{
        printf("╔════════════╗\n" 
               "║  You Win!! ║\n"
               "╚════════════╝\n");
        player++;
    }
    printf("Whether to continue?\n");
}
void Query(){
    FILE *fp = fopen("/Users/renjiewang/Desktop/Application_Program/C_C++/Guess_Number/grade.txt", "r");
    char p[50] = {0};
    if(fp == NULL)
        exit(-1);
    else{
        fgets(p, 50, fp);
        printf("%s\n", p);
    }
    fclose(fp);
    printf("Whether to continue?\n");
}
void store(){
    FILE *fp = fopen("/Users/renjiewang/Desktop/Application_Program/C_C++/Guess_Number/grade.txt", "w");
    if(fp == NULL)
        exit(-1);
    else
        fprintf(fp, "computer : player = %d : %d", computer, player);
    fclose(fp);
}
int main(){
    int select;
    while(1){
        printf("╔═════════════════════╗\n"
               "║      1.Play         ║\n"
               "║      2.Query        ║\n"
               "║      0.Exit         ║\n"
               "╚═════════════════════╝\n");
        printf("=> ");
        scanf("%d", &select);
        switch(select){
            case 1:
                PlayGame();
                store();
                break;
            case 2:
                Query();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Re-Enter!!\n");
        }
    }
    return 0;
}
