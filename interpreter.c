#include <stdio.h>
#include "parser.h"

void print_command(Cmd* command);
void print_expr(Expr* expr);

void print_tree(CmdList* l){
  if(l!=NULL){
    print_command(l->cmd);
    if(l->next !=NULL){
      printf("\n");
      print_tree(l->next);
    }
    else{
      return;
    }
  }
  else{
    printf("NULL");
    return;
  }
}

void print_expr(Expr* expr){
  printf("Expr(");
  switch(expr->kind){
  case E_INTEGER: printf("Int(%d)", expr->attr.value); break;
  case E_OPERATION:print_expr(expr->attr.op.left); printf("(");
    switch(expr->attr.op.operator){
    case PLUS: printf("PLUS)");
      break;
    case MINUS: printf("MINUS)");
      break;
    case MUL: printf("MUL)");
      break;
    case DIV: printf("DIV)");
      break;
    case MOD: printf("MOD)");
      break;
    case GT: printf(">)");
      break;
    case GE: printf(">=)");
      break;
    case LT: printf("<)");
      break;
    case LE: printf("<=)");
      break;
    case NE: printf("~=)");
      break;
    case EQ: printf("==)");
      break;
    default:
      break;
    }
    print_expr(expr->attr.op.right);
    break;
  default: printf("Var(%s)",expr->attr.name);
  }
  printf(")");
}

void print_command(Cmd* c){
  switch(c->kind){
  case C_IF:printf("IF(");
    print_expr(c->attr.ifs.expr);
    print_tree(c->attr.ifs.next); printf(")");
    break;

  case C_ELSEIF: printf("ELSEIF(");
    print_expr(c->attr.elseifs.expr);
    print_tree(c->attr.elseifs.next); printf(")");
    break;

  case C_ELSE: printf("ELSE(");
    print_tree(c->attr.elses.next); printf(")");
    break;

  case C_WHILE: printf("WHILE(");
    print_expr(c->attr.whiles.expr);
    print_tree(c->attr.whiles.next); printf(")");
    break;

  case C_FOR: printf("FOR(");
    print_command(c->attr.fors.cmd);
    print_expr(c->attr.fors.expr);
    print_tree(c->attr.fors.next);
    printf(")");
    break;

  case C_OUT: printf("OUTPUT(");
    print_expr(c->attr.out.expr);
    printf(")");
    break;

  case C_IN: printf("INPUT(Var(%s)", c->attr.in.name);
    printf(")");
    break;

  case C_ATR: printf("ATTRIBUTION(Var(%s)", c->attr.atrib.var);
    print_expr(c-> attr.atrib.expr);
    break;

  default:
    printf(")\n");
  }
}

int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  }
  if (yyparse() == 0) {
    print_tree(root);
    printf("\n");
  }
  return 0;
}
