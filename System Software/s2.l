%{
	#include<stdio.h>
%}

%%

[/\*].*[\*/] {printf("Multiline Comment: \n %s \n ",yytext);}
"#" {printf("Preprocessor Statement: %s",yytext);}
[a-z]+[\.][h] {printf("Header File : \n %s \n",yytext);}
int|float|double|char|printf|scanf|void|main {printf("Keywords: \n %s \n",yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("Identifier: \n %s \n",yytext);}
"+"|"-"|"/"|"*" {printf("Operators: \n %s \n",yytext);}
";"|"("|")"|"{"|"}"|"["|"]"|"<"|">"|"," {printf("Punctuation: \n %s \n",yytext);}
[0-9]+ {printf("Integer : \n %s \n",yytext);}
[0-9]+[\.][0-9]+ {printf("Float: \n %s \n",yytext);}
["].*["] {printf("Literals: \n %s \n",yytext);}
"//".*[\n] {printf("Single Line Comment: \n %s \n",yytext);}

%%

int yywrap()
{
	return 1;

}

int main()
{
	yyin = fopen("D:/VS Code/System Software/Codes/Ass2/ass2.c","r");
	yylex();

	return 0;
}