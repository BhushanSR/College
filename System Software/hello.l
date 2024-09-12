%{
#include "y.tab.h"
%}

%%

"hello"     { return HELLO; }
\n          { return NEWLINE; }
.           { /* Ignore all other characters */ }

%%

int yywrap() {
    return 1;
}
