
%{
        #include<stdio.h>
%}

%%
[/\*].*[\*/] {printf("\n%s is Multiline comment",yytext);}
"#" {printf("\n%s is Preprocesssor statement",yytext);}
[a-z]+[\.][h] {printf("\n%s is Header file",yytext);}
int|float|double|printf|scanf|void|main {printf("\n%s is Keyword",yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("\n%s is an Identifier",yytext);}
"+"|"-"|"=" {printf("\n%s is an Operator",yytext);}
[0-9]+ {printf("\n%s is Number",yytext);}
[0-9]+[\.][0-9]+ {printf("\n%s is Number",yytext);}
";"|","|"("|")"|"["|"]"|"{"|"}"|"<"|">" {printf("\n%s is Punctuation",yytext);}
["].*["] {printf("\n%s is Literals",yytext);}
"//".* {printf("\n%s is Single line Comment",yytext);}       
%%
int yywrap()
{
         return 1;
}
int main()
{
        yyin=fopen("ass2.c","r");
        yylex();
        return 0;
}
