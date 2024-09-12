%{
#include<stdio.h>
#include<stdlib.h>   
#include<string.h>   
#include"y.tab.h"     

void add_to_st(const char *name, const char *type , int size);
%}

%%

int {return INT;}
float {return FLOAT;}
char {return CHAR;}
[a-zA-Z_][a-zA-Z0-9_]* {return ID;}
";" {return SC;}
[ \t] { }
. {printf("%s not recognized",yytext);}

%%

int yywrap()
{
    return 1;
}

