#include <iostream>

#include "tokenizer.h"
#include "token.h"

int main() {
    try {
        Tokenizer tokenizer;
        vector<Token> tokens = tokenizer.getTokens(
            "var identifier = 1 + 1\nprint identifier"
        );
    }
    catch ( exception e ) {
        cout << e.what() << endl;
    }
    return 0;
}
