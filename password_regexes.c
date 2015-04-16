// Made by Lars Nielsen
//
// This is a hobby project, please do not use
// it for any harmfull things.
//
// http://www.cheatography.com/davechild/cheat-sheets/regular-expressions/

#include <stdio.h>
#include <stdlib.h>

#include <time.h> // used for seeding random

#include <regex.h> // Not in use yet

const char uppercase[] = {'A', 'B', 'C', 'D', 'E', 'F',
                        'G', 'H', 'I', 'J', 'K', 'L',
                        'M', 'N', 'O', 'P', 'Q', 'R',
                        'S', 'T', 'U', 'V', 'W', 'X',
                        'Y', 'Z'};

const char lowercase[] = {'a', 'b', 'c', 'd', 'e', 'f',
                          'g', 'h', 'i', 'j', 'k', 'l',
                          'm', 'n', 'o', 'p', 'q', 'r',
                          's', 't', 'u', 'v', 'w', 'x',
                          'y', 'z'};

const char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Generates password containg both lower
// and upper case letters and numbers
void create_full_password(char* password, int size){
    srand(time(NULL));
    int i;
    for(i = 0; i < size; i++){
        int r = rand() % 3;
        if(r == 0 || r == 1){
            int index = rand() % 25;
            if(r == 0){
                password[i] = uppercase[index];
            }else{
                password[i] = lowercase[index];
            }
        }else{
            int index = rand() % 9;
            password[i] = numbers[index];
        }
    }
}

// Create password containg only lower case, upper case or numbers
// Type 0: lower case chars
// Type 1: upper case chars
// Type 2: numbers
void create_singular_password(char* password, int size, int type){
    srand(time(NULL));
    int i;
    for(i = 0; i < size; i++){
        if(type != 2){
            int index = rand() % 25;
            if(type == 0){
                password[i] = lowercase[index];
            }else{
                password[i] = uppercase[index];
            }
        }else{
            int index = rand() % 9;
            password[i] = numbers[index];
        }
    }
}

int main(){
    char* password = malloc(sizeof(char) * 4);
    create_full_password(password, 4);
    printf("String: %s\n", password);
    create_singular_password(password, 4, 0);
    printf("Lower case only %s\n", password);
    create_singular_password(password, 4, 1);
    printf("Upper case only %s\n", password);
    create_singular_password(password, 4, 2);
    printf("Numbers case only %s\n", password);
    return 0;
}
