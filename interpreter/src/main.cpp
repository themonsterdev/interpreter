#include "Interpreter.h"

static int QUOTE_CHARACTER          = '\'';
static int DOUBLE_QUOTE_CHARACTER   = '"';

int main(const int argc, const char* argv[])
{
    try
    {
        return Interpreter::Main(argc, argv);
    }
    catch (exception e)
    {
        cout << "\x1B[91mErreur: " << e.what() << "\033[0m" << endl;
    }

    return EXIT_FAILURE;
}
