#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int awaitProcess(int *randNum);
void getPath(const char *paths[], int randNum, int size);

int main(){

    while(1){

        const char *IMG_PATHS[] = { "/images/image1.jpg", "/photos/photo1.png", "/pics/pic1.jpg", "/images/image2.png/", "photos/photo2.jpg", "/pics/pic2.png", "/images/image3.jpg", "/photos/photo3.png", "/pics/pic3.jpg", "/images/image4.png", "/photos/photo4.jpg", "/pics/pic4.png", "/images/image5.jpg", "/photos/photo5.png", "/pics/pic5.jpg", "/images/image6.png", "/photos/photo6.jpg", "/pics/pic6.png", "/images/image7.jpg", "/photos/photo7.png" };
        int randNum = -1;

        // will stop checking when UI file = "run rng"
        while( !awaitProcess(&randNum) ){  }

        printf("rand num: %d\n", randNum);

        getPath(IMG_PATHS, randNum, sizeof(IMG_PATHS)/sizeof(IMG_PATHS[0]));

        sleep(1);

    }

    return 0;

}

int awaitProcess(int *randNum){

    FILE *UIfile = fopen("UI.txt", "r"); 

    const unsigned int size = 257;
    char *buffer = (char *) malloc(size);

    fgets(buffer, size, UIfile);
    
    if(strcmp(buffer, "run img\n") == 0){ fgets(buffer, size, UIfile); *randNum = atoi(buffer); return 1; }

    fclose(UIfile);

    return 0;
}

void getPath(const char *paths[], int randNum, int size){
    
    char *path = (char *) paths[randNum % size]; 
    FILE *IMGfile = fopen("IMG.txt", "w");

    fprintf(IMGfile, path);

    printf("PATH ADDED: %s\n", path);

    fclose(IMGfile);

}