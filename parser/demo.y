%{
#include <stdio.h>
#include <string.h>

//int yydebug = 1;
extern int yylineno;
int yyerror(const char*);
int yylex();
%}

%token TOKHEAT TOKTARGET TOKTEMPERATURE

%union
{
    int number;
    char* string;
}

%token <number> NUMBER
%token <string> STATE

%%
commands:
         /* empty */
        | commands command
        ;

command:
       heat_switch
       | target_set
       ;

heat_switch:
           TOKHEAT STATE
           {
                printf("Heat turned %s\n", $2);
           }
           ;


target_set:
          TOKTARGET TOKTEMPERATURE NUMBER
          {
                printf("Temperature set to %d\n", $3);
          }
          ;
%%

int yyerror(const char* str)
{
    fprintf(stderr, "error %s encountered at line %u\n", str, yylineno);
    return 1;
}

int yywrap()
{
    return 1;
}

int main()
{
    yyparse();
    return 0;
}
