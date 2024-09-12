%{
	#include<stdio.h>
%}

%token datatype id comma semicolon newline value

%%
start:datatype varlist semicolon newline {printf("Given statement syntax is correct");}
	|varlist:varlist comma id|id;
%%

int main()
{
	yyparse();
	return 0;
}
int yywrap()
{
	return 1;
}
void yyerror(const char *str)
{ 	
	printf("Syntax Error");
}

