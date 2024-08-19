#include <stdio.h>
#include <stdlib.h>

typedef enum{
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TypeSeperator;

typedef enum{
    EXIT,
} TypeKeyword;
typedef enum{
    INT,
} TypeLiteral;

typedef struct{
    TypeSeperator type;
} TokenSeperator;

typedef struct{
    TypeKeyword type;
} TokenKeyword;

typedef struct{
    TypeLiteral type;
    int value;
} TokenLiteral;


int main(){
    TokenLiteral token;
    token.type = INT;
    token.value = 5;
    printf("%d\n", token.value);
    return 0;
}