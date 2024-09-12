%{

#include<stdio.h>
int flag = 0;

%}

%token NUMBER;

%left "+" "-"
%left "*" "/" "%"
%left "(" ")"

%%

Expression: E{printf("Result = %d\n",$$);}

    E:E'+'E {$$=$1+$3;}
    |E'-'E {$$=$1-$3;}
    |E'*'E {$$=$1*$3;}
    |E'/'E {$$=$1/$3;}
    |E'%'E {$$=$1%$3;}
    |'('E')' {$$=$2;}
    |NUMBER {$$=$1;}
    ;
%%

int yyerror()
{
    printf("The expression is Invalid!!");
    flag = 1;
    return 0;
}

int main()
{
    printf("Enter the expression: ");
    yyparse();

    if(flag==0)
    {
        printf("The expression is valid!");

    }
    return 0;
}