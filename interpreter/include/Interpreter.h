#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream> // std::cout
// #include <fstream>  // std::ifstream
// #include <sstream>

#include <iterator>     // std::istream_iterator

#include "Preprocessor.h"

// Tokenizer
#include "Tokenizer.h"
#include "Token.h"

#include "Statement.h"

using namespace std;

/**
 * Classe Interpreter
 */
class Interpreter
{
public:

    static int Main(const int argc, const char* argv[]);

private:

    static int ParseFile(string filename);
    static int ParseString(string filename);
    static int ParseStringContinue();
};

#endif
