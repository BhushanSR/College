%{
#include"y.tab.h"
%}
%token word compund dot
%%
start:wordlist compund wordlist dot {printf("\n Compund Sentence");}
       |wordlist dot {printf("\n Simple Sentence");};
       |wordlist:word wordlist
               |word
               ;
%%
int main()
{
  yyparse();
  return 0;
}
int yywrap()
{
 return 0;
}
void yyerror(const char *str)
{ 
printf("Error");
}
