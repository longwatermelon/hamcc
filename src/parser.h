#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "node.h"
#include "args.h"

#include <stdlib.h>
#include <stdbool.h>

struct Parser
{
    struct Token **tokens;
    size_t ntokens;

    struct Token *curr_tok;
    size_t curr_idx;

    struct Scope *scope;

    size_t stack_size;
    size_t lc;

    struct Args *args;

    bool ignore_ops;
};

struct Parser *parser_alloc(struct Token **tokens, size_t ntokens, struct Args *args);
void parser_free(struct Parser *parser);

void parser_eat(struct Parser *parser, int type);
void parser_advance(struct Parser *parser, int i);
struct Token *parser_next_expr(struct Parser *parser);

struct Node *parser_parse(struct Parser *parser);
struct Node *parser_parse_expr(struct Parser *parser);

struct Node *parser_parse_int(struct Parser *parser);
struct Node *parser_parse_str(struct Parser *parser);
struct Node *parser_parse_id(struct Parser *parser);

struct Node *parser_parse_function_def(struct Parser *parser);
struct Node **parser_parse_function_def_params(struct Parser *parser, size_t *nparams);
struct Node *parser_parse_return(struct Parser *parser);

struct Node *parser_parse_variable_def(struct Parser *parser);
struct Node *parser_parse_variable(struct Parser *parser);

struct Node *parser_parse_function_call(struct Parser *parser);

struct Node *parser_parse_assignment(struct Parser *parser);

struct Node *parser_parse_struct(struct Parser *parser);

struct Node *parser_parse_init_list(struct Parser *parser);

struct Node *parser_parse_include(struct Parser *parser);

struct Node *parser_parse_binop(struct Parser *parser);

struct Node *parser_parse_idof(struct Parser *parser);

struct Node *parser_parse_inline_asm(struct Parser *parser);

NodeDType parser_parse_dtype(struct Parser *parser);

char *parser_next_lc(struct Parser *parser);

#endif

