// Made by Lars Nielsen
// http://www.info-zip.org/mans/unzip.html
// http://stackoverflow.com/questions/29411929/systemcommand-returns-2304-in-c-but-why?noredirect=1#comment46997494_29411929

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // For checking file exist

#include<sys/types.h>
#include<sys/wait.h>

#include <assert.h>

int crack(char* cmd, char* pass, char* file){

    int size = strlen(cmd) + strlen(pass) -1 + strlen(file) + 3;
    int result = -1;
    char* fullcmd = malloc(size);

    //snprintf(fullcmd, size, "%s %s %s", cmd, pass, file);
    //printf("%s\n", fullcmd);
    strcpy(fullcmd, cmd);
    strcat(fullcmd, " ");
    strncat(fullcmd, pass, strlen(pass) -1 );
    strcat(fullcmd, " ");
    strcat(fullcmd, file);
    strcat(fullcmd, "\0");
    //printf("%s\n", fullcmd);

    //printf("Full Command: %s\n", fullcmd);
    result = system(fullcmd);

    //printf("Result: %d\n", WEXITSTATUS(result));
    if( WEXITSTATUS(result) == 9){
        printf("%s not found\n", file);
        assert(0);
    }else{
        printf("Status: %d\n", WEXITSTATUS(result));
    }

    free(fullcmd);
    //printf("return code: %d\n:", result);
    return result;
}


void setup(char* cmd, char* file){

    //Read passwords
    FILE* fp;
    char* pass = NULL;
    size_t len = 0;
    size_t read;

    fp  = fopen("passwords.txt", "r");
    if(fp == NULL){
        exit(EXIT_FAILURE);
    }

    while((read = getline(&pass, &len, fp)) != -1){
        if(crack(cmd, pass, file) == 0){
            printf("FILE cracked - password: %s\n", pass);
            break;
        }

    }

    fclose(fp);
    if(pass){
        free(pass);
    }
}

//unzip -p password filename

int main(int argc, char *argv[]){
    char *file = argv[1];

    printf("DEMO\n");
    if(access(file, F_OK) == -1){
        printf("Something went wrong \n");
        exit(EXIT_FAILURE);
    }
    setup("unzip  -o -P", file);

    exit(EXIT_SUCCESS);
}
