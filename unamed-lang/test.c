#include <stdio.h>

int main(){
    FILE *fp;
    char buffer[0];

    fp = fopen("./test.unn", "r");

    fread(buffer, 1, 1, fp);
    printf("%c\n", *buffer);
    fclose(fp);

    return 0;
}