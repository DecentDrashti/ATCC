//identify tokens in the input source code file
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[]) {
    char keywords[][10] = {
        "int", "float", "if", "else", "while",
        "for", "return", "char", "double", "void"
    };

    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/=<>";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int isSpecialSymbol(char ch) {
    char symbols[] = ";,(){}[]";
    for (int i = 0; i < strlen(symbols); i++) {
        if (ch == symbols[i])
            return 1;
    }
    return 0;
}

void main() {
    FILE *f;
    char token[50];

    int keyword_count = 0, identifier_count = 0;
    int operator_count = 0, constant_count = 0;
    int special_symbol_count = 0;

    f = fopen("file.txt", "r");

    if (f == NULL) {
        //printf("File not found\n");
        return 0;
    }

    while (fscanf(f, "%s", token) ==1) {

        // KEYWORD
        if (isKeyword(token)) {
            //printf("Keyword: %s\n", token);
            keyword_count++;
        }

        // CONSTANT
        else if (isdigit(token[0])) {
            //printf("Constant: %s\n", token);
            constant_count++;
        }

        // IDENTIFIER
        else if (isalpha(token[0]) || token[0] == '_') {
           // printf("Identifier: %s\n", token);
            identifier_count++;
        }

        // Check each character for operator / symbol
        for (int i = 0; token[i] != '\0'; i++) {

            if (isOperator(token[i])) {
                //printf("Operator: %c\n", token[i]);
                operator_count++;
            }

            else if (isSpecialSymbol(token[i])) {
                //printf("Special Symbol: %c\n", token[i]);
                special_symbol_count++;
            }
        }
    }

    fclose(f);

    printf("\n--- COUNT ---\n");
    printf("Keywords: %d\n", keyword_count);
    printf("Identifiers: %d\n", identifier_count);
    printf("Constants: %d\n", constant_count);
    printf("Operators: %d\n", operator_count);
    printf("Special Symbols: %d\n", special_symbol_count);
}
