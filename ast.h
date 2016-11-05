
// AST definitions
#ifndef __ast_h__
#define __ast_h__

// AST for expressions
struct _Expr {
  enum {E_INTEGER, E_VAR, E_OPERATION} kind;
  union {
    int value; // for integer values
    char* name;
    struct {
      int operator; // PLUS, MINUS, etc
      struct _Expr* left;
      struct _Expr* right;
    } op; // for binary expressions
  } attr;
};

struct _ExprList {
  struct _Expr* expr;
  struct _ExprList* next;
};

typedef struct _Expr Expr; // Convenience typedef
typedef struct _ExprList ExprList; // Convenience typedef

// AST for commands
struct _Cmd{
  enum{C_ATR, C_IF, C_ELSEIF, C_ELSE, C_WHILE, C_FOR, C_IN, C_OUT} kind;
  union{
    struct{char* var; struct _Expr* expr;} atrib;
    struct{struct _Expr* expr; struct _CmdList* next;} ifs;
    struct{struct _Expr* expr; struct _CmdList* next;} elseifs;
    struct{struct _CmdList* next;} elses;
    struct{struct _Expr* expr; struct _CmdList* next;} whiles;
    struct{struct _Cmd* cmd; struct _Expr* expr; struct _CmdList* next;} fors;
    struct{struct _Expr* expr;} out;
    struct{char* name;} in;
  }attr;
};

struct _CmdList {
  struct _Cmd* cmd;
  struct _CmdList* next;
};

typedef struct _Cmd Cmd; // Convenience typedef
typedef struct _CmdList CmdList; // Convenience typedef

// Constructor functions (see implementation in ast.c)
Expr* ast_integer(int v);
Expr* ast_var(char* var);
Expr* ast_operation(int operator, Expr* left, Expr* right);
ExprList* ast_exprlist(Expr* expr, ExprList* next);

Cmd* ast_atrib(char* var, Expr* e);
Cmd* ast_if(Expr* expr, CmdList* next);
Cmd* ast_elseif(Expr* expr, CmdList* next);
Cmd* ast_else(CmdList* next);
Cmd* ast_while(Expr* expr, CmdList* next);
Cmd* ast_for(Cmd* cmd, Expr* expr, CmdList* next);
Cmd* ast_out(Expr* expr);
Cmd* ast_in(char* name);
CmdList* ast_cmdlist(Cmd* expr, CmdList* next);

#endif
