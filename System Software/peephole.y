%{
#include <stdio.h>
%}

%token INTEGER

%%

expr : INTEGER '+' INTEGER  { printf("%d + %d\n", $1, $3); $$ = $1 + $3; }
     | INTEGER '-' INTEGER  { printf("%d - %d\n", $1, $3); $$ = $1 - $3; }
     | INTEGER '*' INTEGER  { printf("%d * %d\n", $1, $3); $$ = $1 * $3; }
     | INTEGER '/' INTEGER  { printf("%d / %d\n", $1, $3); $$ = $1 / $3; }
     ;

%%

int main() {
    yyparse();
    return 0;
}
