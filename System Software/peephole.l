%{
#include "y.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return INTEGER; }
[ \t\n]     ; // Ignore whitespace and newline
.           return yytext[0]; // Return any other character as it is

%%

int yywrap() {
    return 1;
}
