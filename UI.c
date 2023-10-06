#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void runRNG();
int getRNG();
void runIMG(int randNum);
char *getIMG();
void clearAllFiles();

int main(){

    int user_input = 1;

    while(user_input == 1){

        printf("Request photo? (1 - yes; Other - no): ");
        scanf("%d", &user_input);
        printf("\n");

        // if user requests img, get it
        if(user_input == 1){

            // tell rng to create num
            runRNG();
            
            // get num from rng file
            int randNum = getRNG();
            
            // tell IMG to run with a given num
            runIMG(randNum);

            // get random IMG path
            printf("Random image: %s\n\n", getIMG());

            sleep(2);

            clearAllFiles();

        }

    }

    return 0;

}

void runRNG(){

    // open file to write command
    FILE *file = fopen("UI.txt", "w"); 

    fprintf(file, "run rng");

    fclose(file);

    sleep(1);

    return;
}

void runIMG(int randNum){

    // make num str
    char str[100];
    sprintf(str, "%d", randNum);

    // open file to write command
    FILE *file = fopen("UI.txt", "w"); 

    fprintf(file, "run img\n");
    fprintf(file, str);

    fclose(file);

    sleep(1);

    return;

}

// get response from RNG
int getRNG(){

    FILE *RNGfile = fopen("RNG.txt", "r");

    // Move the file pointer to the end of the file
    fseek(RNGfile, 0, SEEK_END);

    // Get the current position of the file pointer, which is the file size
    long file_size = ftell(RNGfile);

    rewind(RNGfile);

    if(file_size){ 

        const unsigned int size = 257;
        char *buffer = (char *) malloc(size);

        fgets(buffer, size, RNGfile);

        return atoi(buffer);

    }

    return -1;
    
}

// get response from IMG
char *getIMG(){

    FILE *IMGfile = fopen("IMG.txt", "r");

    const unsigned int size = 257;
    char *buffer = (char *) malloc(size);

    fgets(buffer, size, IMGfile);

    return buffer;
}

void clearAllFiles(){

    FILE *UIFile = fopen("UI.txt", "w");
    FILE *RNGFile = fopen("RNG.txt", "w");
    FILE *IMGFile = fopen("IMG.txt", "w");

}