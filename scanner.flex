%{
// HEADERS
#include <stdlib.h>
#include "parser.h"

// variables maintained by the lexical analyser
int yyline = 1;
%}

%option noyywrap

%%
[ \t]+ {  }
#.*\n { yyline++; }
\n { yyline++; }

\-?[0-9]+ { yylval.intValue = atoi(yytext); return INT; }

"==" { return EQ; }
">=" { return GE; }
">" { return GT; }
"<=" { return LE; }
"<" { return LT; }
"!=" { return NE; }
"~=" { return NE; }

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"%" { return MOD; }

"true" {return TRUE; }
"false" {return FALSE; }

"if" { return IF; }
"elseif" { return ELSEIF; }
"else" { return ELSE; }
"for" { return FOR; }
":" { return TO; }
"while" { return WHILE; }
"end" { return END; }

"(" { return LB; }
")" { return RB; }
";" { return EOC; }
"=" { return ATR; }

"disp" { return OUTPUT; }
"input" { return INPUT; }

\-?[a-zA-Z]+ { yylval.varValue = strdup(yytext); return VAR; }

. { yyerror("unexpected character"); }
%%
