%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern char *yytext;

struct Symbol {
    char name[20];
    char type[20];
};

#define MAX_SYMBOLS 100
struct Symbol symbol_table[MAX_SYMBOLS];
int num_symbols = 0;

void addSymbol(char *name, char *type) {
    if (num_symbols < MAX_SYMBOLS) {
        strcpy(symbol_table[num_symbols].name, name);
        strcpy(symbol_table[num_symbols].type, type);
        num_symbols++;
    } else {
        printf("Symbol table full. Cannot add symbol %s.\n", name);
    }
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("%-10s %-10s\n", "Name", "Type");
    for (int i = 0; i < num_symbols; i++) {
        printf("%-10s %-10s\n", symbol_table[i].name, symbol_table[i].type);
    }
}

int yywrap() {
    return 1;
}
%}

%union {
    char name[20];
}

%token <name> IDENTIFIER
%token INT FLOAT CHAR DOUBLE VOID

%type <name> type

%%

program : declaration_list
        ;

declaration_list : declaration
                 | declaration_list declaration
                 ;

declaration : type IDENTIFIER ';'
            {
                addSymbol($2, $1); // $2 is the name, $1 is the type
            }
            ;

type : INT
     | FLOAT
     | CHAR
     | DOUBLE
     | VOID
     ;

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    yyin = fp;

    yyparse();

    fclose(fp);

    displaySymbolTable();

    return 0;
}
