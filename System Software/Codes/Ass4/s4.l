%{
#include<stdio.h>
#include"y.tab.h"    
int flag = 0;
%}

%%
and|AND|BUT|but|or|OR {return compound;}
[a-zA-Z0-9_]+ {return word;}
\. {return dot;}

%%
