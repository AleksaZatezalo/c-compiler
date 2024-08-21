#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
    char *value;
} TokenLiteral;


TokenLiteral *generate_number(char current, FILE *file){
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while(isdigit(current) && current != EOF){
        if(!isdigit(current)){
            break;
        }
        value[value_index] = current;
        value_index++;
        current = fgetc(file);
    }
    token->value = value;
    return token;
}

TokenKeyword *generate_keyword(char current, FILE *file){
    TokenKeyword *token = malloc(sizeof(TokenKeyword));
    char *keyword= malloc(sizeof(char) * 8);
    int keyword_index = 0; 
    while(isalpha(current) && current != EOF){
        if(current == '('){
            printf("FOUND OPEN PAREN\n");
            break;
        }
        keyword[keyword_index] = current;
        keyword_index++;
        current = fgetc(file);
    }
    for (int i = 0; i < keyword_index; i++){
        printf("%c\n", keyword[i]);
    }   
    
    if(!strcmp(keyword, "exit")){
        token->type = EXIT;
    }
    return token;
}

void lexer(FILE *file){
    char current = fgetc(file);

    while(current != EOF){
        if(current == ';'){
            printf("FOUND SEMICOLON\n");
        } else if (current == '('){
            printf("FOUND OPEN PAREN\n");
        } else if (current == ')'){
            printf("FOUND CLOSED PAREN\n");
        } else if (isdigit(current)){
            TokenLiteral *test_token = generate_number(current, file);
            printf("TEST TOKEN VALUE: %s\n", test_token->value);
        } else if (isalpha(current)){
            TokenKeyword *test_keyword = generate_keyword(current, file);
            if(test_keyword->type == EXIT){
                printf("EXIT\n");
            }    
        }
        current = fgetc(file);
    }
}


int main(){
    FILE *file;
    file = fopen("test.unn", "r");

    lexer(file);
    return 0;
}