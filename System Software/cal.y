%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%token NUM
%token ADD SUB MUL DIV

%%

calc: expr { printf("Result: %d\n", $1); }
    ;

expr: expr ADD expr { $$ = $1 + $3; }
    | expr SUB expr { $$ = $1 - $3; }
    | expr MUL expr { $$ = $1 * $3; }
    | expr DIV expr { $$ = $1 / $3; }
    | NUM { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
