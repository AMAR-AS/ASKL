#pragma once
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
struct Token{std::string type,value;std::size_t line=1,column=1;};
class Lexer{public:explicit Lexer(std::string language_dir="languages");std::vector<Token> tokenize(const std::string& source);private:std::unordered_map<std::string,std::string> keywords;void loadLanguagePacks(const std::string&);static bool isIdentifierStart(unsigned char);static bool isIdentifierContinue(unsigned char);};