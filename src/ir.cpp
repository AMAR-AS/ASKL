#include "ir.h"
#include <iostream>
void IRGenerator::generate(ASTNode* root){(void)root;instructions.clear();}
void IRGenerator::printIR(){for(const auto&i:instructions)std::cout<<i.op<<" "<<i.arg1<<" "<<i.arg2<<" -> "<<i.result<<"\n";}
std::vector<IRInstruction>IRGenerator::getIR(){return instructions;}