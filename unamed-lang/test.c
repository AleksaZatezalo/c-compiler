#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    char *buffer = 0;
    long length;

    file = fopen("test.unn", "r");

    if(!file){
        printf("ERROR: COULD NOT OPEN FILE\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0 , SEEK_SET);
    buffer = malloc(length + 1);

    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    printf("%s\n", buffer);
    fclose(file);

    return 0;
}