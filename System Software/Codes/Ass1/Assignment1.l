%{
 #include<stdio.h>
 int cnt = 0;
 int wc = 0;
 int cc = 0;
 int sp = 0;
%}
%%
[\n] {cnt++; cc++;}
[^ \t\n]+ {wc++; cc = cc + yyleng;}
[ \t] {sp++; cc=cc + yyleng;}
%%
int yywrap()
{
 return 1;
}
int main()
{
 yyin = fopen("abc.txt","r");
 yylex();
 printf("\n Number of lines: %d",cnt);
 printf("\n Number of words: %d",wc);
 printf("\n Number of Characters: %d",cc);
 printf("\n Number of spaces: %d",sp);
 return 0;
}
