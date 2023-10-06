#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int awaitProcess();
void createNum();

int main(){

    while(1){

        // set seed for RNG
        srand(time(NULL));

        // will stop checking when UI file = "run rng"
        while( !awaitProcess() ){ }

        createNum();

    }

    return 0;

}

int awaitProcess(){

    FILE *UIfile = fopen("UI.txt", "r"); 

    const unsigned int size = 257;
    char *buffer = (char *) malloc(size);

    fgets(buffer, size, UIfile);
    
    if(strcmp(buffer, "run rng") == 0){ return 1; }

    fclose(UIfile);

    return 0;
}

void createNum(){

    FILE *RNGfile = fopen("RNG.txt", "w");

    // make rand num to str
    int randNum = rand();
    char str[100];
    sprintf(str, "%d", randNum);

    fprintf(RNGfile, str);
    fclose(RNGfile);

}
