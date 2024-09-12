%{
#include "calculator.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUM; }
[ \t\n]     ;
"+"         { return ADD; }
"-"         { return SUB; }
"*"         { return MUL; }
"/"         { return DIV; }
.           { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}
