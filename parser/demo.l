%{
#include <stdio.h>
#include "demo.tab.h"

%}

number          [0-9]+
ws              [ \t] 

%%
{number}        {yylval.number = atoi(yytext); return NUMBER;}
heat            return TOKHEAT;
on|off          {yylval.string = yytext; return STATE;}
target          return TOKTARGET;
temperature     return TOKTEMPERATURE;
\n              ++yylineno;
{ws}+          /* ignored */;
%%

