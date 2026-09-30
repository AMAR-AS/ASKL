#pragma once
#include <memory>
#include <string>
#include <vector>
struct ASTNode{std::string nodeType,value;std::vector<std::unique_ptr<ASTNode>> children;ASTNode(std::string t,std::string v={}):nodeType(std::move(t)),value(std::move(v)){} };