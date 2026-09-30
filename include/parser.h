#pragma once
#include "ast.h"
#include "lexer.h"
#include <memory>
#include <vector>
class Parser{public:std::unique_ptr<ASTNode> parse(const std::vector<Token>&);private:const std::vector<Token>*tokens=nullptr;std::size_t current=0;const Token&peek()const;const Token&previous()const;bool check(const std::string&)const;bool match(const std::string&);const Token&consume(const std::string&,const char*);std::unique_ptr<ASTNode>statement();std::unique_ptr<ASTNode>block();std::unique_ptr<ASTNode>expression();std::unique_ptr<ASTNode>assignment();std::unique_ptr<ASTNode>equality();std::unique_ptr<ASTNode>comparison();std::unique_ptr<ASTNode>term();std::unique_ptr<ASTNode>factor();std::unique_ptr<ASTNode>unary();std::unique_ptr<ASTNode>primary();};