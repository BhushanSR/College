%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>

extern int yylval;
%}

%%

#.*                             ; /* Skip preprocessor directives */
int                             { return INT; }
float                           { return FLOAT; }
char                            { return CHAR; }
double                          { return DOUBLE; }
void                            { return VOID; }
[a-zA-Z_][a-zA-Z0-9_]*          { yylval = strdup(yytext); return IDENTIFIER; }
[ \t\n]                         ; /* Skip whitespace */
.                               ; /* Skip other characters */

%%
