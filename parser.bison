// Tokens
%token
//
INT // Intenger
VAR // Variable
// Arithmetics
PLUS // Addition
MINUS // Substraction
MUL // Element-wise power
DIV // Right array division
MOD // Remainder after division (modulo operation)
// Relational Operations
EQ // Determine equality
GE // Determine greater then or equal to
GT // Determine greater then
LE // Determine less than or equal to
LT // Determine less then
NE // Determine inequaility
// Logical Operations
TRUE // Logical 1 (true)
FALSE // Logical 0 (false)
// Control Flow
IF // Execute statements if condition is true
ELSEIF // Execute statements if condition is true
ELSE // Execute statements if condition is true
FOR // for loop to repeat specified number of times
TO // Iterate values
WHILE // while loop to repeat when condition is true
END // Terminate block of code, or indicate last array index
//Brackets
LB // Left Bracket
RB // Right Bracket
EOC // Marks the end of a command
//Commands
ATR // Attribution
OUTPUT // Display value of variable
INPUT // Request user input


// Operator associativity & precedence
%nonassoc EQ GE GT LE LT NE
%left PLUS MINUS
%left MUL DIV MOD

// Root-level grammar symbol
%start program;

// Types/values in association to grammar symbols.
%union {
int intValue;
char* varValue;
Expr* exprValue;
ExprList* exprList;
Cmd* cmd;
CmdList* cmdList;
}

%type <intValue> INT
%type <varValue> VAR
%type <exprValue> expr
%type <cmd> cmd
%type <cmdList> cmd_list

// Use "%code requires" to make declarations go
// into both parser.c and parser.h
%code requires {
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
struct _CmdList* root;
}

%%
program: cmd_list {root = $1;}

expr:
INT {$$ = ast_integer($1);}
|  FALSE {$$ = ast_integer(0);}
|  TRUE {$$ = ast_integer(1);}
|  VAR {$$ = ast_var($1);}
|  LB expr RB {$$ = $2;}
|  expr PLUS expr {$$ = ast_operation(PLUS, $1, $3);}
|  expr MINUS expr {$$ = ast_operation(MINUS, $1, $3);}
|  expr MUL expr {$$ = ast_operation(MUL, $1, $3);}
|  expr DIV expr {$$ = ast_operation(DIV, $1, $3);}
|  expr MOD expr {$$ = ast_operation(MOD, $1, $3);}
|  expr EQ expr {$$ = ast_operation(EQ, $1, $3);}
|  expr GE expr {$$ = ast_operation(GE, $1, $3);}
|  expr GT expr {$$ = ast_operation(GT, $1, $3);}
|  expr LE expr {$$ = ast_operation(LE, $1, $3);}
|  expr LT expr {$$ = ast_operation(LT, $1, $3);}
|  expr NE expr {$$ = ast_operation(NE, $1, $3);}

cmd: VAR ATR expr EOC {$$ = ast_atrib($1,$3);}
| VAR ATR expr {$$ = ast_atrib($1,$3);}
| IF expr cmd_list END {$$ = ast_if($2,$3);}
| ELSEIF expr cmd_list {$$ = ast_elseif($2,$3);}
| ELSE cmd_list {$$ = ast_else($2);}
| WHILE expr cmd_list END {$$ = ast_while($2,$3);}
| FOR cmd TO expr cmd_list END {$$ = ast_for($2,$4,$5);}
| OUTPUT LB expr RB EOC {$$ = ast_out($3);}
| VAR ATR INPUT LB RB EOC {$$ = ast_in($1);}

cmd_list: cmd {$$ = ast_cmdlist($1,NULL);}
| cmd cmd_list {$$ = ast_cmdlist($1,$2);}

;
%%

void yyerror(const char* err) {
printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}
