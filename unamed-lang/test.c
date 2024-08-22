#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    char *buffer = 0;
    long length;

    file = fopen("test.unn", "r");

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0 , SEEK_SET);
    buffer = malloc(length);

    fread(buffer, 1, length, file);
    printf("%c\n", *buffer);
    fclose(file);

    return 0;
}