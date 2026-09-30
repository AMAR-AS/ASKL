#include "lexer.h"
#include "parser.h"
#include "codegen.h"
#include "vm.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
int main(int argc,char**argv){if(argc!=2){std::cerr<<"Usage: ask <file.as>\n";return 1;}std::ifstream in(argv[1],std::ios::binary);if(!in){std::cerr<<"Ask: cannot open "<<argv[1]<<"\n";return 1;}std::string source((std::istreambuf_iterator<char>(in)),{});try{Lexer lexer;auto tokens=lexer.tokenize(source);Parser parser;auto ast=parser.parse(tokens);CodeGenerator gen;auto code=gen.generate(*ast);VM vm;vm.load(std::move(code));return vm.run();}catch(const std::exception&e){std::cerr<<"Ask compile error: "<<e.what()<<"\n";return 2;}}