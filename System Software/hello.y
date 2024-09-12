%{
#include <stdio.h>
%}

%token HELLO NEWLINE

%%

program: greetings NEWLINE
       | greetings NEWLINE program
       ;

greetings: HELLO
         ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
