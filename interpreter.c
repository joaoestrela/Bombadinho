#include <stdio.h>
#include "parser.h"

//evaluation of an expression
int eval(Expr* expr) {
  int result = 0;
  if (expr == 0) {
    yyerror("Null expression!!");
  }
  else if (expr->kind == E_INTEGER) {
    result = expr->attr.value;
  }
  else if (expr->kind == E_OPERATION) {
    int vLeft = eval(expr->attr.op.left);
    int vRight = eval(expr->attr.op.right);
    switch (expr->attr.op.operator) {
      case PLUS:
        result = vLeft + vRight;
        break;
      case MINUS:
        result = vLeft - vRight;
        break;
      case MUL:
        result = vLeft * vRight;
        break;
      case DIV:
        result = vLeft / vRight;
        break;
      case MOD:
        result = vLeft % vRight;
        break;
      case EQ:
        if(vLeft == vRight) result = 1;
        else result = 0;
        break;
      case GE:
        if(vLeft >= vRight) result = 1;
        else result = 0;
        break;
      case GT:
        if(vLeft > vRight) result = 1;
        else result = 0;
        break;
      case LE:
        if(vLeft <= vRight) result = 1;
        else result = 0;
        break;
      case LT:
        if(vLeft < vRight) result = 1;
        else result = 0;
      case NE:
        if(vLeft != vRight) result = 1;
        else result = 0;
        break;
      default: yyerror("Unknown operator!");
    }
  }
  return result;
}


int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //  yyin = stdin
  if (yyparse() == 0) {
    while(root != NULL){
      //printf("Result = %d\n", eval(root->expr));
      root = root->next;
    }
  }
  return 0;


}
