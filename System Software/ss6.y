%{
/* Declaration Section */

#include <stdio.h>

int flag = 0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
S: E {
    printf("\nResult = %d\n", $$);
    return 0;
}

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { $$ = $1 / $3; }
 | E '%' E { $$ = $1 % $3; }
 | '(' E ')' { $$ = $2; }
 | NUMBER { $$ = $1; }
 ;

%%


void main() {
    printf("\nEnter any arithmetic expression: ");

    yyparse();

    if (flag == 0)
        printf("\nEntered arithmetic expression is valid\n\n");


}
void yyerror()
{
printf("\nExpression is invalid\n\n");
flag=1;
}