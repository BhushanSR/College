%{
    #include<stdio.h>
    int lines = 0;
    int words = 0;
    int characters = 0;
    int spaces = 0;    
%}

%%

[\n] {lines++ ; characters++;}
[^ \t \n] {words++ ; characters = characters + yyleng ;}
[ \t ] {spaces++ ; characters = characters + yyleng ;}

%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("D:/VS Code/System Software/Codes/Ass1/abc.txt" , "r");
    yylex();
    printf("NUMBER OF\n");
    printf("Lines : %d \n",lines);
    printf("Words : %d \n",words);
    printf("Characters : %d \n",characters);
    printf("Spaces : %d",spaces);

    return 0;
}

