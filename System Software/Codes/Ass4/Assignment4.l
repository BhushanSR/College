%{
#include<stdio.h>
#include"y.tab.h"
%}
%%
[a-zA-Z0-9_] {return word;}
and|AND|but|BUT|or|OR|Or {return compund;}
\. {return dot;}
%%
