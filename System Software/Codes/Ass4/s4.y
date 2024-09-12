%{
#include<stdio.h>    
%}

%token compund word dot

%%
start: wordlist compund wordlist dot {printf("Compound");}
    |wordlist dot {printf("Simple");}
    ;

    wordlist: word wordlist
    |word
    ;
    
%%

int main()
{
    printf("Enter the Sentence: ");
    yyparse();
    return 0;
}

int yywrap()
{
    return 1;

}

int yyerror()
{
    printf("Error");
}