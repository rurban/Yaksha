// ast.h
// generated by update_ast.py
#ifndef AST_H
#define AST_H
#include "tokenizer/token.h"
#include "utilities/annotations.h"
#include "utilities/ykdatatype.h"
#include <vector>
namespace yaksha {
  // ------ forward declarations ------
  struct expr;
  struct stmt;
  struct parameter;
  struct assign_expr;
  struct assign_arr_expr;
  struct assign_member_expr;
  struct binary_expr;
  struct fncall_expr;
  struct get_expr;
  struct grouping_expr;
  struct literal_expr;
  struct logical_expr;
  struct set_expr;
  struct square_bracket_access_expr;
  struct square_bracket_set_expr;
  struct unary_expr;
  struct variable_expr;
  struct block_stmt;
  struct break_stmt;
  struct ccode_stmt;
  struct class_stmt;
  struct const_stmt;
  struct continue_stmt;
  struct def_stmt;
  struct defer_stmt;
  struct del_stmt;
  struct elif_stmt;
  struct expression_stmt;
  struct if_stmt;
  struct import_stmt;
  struct let_stmt;
  struct pass_stmt;
  struct return_stmt;
  struct while_stmt;
  // Types of expressions and statements
  enum class ast_type {
    EXPR_ASSIGN,
    EXPR_ASSIGN_ARR,
    EXPR_ASSIGN_MEMBER,
    EXPR_BINARY,
    EXPR_FNCALL,
    EXPR_GET,
    EXPR_GROUPING,
    EXPR_LITERAL,
    EXPR_LOGICAL,
    EXPR_SET,
    EXPR_SQUARE_BRACKET_ACCESS,
    EXPR_SQUARE_BRACKET_SET,
    EXPR_UNARY,
    EXPR_VARIABLE,
    STMT_BLOCK,
    STMT_BREAK,
    STMT_CCODE,
    STMT_CLASS,
    STMT_CONST,
    STMT_CONTINUE,
    STMT_DEF,
    STMT_DEFER,
    STMT_DEL,
    STMT_ELIF,
    STMT_EXPRESSION,
    STMT_IF,
    STMT_IMPORT,
    STMT_LET,
    STMT_PASS,
    STMT_RETURN,
    STMT_WHILE
  };
  // ------ expression visitor ------
  struct expr_visitor {
    virtual void visit_assign_expr(assign_expr *obj) = 0;
    virtual void visit_assign_arr_expr(assign_arr_expr *obj) = 0;
    virtual void visit_assign_member_expr(assign_member_expr *obj) = 0;
    virtual void visit_binary_expr(binary_expr *obj) = 0;
    virtual void visit_fncall_expr(fncall_expr *obj) = 0;
    virtual void visit_get_expr(get_expr *obj) = 0;
    virtual void visit_grouping_expr(grouping_expr *obj) = 0;
    virtual void visit_literal_expr(literal_expr *obj) = 0;
    virtual void visit_logical_expr(logical_expr *obj) = 0;
    virtual void visit_set_expr(set_expr *obj) = 0;
    virtual void
    visit_square_bracket_access_expr(square_bracket_access_expr *obj) = 0;
    virtual void
    visit_square_bracket_set_expr(square_bracket_set_expr *obj) = 0;
    virtual void visit_unary_expr(unary_expr *obj) = 0;
    virtual void visit_variable_expr(variable_expr *obj) = 0;
    virtual ~expr_visitor() = default;
  };
  // ------ statement visitor ------
  struct stmt_visitor {
    virtual void visit_block_stmt(block_stmt *obj) = 0;
    virtual void visit_break_stmt(break_stmt *obj) = 0;
    virtual void visit_ccode_stmt(ccode_stmt *obj) = 0;
    virtual void visit_class_stmt(class_stmt *obj) = 0;
    virtual void visit_const_stmt(const_stmt *obj) = 0;
    virtual void visit_continue_stmt(continue_stmt *obj) = 0;
    virtual void visit_def_stmt(def_stmt *obj) = 0;
    virtual void visit_defer_stmt(defer_stmt *obj) = 0;
    virtual void visit_del_stmt(del_stmt *obj) = 0;
    virtual void visit_expression_stmt(expression_stmt *obj) = 0;
    virtual void visit_if_stmt(if_stmt *obj) = 0;
    virtual void visit_import_stmt(import_stmt *obj) = 0;
    virtual void visit_let_stmt(let_stmt *obj) = 0;
    virtual void visit_pass_stmt(pass_stmt *obj) = 0;
    virtual void visit_return_stmt(return_stmt *obj) = 0;
    virtual void visit_while_stmt(while_stmt *obj) = 0;
    virtual ~stmt_visitor() = default;
  };
  // ------ expression base class ------
  struct expr {
    virtual ~expr() = default;
    virtual void accept(expr_visitor *v) = 0;
    virtual ast_type get_type() = 0;
  };
  // ------- statement base class ------
  struct stmt {
    virtual ~stmt() = default;
    virtual void accept(stmt_visitor *v) = 0;
    virtual ast_type get_type() = 0;
  };
  // ------- expressions ------
  struct assign_expr : expr {
    assign_expr(token *name, token *opr, expr *right);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    token *name_;
    token *opr_;
    expr *right_;
  };
  struct assign_arr_expr : expr {
    assign_arr_expr(expr *assign_oper, token *opr, expr *right);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *assign_oper_;
    token *opr_;
    expr *right_;
  };
  struct assign_member_expr : expr {
    assign_member_expr(expr *set_oper, token *opr, expr *right);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *set_oper_;
    token *opr_;
    expr *right_;
  };
  struct binary_expr : expr {
    binary_expr(expr *left, token *opr, expr *right);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *left_;
    token *opr_;
    expr *right_;
  };
  struct fncall_expr : expr {
    fncall_expr(expr *name, token *paren_token, std::vector<expr *> args);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *name_;
    token *paren_token_;
    std::vector<expr *> args_;
  };
  struct get_expr : expr {
    get_expr(expr *lhs, token *dot, token *item);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *lhs_;
    token *dot_;
    token *item_;
  };
  struct grouping_expr : expr {
    explicit grouping_expr(expr *expression);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *expression_;
  };
  struct literal_expr : expr {
    explicit literal_expr(token *literal_token);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    token *literal_token_;
  };
  struct logical_expr : expr {
    logical_expr(expr *left, token *opr, expr *right);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *left_;
    token *opr_;
    expr *right_;
  };
  struct set_expr : expr {
    set_expr(expr *lhs, token *dot, token *item);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *lhs_;
    token *dot_;
    token *item_;
  };
  struct square_bracket_access_expr : expr {
    square_bracket_access_expr(expr *name, token *sqb_token, expr *index_expr);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *name_;
    token *sqb_token_;
    expr *index_expr_;
  };
  struct square_bracket_set_expr : expr {
    square_bracket_set_expr(expr *name, token *sqb_token, expr *index_expr);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    expr *name_;
    token *sqb_token_;
    expr *index_expr_;
  };
  struct unary_expr : expr {
    unary_expr(token *opr, expr *right);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    token *opr_;
    expr *right_;
  };
  struct variable_expr : expr {
    explicit variable_expr(token *name);
    void accept(expr_visitor *v) override;
    ast_type get_type() override;
    token *name_;
  };
  // ------- statements ------
  struct block_stmt : stmt {
    explicit block_stmt(std::vector<stmt *> statements);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    std::vector<stmt *> statements_;
  };
  struct break_stmt : stmt {
    explicit break_stmt(token *break_token);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *break_token_;
  };
  struct ccode_stmt : stmt {
    ccode_stmt(token *ccode_keyword, token *code_str);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *ccode_keyword_;
    token *code_str_;
  };
  struct class_stmt : stmt {
    class_stmt(token *name, std::vector<parameter> members,
               annotations annotations);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *name_;
    std::vector<parameter> members_;
    annotations annotations_;
  };
  struct const_stmt : stmt {
    const_stmt(token *name, ykdatatype *data_type, expr *expression);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *name_;
    ykdatatype *data_type_;
    expr *expression_;
  };
  struct continue_stmt : stmt {
    explicit continue_stmt(token *continue_token);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *continue_token_;
  };
  struct def_stmt : stmt {
    def_stmt(token *name, std::vector<parameter> params, stmt *function_body,
             ykdatatype *return_type, annotations annotations);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *name_;
    std::vector<parameter> params_;
    stmt *function_body_;
    ykdatatype *return_type_;
    annotations annotations_;
  };
  struct defer_stmt : stmt {
    defer_stmt(token *defer_keyword, expr *expression, stmt *del_statement);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *defer_keyword_;
    expr *expression_;
    stmt *del_statement_;
  };
  struct del_stmt : stmt {
    del_stmt(token *del_keyword, expr *expression);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *del_keyword_;
    expr *expression_;
  };
  struct elif_stmt : stmt {
    elif_stmt(token *elif_keyword, expr *expression, stmt *elif_branch);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *elif_keyword_;
    expr *expression_;
    stmt *elif_branch_;
  };
  struct expression_stmt : stmt {
    explicit expression_stmt(expr *expression);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    expr *expression_;
  };
  struct if_stmt : stmt {
    if_stmt(token *if_keyword, expr *expression, stmt *if_branch,
            token *else_keyword, stmt *else_branch);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *if_keyword_;
    expr *expression_;
    stmt *if_branch_;
    token *else_keyword_;
    stmt *else_branch_;
  };
  struct import_stmt : stmt {
    import_stmt(token *import_token, std::vector<token *> import_names,
                token *name, file_info *data);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *import_token_;
    std::vector<token *> import_names_;
    token *name_;
    file_info *data_;
  };
  struct let_stmt : stmt {
    let_stmt(token *name, ykdatatype *data_type, expr *expression);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *name_;
    ykdatatype *data_type_;
    expr *expression_;
  };
  struct pass_stmt : stmt {
    explicit pass_stmt(token *pass_token);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *pass_token_;
  };
  struct return_stmt : stmt {
    return_stmt(token *return_keyword, expr *expression);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *return_keyword_;
    expr *expression_;
  };
  struct while_stmt : stmt {
    while_stmt(token *while_keyword, expr *expression, stmt *while_body);
    void accept(stmt_visitor *v) override;
    ast_type get_type() override;
    token *while_keyword_;
    expr *expression_;
    stmt *while_body_;
  };
  // ------- utils ------
  struct ast_pool {
    ast_pool();
    ~ast_pool();
    expr *c_assign_expr(token *name, token *opr, expr *right);
    expr *c_assign_arr_expr(expr *assign_oper, token *opr, expr *right);
    expr *c_assign_member_expr(expr *set_oper, token *opr, expr *right);
    expr *c_binary_expr(expr *left, token *opr, expr *right);
    expr *c_fncall_expr(expr *name, token *paren_token,
                        std::vector<expr *> args);
    expr *c_get_expr(expr *lhs, token *dot, token *item);
    expr *c_grouping_expr(expr *expression);
    expr *c_literal_expr(token *literal_token);
    expr *c_logical_expr(expr *left, token *opr, expr *right);
    expr *c_set_expr(expr *lhs, token *dot, token *item);
    expr *c_square_bracket_access_expr(expr *name, token *sqb_token,
                                       expr *index_expr);
    expr *c_square_bracket_set_expr(expr *name, token *sqb_token,
                                    expr *index_expr);
    expr *c_unary_expr(token *opr, expr *right);
    expr *c_variable_expr(token *name);
    stmt *c_block_stmt(std::vector<stmt *> statements);
    stmt *c_break_stmt(token *break_token);
    stmt *c_ccode_stmt(token *ccode_keyword, token *code_str);
    stmt *c_class_stmt(token *name, std::vector<parameter> members,
                       annotations annotations);
    stmt *c_const_stmt(token *name, ykdatatype *data_type, expr *expression);
    stmt *c_continue_stmt(token *continue_token);
    stmt *c_def_stmt(token *name, std::vector<parameter> params,
                     stmt *function_body, ykdatatype *return_type,
                     annotations annotations);
    stmt *c_defer_stmt(token *defer_keyword, expr *expression,
                       stmt *del_statement);
    stmt *c_del_stmt(token *del_keyword, expr *expression);
    stmt *c_elif_stmt(token *elif_keyword, expr *expression, stmt *elif_branch);
    stmt *c_expression_stmt(expr *expression);
    stmt *c_if_stmt(token *if_keyword, expr *expression, stmt *if_branch,
                    token *else_keyword, stmt *else_branch);
    stmt *c_import_stmt(token *import_token, std::vector<token *> import_names,
                        token *name, file_info *data);
    stmt *c_let_stmt(token *name, ykdatatype *data_type, expr *expression);
    stmt *c_pass_stmt(token *pass_token);
    stmt *c_return_stmt(token *return_keyword, expr *expression);
    stmt *c_while_stmt(token *while_keyword, expr *expression,
                       stmt *while_body);

private:
    std::vector<expr *> cleanup_expr_;
    std::vector<stmt *> cleanup_stmt_;
  };
  /**
* Parameter for a user defined function declaration
*/
  struct parameter {
    token *name_;
    ykdatatype *data_type_;
  };
}// namespace yaksha
#endif