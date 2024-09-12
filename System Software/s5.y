%{

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Symbol{
    char *name;
    char *type;
    int size;
    struct Symbol *next;
}Symbol;

Symbol *symbol_table = NULL;

void add_to_st(const char *name, const char *type , int size)
{
    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = strdup(type);
    sym->size = size;
    sym->next = symbol_table;
    symbol_table = sym;
}

void print_st()
{
    Symbol *sym = symbol_table;
    printf("Name\t\tType\t\tSize\n");
    while(sym != NULL)
    {
        printf("%s\t\t%s\t\t%d \n");
        sym=sym->next;
    }
}

%

%union{
    char *str;
}

%token <str> ID
%token INT FLOAT CHAR
%token SC

%%

program: declarations {print_st();} ;

    declarations: declarations declaration SC 
        |declaration SC
        ;

    declaration: 
        INT ID {add_to_st($2 , "int" , 4 );}
        |FLOAT ID {add_to_st($2 , "float" , 4 );}
        |CHAR ID {add_to_st($2 , "char" , 1 );}
        ;

%%

int main()
{
    printf("Enter the string: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("error");
    return 0;
}