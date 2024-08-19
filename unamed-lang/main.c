#include <stdio.h>
#include <stdlib.h>

typedef enum{
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TokenTypeSeperator;

typedef enum{
    EXIT,
} TokenTypeKeyword;
typedef enum{
    INT,
} TokenTypeLiteral;

int main(){
    printf("Hello, world!\n");
    return 0;
}