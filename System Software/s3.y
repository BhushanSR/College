%{
#include<stdio.h>    
%}

%token DType ID C SC NL 

%%

start:DType varlist SC NL {printf("Syntax Correct");}
    |varlist:varlist C ID|ID;

%%

int yyerror()
{
    printf("Syntax Error");
}

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the String:");
    yyparse();
    return 0;
}