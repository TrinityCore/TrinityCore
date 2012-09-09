/**
 @file TextInput.cpp
  
 @author Morgan McGuire, graphics3d.com
 
 @cite Based on a lexer written by Aaron Orenstein. 
 
 @created 2001-11-27
 @edited  2010-07-03
 */

#include "G3D/fileutils.h"
#include "G3D/TextInput.h"
#include "G3D/BinaryInput.h"
#include "G3D/stringutils.h"

#ifdef _MSC_VER
#   pragma warning (push)
// conversion from 'int' to 'char', possible loss of data (TODO: fix underlying problems)
#   pragma warning (disable: 4244)
#endif

namespace G3D {

Token TextInput::readSignificant() {
    Token t;
    do { 
        t = read();
    } while ((t.type() == Token::COMMENT) || (t.type() == Token::NEWLINE));
    return t;
}


double Token::number() const {
    if (_type == NUMBER) {
        return TextInput::parseNumber(_string);
    } else {
        return 0.0;
    }
}


bool TextInput::parseBoolean(const std::string& _string) {
     return toLower(_string) == "true";
}

double TextInput::parseNumber(const std::string& _string) {
    std::string s = toLower(_string);
    if (s == "-1.#ind00" || s == "nan") {
        return nan();
    }
    
    if (s == "1.#inf00" || s == "inf" || s == "+inf") {
        return inf();
    }
    
    if (s == "-1.#inf00" || s == "-inf") {
        return -inf();
    }
    
    double n;
    if ((_string.length() > 2) &&
        (_string[0] == '0') &&
        (_string[1] == 'x')) {
        // Hex
        uint32 i;
        sscanf(_string.c_str(), "%x", &i);
        n = i;
    } else {
        sscanf(_string.c_str(), "%lg", &n);
    }

    return n;
}

TextInput::Settings::Settings () :
    cppBlockComments(true),
    cppLineComments(true),
    otherLineComments(true),
    escapeSequencesInStrings(true), 
    otherCommentCharacter('\0'),
    otherCommentCharacter2('\0'),
    generateCommentTokens(false),
    generateNewlineTokens(false),
    signedNumbers(true),
    singleQuotedStrings(true),
    singleQuoteCharacter('\''),
    sourceFileName(),
    startingLineNumberOffset(0),
    msvcFloatSpecials(true),
    simpleFloatSpecials(true),
    proofSymbols(false),
    caseSensitive(true)
{ 
    trueSymbols.insert("true");
    falseSymbols.insert("false");
}


Token TextInput::peek() {
    if (stack.size() == 0) {
        Token t = nextToken();
        push(t);
    }

    return stack.front();
}


int TextInput::peekLineNumber() {
    return peek().line();
}


int TextInput::peekCharacterNumber() {
    return peek().character();
}


Token TextInput::read() {
    if (stack.size() > 0) {
        Token t = stack.front();
        stack.pop_front();
        return t;
    } else {
        return nextToken();
    }
}



std::string TextInput::readUntilNewlineAsString() {
/*
    // Reset the read position back to the start of that token
    currentCharOffset = t.bytePosition();
    lineNumber = t.line();
    charNumber = t.character();
    stack.clear();

    if (currentCharOffset == buffer.size()) {
        // End of file
        return "";
    }
    */
    std::string s;

    // Read until newline or eof
    char c = '\0';
    do {
        c = buffer[currentCharOffset];
        if (c == '\r' || c == '\n') {
            // Done
            break;
        } else {
            s += c;
            ++currentCharOffset;
            ++charNumber;
        }
    } while (currentCharOffset < buffer.size());

    return s;    
}


static void toUpper(Set<std::string>& set) {
    Array<std::string> symbols;
    set.getMembers(symbols);
    set.clear();
    for (int i = 0; i < symbols.size(); ++i) {
        set.insert(toUpper(symbols[i]));
    }
}

void TextInput::init() {
    currentCharOffset = 0;
    charNumber = 1;
    lineNumber = 1 + options.startingLineNumberOffset;

    if (! options.caseSensitive) {
        // Convert true and false symbols to all uppercase for fast comparisons
        toUpper(options.trueSymbols);
        toUpper(options.falseSymbols);
    }
}


void TextInput::push(const Token& t) {
    stack.push_front(t);
}


bool TextInput::hasMore() {
    return (peek()._type != Token::END);
}


int TextInput::eatInputChar() {
    // Don't go off the end
    if (currentCharOffset >= buffer.length()) {
        return EOF;
    }

    unsigned char c = buffer[currentCharOffset];
    ++currentCharOffset;

    // update lineNumber and charNumber to reflect the location of the *next*
    // character which will be read.

    // increment line number for \r, \n and \r\n which matches Token::NEWLINE parsing
    if (c == '\r') {
        ++lineNumber;
        charNumber = 1;

        // check for \r\n
        if (currentCharOffset < buffer.length()) {
            unsigned char c2 = buffer[currentCharOffset];
            if (c2 == '\n') {
                c = c2;
                ++currentCharOffset;
            }
        }
    } else if (c == '\n') {
        ++lineNumber;
        charNumber = 1;
    } else {
        ++charNumber;
    }

    return c;
}

int TextInput::peekInputChar(int distance) {
    // Don't go off the end
    if ((currentCharOffset + distance) >= buffer.length()) {
        return EOF;
    }

    unsigned char c = buffer[currentCharOffset + distance];
    return c;
}


Token TextInput::nextToken() {
    Token t;

    t._bytePosition = currentCharOffset;
    t._line         = lineNumber;
    t._character    = charNumber;
    t._type         = Token::END;
    t._extendedType = Token::END_TYPE;

    int c = peekInputChar();
    if (c == EOF) {
        return t;
    }

    // loop through white space, newlines and comments
    // found before other tokens
    bool whitespaceDone = false;
    while (! whitespaceDone) {
        whitespaceDone = true;

        // generate newlines tokens for '\n' and '\r' and '\r\n'
        while (isWhiteSpace(c)) {
            if (options.generateNewlineTokens && isNewline(c)) {
                t._type         = Token::NEWLINE;
                t._extendedType = Token::NEWLINE_TYPE;
                t._bytePosition = currentCharOffset;
                t._line         = lineNumber;
                t._character    = charNumber;
                t._string       = c;

                int c2 = peekInputChar(1);
                if (c == '\r' && c2 == '\n') {
                    t._string  += c2;
                }

                eatInputChar();
                return t;
            } else {
                // Consume the single whitespace
                c = eatAndPeekInputChar();
            }
        }

        // update line and character number to include discarded whitespace
        t._line         = lineNumber;
        t._character    = charNumber;
        t._bytePosition = currentCharOffset;

        int c2 = peekInputChar(1);

        // parse comments and generate tokens if enabled
        std::string commentString;

        // check for line comments first
        bool isLineComment = false;
        if (options.cppLineComments && (c == '/' && c2 == '/')) {
            // set start of line comment and eat markers
            isLineComment = true;
            eatInputChar();
            eatInputChar();
        } else if ( options.otherCommentCharacter && 
                   (options.otherCommentCharacter != '\0' && c == options.otherCommentCharacter) ) {
            // set start of line comment and eat markers
            isLineComment = true;
            eatInputChar();
        } else if ( options.otherCommentCharacter && 
                   (options.otherCommentCharacter2 != '\0' && c == options.otherCommentCharacter2) ) {
            // set start of line comment and eat markers
            isLineComment = true;
            eatInputChar();
        }

        if (isLineComment) {

            // consume line comment to newline or EOF
            c = peekInputChar();
            while (! isNewline(c) && c != EOF) {
                // build comment string for token
                commentString += c;

                c = eatAndPeekInputChar();
            }

            if (options.generateCommentTokens) {
                t._type         = Token::COMMENT;
                t._extendedType = Token::LINE_COMMENT_TYPE;
                t._string       = commentString;
                return t;
            } else {
                // There is whitespace after the comment (in particular, the
                // newline that terminates the comment).  There might also be
                // whitespace at the start of the next line.
                whitespaceDone = false;
            }

        } else if (options.cppBlockComments && (c == '/' && c2 == '*')) {
            // consume block comment to end-marker or EOF

            // consume both start-comment chars, can't let the trailing one
            // help close the comment.
            eatInputChar();
            eatInputChar();

            // c is the next character we'll read, c2 is the one after *that*
            c = peekInputChar();
            c2 = peekInputChar(1);
            while (! ((c == '*') && (c2 == '/')) && (c != EOF)) {
                commentString += c;

                // Eat input char may consume more than one character if there is a newline
                eatInputChar();

                c = peekInputChar();
                c2 = peekInputChar(1);
            }
            eatInputChar();      // eat closing '*'
            eatInputChar();      // eat closing '/'

            c = peekInputChar();

            if (options.generateCommentTokens) {
                t._type         = Token::COMMENT;
                t._extendedType = Token::BLOCK_COMMENT_TYPE;
                t._string       = commentString;
                return t;
            } else {
                // There is whitespace after the comment (in particular, the
                // newline that terminates the comment).  There might also be
                // whitespace at the start of the next line.
                whitespaceDone = false;
            }
        }

    }  // while (! whitespaceDone)

    t._line      = lineNumber;
    t._character = charNumber;
    t._bytePosition = currentCharOffset;

    // handle EOF
    if (c == EOF) {
        return t;
    }

    // Extended ASCII parses as itself, except for EOF
    if (c > 127 && c < 255) {
        t._type = Token::SYMBOL;                                                
        t._extendedType = Token::SYMBOL_TYPE;                                   
        t._string = c;                                                          
        c = eatAndPeekInputChar();                                              
    }


    // Perform appropriate setup for a symbol (including setting up the token
    // string to start with c), eat the input character, and overwrite
    // 'c' with the peeked next input character.
#define SETUP_SYMBOL(c)                                                         \
    {                                                                           \
        t._type = Token::SYMBOL;                                                \
        t._extendedType = Token::SYMBOL_TYPE;                                   \
        t._string = c;                                                          \
        c = eatAndPeekInputChar();                                              \
    }

    switch (c) {

    case '@':                   // Simple symbols -> just themselves.
    case '(': 
    case ')':
    case ',':
    case ';':
    case '{':
    case '}':
    case '[':
    case ']':
    case '#':
    case '$':
    case '?':
    case '%':
        SETUP_SYMBOL(c);
        return t;

    case '-':                   // negative number, -, --, -=, or ->
        SETUP_SYMBOL(c);

        switch (c) {
        case '>':               // ->
        case '-':               // --
        case '=':               // -=
            t._string += c;
            eatInputChar();
            return t;
        }

        if (options.signedNumbers) {
            if (isDigit(c) || (c == '.' && isDigit(peekInputChar(1)))) {
                // Negative number.  'c' is still the first digit, and is
                // the next input char.

                goto numLabel;
            } else {
                char terminal = peekInputChar(3);
                if (options.simpleFloatSpecials && (c == 'i') && (peekInputChar(1) == 'n') && (peekInputChar(2) == 'f') && 
                    ! isLetter(terminal) && (terminal != '_')) {
                    // negative infinity
                    t._type = Token::NUMBER;
                    t._extendedType = Token::FLOATING_POINT_TYPE;
                    t._string = "-inf";
                    eatInputChar(); // i
                    eatInputChar(); // n
                    eatInputChar(); // f
                    return t;
                }
            }
        }


        // plain -
        return t;

    case '+':                   // positive number, +, ++, or +=
        SETUP_SYMBOL(c);

        switch (c) {
        case '+':               // ++
        case '=':               // +=
            t._string += c;
            eatInputChar();
            return t;
        }

        if (options.signedNumbers) {
            if (isDigit(c) || (c == '.' && isDigit(peekInputChar(1)))) {
                // Positive number.  'c' is still the first digit, and is
                // the next input char.

                goto numLabel;
            } else {
                char terminal = peekInputChar(3);
                if (options.simpleFloatSpecials && (c == 'i') && (peekInputChar(1) == 'n') && (peekInputChar(2) == 'f') && 
                    ! isLetter(terminal) && (terminal != '_')) {
                    // positive infinity
                    t._type = Token::NUMBER;
                    t._extendedType = Token::FLOATING_POINT_TYPE;
                    t._string = "+inf";
                    eatInputChar(); // i
                    eatInputChar(); // n
                    eatInputChar(); // f
                    return t;
                }
            }
        }

        return t;

    case ':':                   // : or :: or ::> or ::= or := or :>
        SETUP_SYMBOL(c);
        
        if (c == ':') {
            t._string += c;
            eatInputChar();

            if (options.proofSymbols) {
                c = peekInputChar(0);
                
                if ((c == '>') || (c == '=')) {
                    t._string += c;
                    eatInputChar();
                }
            }
        }
        else if (options.proofSymbols && (c == '=' || c == '>')) {
            t._string += c;
            eatInputChar();
        }
        return t;

    case '=':                   // = or == or =>
        SETUP_SYMBOL(c);

        if (c == '=') {
            t._string += c;
            eatInputChar();
            return t;
        } else if (options.proofSymbols && (c == '>')) {
            t._string += c;
            eatInputChar();
            return t;
        }
        return t;

    case '*':                   // * or *=
    case '/':                   // / or /=
    case '!':                   // ! or !=
    case '~':                   // ~ or ~=
    case '^':                   // ^ or ^=
        SETUP_SYMBOL(c);
        
        if (c == '=') {
            t._string += c;
            eatInputChar();
            return t;
        }
        return t;

    case '>':                   // >, >>,or >=
    case '<':                   // <<, <<, or <= or <- or <:
    case '|':                   // ||, ||, or |= or |-
    case '&':                   // &, &&, or &=
        {
            int orig_c = c;
            SETUP_SYMBOL(c);

            if ((c == '=') || (orig_c == c)) {
                t._string += c;
                eatInputChar();
                return t;
            } else if (options.proofSymbols) {
                if ((orig_c == '<') && (c == '-')) {
                    t._string += c;
                    eatInputChar();
                } else if ((orig_c == '|') && (c == '-')) {
                    t._string += c;
                    eatInputChar();
                } else if ((orig_c == '<') && (c == ':')) {
                    t._string += c;

                    c = eatAndPeekInputChar();

                    if (c == ':') {
                        t._string += c;
                        eatInputChar();
                    }
                }
            }
        }
        return t;
            
    case '\\':                // backslash or escaped comment char.
        SETUP_SYMBOL(c);

        if ((options.otherCommentCharacter != '\0'
             && c == options.otherCommentCharacter)
            || (options.otherCommentCharacter2 != '\0'
                && c == options.otherCommentCharacter2)) {
            
            // escaped comment character.  Return the raw comment
            // char (no backslash).

            t._string = c;
            eatInputChar();
            return t;
        }
        return t;

    case '.':                   // number, ., .., or ...
        if (isDigit(peekInputChar(1))) {
            // We're parsing a float that began without a leading zero
            goto numLabel;
        }

        SETUP_SYMBOL(c);

        if (c == '.') {         // .. or ...
            t._string += c;
            c = eatAndPeekInputChar();

            if (c == '.') {     // ...
                t._string += c;
                eatInputChar();
            }
            return t;
        }

        return t;

    } // switch (c)

#undef SETUP_SYMBOL

numLabel:
    if (isDigit(c) || (c == '.')) {

        // A number.  Note-- single dots have been
        // parsed already, so a . indicates a number
        // less than 1 in floating point form.
    
        // [0-9]*(\.[0-9][f]) or [0-9]+ or 0x[0-9,A-F]+

        if (t._string != "-") {
            // If we picked up a leading "-" sign above, keep it,
            // otherwise drop the string parsed thus far
            t._string = "";
        }
        t._type = Token::NUMBER;
        if (c == '.') {
            t._extendedType = Token::FLOATING_POINT_TYPE;
        } else {
            t._extendedType = Token::INTEGER_TYPE;
        }
        
        if ((c == '0') && (peekInputChar(1) == 'x')) {
            // Hex number
            t._string += "0x";

            // skip the 0x
            eatInputChar();
            eatInputChar();

            c = peekInputChar();
            while (isDigit(c) || ((c >= 'A') && (c <= 'F')) || ((c >= 'a') && (c <= 'f'))) {
                t._string += c;
                c = eatAndPeekInputChar();
            }

        } else {
			// Non-hex number

            // Read the part before the decimal.
            while (isDigit(c)) {
                t._string += c;
                c = eatAndPeekInputChar();
            }
    
            // True if we are reading a floating-point special type
            bool isSpecial = false;

            // Read the decimal, if one exists
            if (c == '.') {
                t._extendedType = Token::FLOATING_POINT_TYPE;

                // The '.' character was a decimal point, not the start of a
                // method or range operator
                t._string += c;
                c = eatAndPeekInputChar();

                // Floating point specials (msvc format only)
                if (options.msvcFloatSpecials && (c == '#')) {
                    isSpecial = true;
                    // We are reading a floating point special value
                    // of the form -1.#IND00, -1.#INF00, or 1.#INF00
                    c = eatAndPeekInputChar();
                    char test = c;
                    if (! options.caseSensitive) {
                        test = toupper(c);
                    }
                    if (test != 'I') {
                        throw BadMSVCSpecial
                            ("Incorrect floating-point special (inf or nan) "
                             "format.",
                            t.line(), charNumber);
                    }
                    c = eatAndPeekInputChar();
                    test = c;
                    if (! options.caseSensitive) {
                        test = toupper(c);
                    }
                    if (test != 'N') {
                        throw BadMSVCSpecial
                            (
                             "Incorrect floating-point special (inf or nan) "
                             "format.",
                            t.line(), charNumber);
                    }
                    t._string += "#IN";
                    c = eatAndPeekInputChar();
                    test = c;
                    if (! options.caseSensitive) {
                        test = toupper(c);
                    }
                    if ((test != 'F') && (test != 'D')) {
                        throw BadMSVCSpecial
                            (
                             "Incorrect floating-point special (inf or nan) "
                             "format.",
                            t.line(), charNumber);
                    }
                    t._string += c;
                    for (int j = 0; j < 2; ++j) {
                        c = eatAndPeekInputChar();
                        if (c != '0') {
                            throw BadMSVCSpecial
                                (
                                 "Incorrect floating-point special (inf or"
                                 "nan) format.",
                                 t.line(), charNumber);
                        }
                        t._string += (char)c;
                    }

                } else {

                    // Read the part after the decimal
                    while (isDigit((char)c)) {
                        t._string += (char)c;
                        c = eatAndPeekInputChar();
                    }
                }
            }

            if (! isSpecial && ((c == 'e') || (c == 'E'))) {
                // Read exponent
                t._extendedType = Token::FLOATING_POINT_TYPE;
                t._string += c;

                c = eatAndPeekInputChar();
                if ((c == '-') || (c == '+')) {
                    t._string += c;
                    c = eatAndPeekInputChar();                    
                }

                while (isDigit(c)) {
                    t._string += c;
                    c = eatAndPeekInputChar();
                }
            }

            if (! isSpecial && (t._extendedType == Token::FLOATING_POINT_TYPE) && (c == 'f')) {
                // Trailing f on a float
                t._string += c;
                c = eatAndPeekInputChar();
            }
        }
        return t;

    } else if (isLetter(c) || (c == '_')) {
        // Identifier or keyword
        // [A-Za-z_][A-Za-z_0-9]*

        t._type = Token::SYMBOL;
        t._extendedType = Token::SYMBOL_TYPE;
        t._string = "";
        do {
            t._string += c;
            c = eatAndPeekInputChar();
        } while (isLetter(c) || isDigit(c) || (c == '_'));

        // See if this symbol is actually a boolean
        if ((options.trueSymbols.size() > 0) || (options.falseSymbols.size() > 0)) {
            std::string str = t._string;
            if (! options.caseSensitive) {
                str = toUpper(str);
            }
            if (options.trueSymbols.contains(str)) {
               t._type = Token::BOOLEAN;
               t._extendedType = Token::BOOLEAN_TYPE;
               t._bool = true;
            } else if (options.falseSymbols.contains(str)) {
               t._type = Token::BOOLEAN;
               t._extendedType = Token::BOOLEAN_TYPE;
               t._bool = false;
            }
        }

        if (options.simpleFloatSpecials && ((t._string == "nan") || (t._string == "inf"))) {
            t._type = Token::NUMBER;
            t._extendedType = Token::FLOATING_POINT_TYPE;
        }
        return t;

    } else if (c == '\"') {

        // Discard the double-quote.
        eatInputChar();

        // Double quoted string
        parseQuotedString('\"', t);
        return t;

    } else if (c == options.singleQuoteCharacter) {

        // Discard the single-quote.
        eatInputChar();

        if (options.singleQuotedStrings) {
            // Single quoted string
            parseQuotedString(options.singleQuoteCharacter, t);
        } else {
            t._string = c;
            t._type = Token::SYMBOL;
            t._extendedType = Token::SYMBOL_TYPE;
        }
        return t;

    } // end of special case tokens

    if (c == EOF) {
        t._type = Token::END;
        t._extendedType = Token::END_TYPE;
        t._string = "";
        return t;
    }

    // Some unknown token
    debugAssertM(false, 
                 format("Unrecognized token type beginning with character '%c' (ASCII %d)", 
                        c, c));
    return t;
}


void TextInput::parseQuotedString(unsigned char delimiter, Token& t) {

    t._type = Token::STRING;

    if (delimiter == options.singleQuoteCharacter) {
        t._extendedType = Token::SINGLE_QUOTED_TYPE;
    } else {
        t._extendedType = Token::DOUBLE_QUOTED_TYPE;
    }

    while (true) {
        // We're definitely going to consume the next input char, so we get
        // it right now.  This makes the condition handling below a bit easier.
        int c = eatInputChar();

        if (c == EOF) {
            // END inside a quoted string.  (We finish the string.)
            break;
        }

        if (options.escapeSequencesInStrings && (c == '\\')) {
            // An escaped character.  We're definitely going to consume it,
            // so we get it (and consume it) now.

            c = eatInputChar();

            switch (c) {
            case 'r':
                t._string += '\r';
                break;
            case 'n':
                t._string += '\n';
                break;
            case 't':
                t._string += '\t';
                break;
            case '0':
                t._string += '\0';
                break;

            case '\\':
            case '\"':
                t._string += (char)c;
                break;

            default:
                if (c ==  options.singleQuoteCharacter) {
                    t._string += (char)c;
                    break;
                }

                if (((c == options.otherCommentCharacter) && 
                     (options.otherCommentCharacter != '\0')) ||
                    ((c == options.otherCommentCharacter2) && 
                     (options.otherCommentCharacter2 != '\0'))) {
                    t._string += c;
                } 
                // otherwise, some illegal escape sequence; skip it.
                break;

            } // switch

        } else if (c == delimiter) {
            // End of the string.  Already consumed the character.
            break;
        } else {
            // All other chars, go on to the string.  Already consumed the
            // character.
            t._string += (char)c;
        }

    }
}

bool TextInput::readBoolean() {
    Token t(read());

    if (t._type == Token::BOOLEAN) {
        return t.boolean();
    }

    // Push initial token back, and throw an error.  We intentionally
    // indicate that the wrong type is the type of the initial token.
    // Logically, the number started there.
    push(t);
    throw WrongTokenType(options.sourceFileName, t.line(), t.character(),
                         Token::BOOLEAN, t._type); 
}

double TextInput::readNumber() {
    Token t(read());

    if (t._type == Token::NUMBER) {
        return t.number();
    }

    // Even if signedNumbers is disabled, readNumber attempts to
    // read a signed number, so we handle that case here.
    if (! options.signedNumbers
        && (t._type == Token::SYMBOL)
        && ((t._string == "-") 
             || (t._string == "+"))) {

        Token t2(read());

        if ((t2._type == Token::NUMBER)
            && (t2._character == t._character + 1)) {

            if (t._string == "-") {
                return -t2.number();
            } else {
                return t2.number();
            }
        }

        // push back the second token.
        push(t2);
    }

    // Push initial token back, and throw an error.  We intentionally
    // indicate that the wrong type is the type of the initial token.
    // Logically, the number started there.
    push(t);
    throw WrongTokenType(options.sourceFileName, t.line(), t.character(),
                         Token::NUMBER, t._type); 
}


Token TextInput::readStringToken() {
    Token t(read());

    if (t._type == Token::STRING) {               // fast path
        return t;
    }

    push(t);
    throw WrongTokenType(options.sourceFileName, t.line(), t.character(),
                         Token::STRING, t._type);
}

std::string TextInput::readString() {
    return readStringToken()._string;
}

void TextInput::readString(const std::string& s) {
    Token t(readStringToken());

    if (t._string == s) {                         // fast path
        return;
    }

    push(t);
    throw WrongString(options.sourceFileName, t.line(), t.character(),
                      s, t._string);
}

Token TextInput::readCommentToken() {
    Token t(read());

    if (t._type == Token::COMMENT) {               // fast path
        return t;
    }

    push(t);
    throw WrongTokenType(options.sourceFileName, t.line(), t.character(),
                         Token::COMMENT, t._type);
}

std::string TextInput::readComment() {
    return readCommentToken()._string;
}

void TextInput::readComment(const std::string& s) {
    Token t(readCommentToken());

    if (t._string == s) {                         // fast path
        return;
    }

    push(t);
    throw WrongString(options.sourceFileName, t.line(), t.character(),
                      s, t._string);
}

Token TextInput::readNewlineToken() {
    Token t(read());

    if (t._type == Token::NEWLINE) {               // fast path
        return t;
    }

    push(t);
    throw WrongTokenType(options.sourceFileName, t.line(), t.character(),
                         Token::NEWLINE, t._type);
}

std::string TextInput::readNewline() {
    return readNewlineToken()._string;
}

void TextInput::readNewline(const std::string& s) {
    Token t(readNewlineToken());

    if (t._string == s) {                         // fast path
        return;
    }

    push(t);
    throw WrongString(options.sourceFileName, t.line(), t.character(),
                      s, t._string);
}

Token TextInput::readSymbolToken() {
    Token t(read());
    
    if (t._type == Token::SYMBOL) {               // fast path
        return t;
    }

    push(t);
    throw WrongTokenType(options.sourceFileName, t.line(), t.character(),
                         Token::SYMBOL, t._type);
}


std::string TextInput::readSymbol() {
    return readSymbolToken()._string;
}

void TextInput::readSymbol(const std::string& symbol) {
    Token t(readSymbolToken());

    if (t._string == symbol) {                    // fast path
        return;
    }

    push(t);
    throw WrongSymbol(options.sourceFileName, t.line(), t.character(),
                      symbol, t._string);
}


TextInput::TextInput(const std::string& filename, const Settings& opt) : options(opt) {
    init();
    std::string input = readWholeFile(filename);

    if (options.sourceFileName.empty()) {
        options.sourceFileName = filename;
    }
    int n = input.size();
    buffer.resize(n);
    System::memcpy(buffer.getCArray(), input.c_str(), n);
}


TextInput::TextInput(FS fs, const std::string& str, const Settings& opt) : options(opt) {
    (void)fs;
    init();
    if (options.sourceFileName.empty()) {
        if (str.length() < 14) {
            options.sourceFileName = std::string("\"") + str + "\"";
        } else {
            options.sourceFileName = std::string("\"") + str.substr(0, 10) + "...\"";
        }
    }
    buffer.resize(str.length()); // we don't bother copying trailing NUL.
    System::memcpy(buffer.getCArray(), str.c_str(), buffer.size());
}


const std::string& TextInput::filename() const {
    return options.sourceFileName;
}

///////////////////////////////////////////////////////////////////////////////////

TextInput::TokenException::TokenException(
    const std::string&  src,
    int                 ln,
    int                 ch) : ParseError(src, ln, ch, format("%s(%d) : ", src.c_str(), ln)),
                              sourceFile(src) {
}

///////////////////////////////////////////////////////////////////////////////////

static const char* tokenTypeToString(Token::Type t) {
    switch (t) {
    case Token::SYMBOL:
        return "Token::SYMBOL";
    case Token::STRING:
        return "Token::STRING";
    case Token::NUMBER:
        return "Token::NUMBER";
    case Token::END:
        return "Token::END";
    case Token::NEWLINE:
        return "Token::NEWLINE";
    default:
        debugAssertM(false, "Fell through switch");
        return "?";
    }
}

TextInput::WrongTokenType::WrongTokenType(
    const std::string&  src,
    int                 ln,
    int                 ch,
    Token::Type         e,
    Token::Type         a) :
    TokenException(src, ln, ch), expected(e), actual(a) {
         
    message += format("Expected token of type %s, found type %s.",
                      tokenTypeToString(e), tokenTypeToString(a));
}


TextInput::BadMSVCSpecial::BadMSVCSpecial(
    const std::string&  src,
    int                 ln,
    int                 ch) :
    TokenException(src, ln, ch) {
}


TextInput::WrongSymbol::WrongSymbol(
    const std::string&  src,
    int                 ln,
    int                 ch,
    const std::string&  e,
    const std::string&  a) : 
    TokenException(src, ln, ch), expected(e), actual(a) {

    message += format("Expected symbol '%s', found symbol '%s'.",
                      e.c_str(), a.c_str());
}


TextInput::WrongString::WrongString(
    const std::string&  src,
    int                 ln,
    int                 ch,
    const std::string&  e,
    const std::string&  a) : 
    TokenException(src, ln, ch), expected(e), actual(a) {

    message += format("Expected string '%s', found string '%s'.",
                      e.c_str(), a.c_str());
}


void deserialize(bool& b, TextInput& ti) {
    b = ti.readSymbol() == "true";
}


void deserialize(int& b, TextInput& ti) {
    b = iRound(ti.readNumber());
}


void deserialize(uint8& b, TextInput& ti) {
    b = (uint8)iRound(ti.readNumber());
}


void deserialize(double& b, TextInput& ti) {
    b = ti.readNumber();
}


void deserialize(float& b, TextInput& ti) {
    b = (float)ti.readNumber();
}

} // namespace

#ifdef _MSC_VER
#   pragma warning (pop)
#endif
