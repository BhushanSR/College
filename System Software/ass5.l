%{
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100

struct Symbol {
    char name[20];
    char type[20];
    int size;
};

struct Symbol symbol_table[MAX_TOKENS];
int num_symbols = 0;

void addSymbol(char *name, char *type, int size) {
    if (num_symbols < MAX_TOKENS) {
        strcpy(symbol_table[num_symbols].name, name);
        strcpy(symbol_table[num_symbols].type, type);
        symbol_table[num_symbols].size = size;
        num_symbols++;
    } else {
        printf("Symbol table full. Cannot add symbol %s.\n", name);
    }
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("%-10s %-10s %-10s\n", "Name", "Type", "Size");
    for (int i = 0; i < num_symbols; i++) {
        printf("%-10s %-10s %-10d\n", symbol_table[i].name, symbol_table[i].type, symbol_table[i].size);
    }
}

%}

%option noyywrap

identifier [a-zA-Z_][a-zA-Z0-9_]*
integer [0-9]+

%%

{identifier}    {
                    char type[20];
                    int size = 0;
                    yytext[yyleng] = '\0'; // Null-terminate the string
                    printf("Identifier: %s\n", yytext);
                    printf("Enter type for %s: ", yytext);
                    scanf("%s", type);
                    addSymbol(yytext, type, size);
                  }

{integer}       { /* Ignore integers for now */ }

[ \t\n]         ; // Ignore whitespace

.               printf("Unrecognized token: %s\n", yytext);

%%

int main(void) {
    printf("Enter your code:\n");
    yylex();
    displaySymbolTable();
    return 0;
}
