%{
#include<stdio.h>
#include"y.tab.h"    
%}

%%

int|float|char {return DType;}
[a-zA-Z_][a-zA-Z_0-9]* {return ID;}
"["[0-9]"]" {return VAL;}
"," {return C;}
";" {return SC;}
"\n" {return NL;}

%%
