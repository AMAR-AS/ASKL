#pragma once
#include "codegen.h"
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
using Value=std::variant<std::monostate,long long,double,bool,std::string>;
class VM{public:void load(std::vector<Instruction>);int run();private:std::vector<Instruction>program;std::vector<Value>stack;std::unordered_map<std::string,Value>variables;static bool truthy(const Value&);static std::string display(const Value&);Value pop();};