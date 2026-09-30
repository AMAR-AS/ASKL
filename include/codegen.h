#pragma once
#include "ast.h"
#include <string>
#include <vector>
struct Instruction{std::string op,arg;};
class CodeGenerator{public:std::vector<Instruction> generate(const ASTNode&);private:std::vector<Instruction>code;void emitExpression(const ASTNode&);};