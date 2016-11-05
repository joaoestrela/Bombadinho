// AST constructor functions

#include <stdlib.h> // for malloc
#include <string.h> // for strdup
#include "ast.h" // AST header

// Expression AST

Expr* ast_integer(int v) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_INTEGER;
  node->attr.value = v;
  return node;
}

Expr* ast_var(char* var){
  Expr* node =(Expr*) malloc(sizeof(Expr));
  node->kind = E_VAR;
  node->attr.name = strdup(var);
  return node;
}

Expr* ast_operation(int operator, Expr* left, Expr* right) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_OPERATION;
  node->attr.op.operator = operator;
  node->attr.op.left = left;
  node->attr.op.right = right;
  return node;
}

// Expression List AST
ExprList* ast_exprlist(Expr* expr, ExprList* next) {
  ExprList* node = (ExprList*) malloc(sizeof(ExprList));
  node->expr = expr;
  node->next = next;
  return node;
}

// Command AST

Cmd* ast_atrib(char* var, Expr* e){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind = C_ATR;
  node->attr.atrib.var=strdup(var);
  node->attr.atrib.expr=e;
  return node;
}

Cmd* ast_if(Expr* expr, CmdList* next){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_IF;
  node->attr.ifs.expr=expr;
  node->attr.ifs.next=next;
  return node;
}

Cmd* ast_elseif(Expr* expr, CmdList* next){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_ELSEIF;
  node->attr.elseifs.expr=expr;
  node->attr.elseifs.next=next;
  return node;
}

Cmd* ast_else(CmdList* next){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_ELSE;
  node->attr.elses.next=next;
  return node;
}

Cmd* ast_while(Expr* expr, CmdList* next){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_WHILE;
  node->attr.whiles.expr=expr;
  node->attr.whiles.next=next;
  return node;
}

Cmd* ast_for(Cmd* cmd,Expr* expr, CmdList* next){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_FOR;
  node->attr.fors.cmd=cmd;
  node->attr.fors.expr=expr;
  node->attr.fors.next=next;
  return node;
}

Cmd* ast_out(Expr* expr){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_OUT;
  node->attr.out.expr=expr;
  return node;
}

Cmd* ast_in(char* name){
  Cmd* node = (Cmd*) malloc(sizeof(Cmd));
  node->kind=C_IN;
  node->attr.in.name=name;
  return node;
}

// Command List AST

CmdList* ast_cmdlist(Cmd* cmd, CmdList* next) {
  CmdList* node = (CmdList*) malloc(sizeof(CmdList));
  node->cmd = cmd;
  node->next = next;
  return node;
}
