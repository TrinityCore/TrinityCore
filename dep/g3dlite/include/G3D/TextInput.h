/**
 @file TextInput.h

 Simple text lexer/tokenizer.

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @cite Based on a lexer written by Aaron Orenstein. 

 @created 2002-11-27
 @edited  2010-07-03

 Copyright 2000-2010, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_TextInput_h
#define G3D_TextInput_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Set.h"
#include "G3D/ParseError.h"
#include <string>
#include <queue>
#include <ctype.h>
#include <stdio.h>

namespace G3D {

/**
 For use with TextInput.
 */
class Token {
public:

    /**
     More detailed type information than Type.
     */
    enum ExtendedType {
      DOUBLE_QUOTED_TYPE, 
      SINGLE_QUOTED_TYPE, 
      SYMBOL_TYPE,
      FLOATING_POINT_TYPE, 
      INTEGER_TYPE,
      BOOLEAN_TYPE,
      LINE_COMMENT_TYPE,
      BLOCK_COMMENT_TYPE,
      NEWLINE_TYPE,
      END_TYPE
    };

    /**
     Strings are enclosed in quotes, symbols are not.
     */
    enum Type {
      STRING  = DOUBLE_QUOTED_TYPE, 
      SYMBOL  = SYMBOL_TYPE, 
      NUMBER  = FLOATING_POINT_TYPE, 
      BOOLEAN = BOOLEAN_TYPE,
      COMMENT = LINE_COMMENT_TYPE,
      NEWLINE = NEWLINE_TYPE,
      END     = END_TYPE
    };

private:

    friend class TextInput;

    /** 
      Holds the actual value, which might be any type.  If a number, it will be 
      parsed at runtime.
    */
    std::string             _string;

    bool                    _bool;
    int                     _line;
    int                     _character;
    uint64                  _bytePosition;
    Type                    _type;
    ExtendedType            _extendedType;

public:

    Token() :
        _string(""),
        _bool(false),
        _line(0), 
        _character(0), 
        _bytePosition(0),
        _type(END), 
        _extendedType(END_TYPE) {}

    Token(Type t, ExtendedType e, const std::string& s, int L, int c, uint64 byte)
        : _string(s), _bool(false), _line(L), _character(c), _bytePosition(byte), _type(t), _extendedType(e) {}

    Token(Type t, ExtendedType e, const std::string& s, bool b, int L, int c, uint64 byte)
        : _string(s), _bool(b), _line(L), _character(c), _bytePosition(byte), _type(t), _extendedType(e) {}

    Type type() const {
        return _type;
    }

    ExtendedType extendedType() const {
        return _extendedType;
    }

    /**
     The value of a single or double quote string (not including the quotes),
     the name of a symbol, or the exact textual representation of a number as
     parsed from the input. 
     */
    const std::string& string() const {
        return _string;
    }

    bool boolean() const {
        return _bool;
    }

    /**
     Starting line of the input from which this token was parsed.  Starts
     at 1.
     */
    int line() const {
        return _line;
    }

    /**
     Starting character position in the input line from which this token was
     parsed.  Starts at 1.
     */
    int character() const {
        return _character;
    }

    /** Number of bytes from the beginning of the buffer that this token was parsed from. 
      Begins at 0 */
    uint64 bytePosition() const {
        return _bytePosition;
    }

    /** Return the numeric value for a number type, or zero if this is
        not a number type.
    */
    double number() const;
};


/**
 A simple style tokenizer for reading text files.  TextInput handles a
 superset of C++,Java, Matlab, and Bash code text including single
 line comments, block comments, quoted strings with escape sequences,
 and operators.  TextInput recognizes several categories of tokens,
 which are separated by white space, quotation marks, or the end of a
 recognized operator:

 <ul>
  <li><CODE>Token::SINGLE_QUOTED_TYPE</CODE> string of characters surrounded by single quotes, e.g., 'x', '\\0', 'foo'.
  <li><CODE>Token::DOUBLE_QUOTED_TYPE</CODE> string of characters surrounded by double quotes, e.g., "x", "abc\txyz", "b o b".
  <li><CODE>Token::SYMBOL_TYPE</CODE> legal C++ operators, keywords, and identifiers.  e.g., >=, Foo, _X, class, {
  <li><CODE>Token::INTEGER_TYPE</CODE> numbers without decimal places or exponential notation. e.g., 10, 0x17F, 32, 0, -155
  <li><CODE>Token::FLOATING_POINT_TYPE</CODE> numbers with decimal places or exponential notation. e.g., 1e3, -1.2, .4, 0.5
  <li><CODE>Token::BOOLEAN_TYPE</CODE> special symbols like "true" and "false"; the exact details can be configured in TextInput::Settings
  <li><CODE>Token::LINE_COMMENT_TYPE</CODE> (disabled by default); generated for line comments as specified by TextInput::Settings
  <li><CODE>Token::BLOCK_COMMENT_TYPE</CODE> (disabled by default); generated for c-style block comments as specified by TextInput::Settings
  <li><CODE>Token::NEWLINE_TYPE</CODE> (disabled by default); generated for any of "\\r", "\\n" or "\\r\\n"
 </ul>

 <P>The special ".." and "..." tokens are always recognized in
 addition to normal C++ operators. Additional tokens can be made
 available by changing the Settings.

 Negative numbers are handled specially because of the ambiguity between unary minus and negative numbers-- 
 see the note on TextInput::read.

  TextInput does not have helper functions for types with non-obvious
  formatting, or helpers that would be redundant.  Use the serialize
  methods instead for parsing specific types like int, Vector3, and
  Color3.

  Inside quoted strings escape sequences are converted.  Thus the
  string token for ["a\\nb"] is 'a', followed by a newline, followed by
  'b'.  Outside of quoted strings, escape sequences are not converted,
  so the token sequence for [a\\nb] is symbol 'a', symbol '\\', symbol
  'nb' (this matches what a C++ parser would do).  The exception is
  that a specified TextInput::Settings::otherCommentCharacter preceeded
  by a backslash is assumed to be an escaped comment character and is
  returned as a symbol token instead of being parsed as a comment
  (this is what a LaTex or VRML parser would do).

  <B>Examples</B>

  <PRE>
  TextInput ti(TextInput::FROM_STRING, "name = \"Max\", height = 6");

  Token t;

  t = ti.read(); 
  debugAssert(t.type == Token::SYMBOL);
  debugAssert(t.sval == "name");

  ti.read();
  debugAssert(t.type == Token::SYMBOL);
  debugAssert(t.sval == "=");

  std::string name = ti.read().sval;
  ti.read();
  </PRE>

  <PRE>
  TextInput ti(TextInput::FROM_STRING, "name = \"Max\", height = 6");
  ti.readSymbols("name", "=");
  std::string name = ti.readString();
  ti.readSymbols(",", "height", "=");
  double height = ti. readNumber();
  </PRE>

 Assumes that the file is not modified once opened.
 */
class TextInput {
public:
    /** Includes MSVC specials parsing */
    static double parseNumber(const std::string& _string);

    /** toLower(_string) == "true" */
    static bool parseBoolean(const std::string& _string);


    /** Tokenizer configuration options.  */
    class Settings {
    public:
        /** If true, C-style slash-star marks a multi-line comment.

            See generateCommentTokens for rules on how this is applied.

            Default is true.
         */
        bool                cppBlockComments;

        /** If true, // begins a single line comment.

            See generateCommentTokens for rules on how this is applied.

            Default is true.
         */
        bool                cppLineComments;

        /** If true, otherCommentCharacter and otherCommentCharacter2
            are used to begin single line comments in the same way
            cppLineComments is.

            See generateCommentTokens for rules on how this is applied.

            Default is true.
         */
        bool                otherLineComments;

        /** If true, \\r, \\n, \\t, \\0, \\\\ and other escape sequences inside
            strings are converted to the equivalent C++ escaped character.
            If false, backslashes are treated literally.  It is convenient to
            set to false if reading Windows paths, for example, like
            c:\\foo\\bar.

            Default is true.
         */
        bool                escapeSequencesInStrings;

        /** If not '\\0', specifies a character that begins single line
            comments ('#' and '%' are popular choices).  This is independent
            of the cppLineComments flag.  If the character appears in text with
            a backslash in front of it, it is considered escaped and is not
            treated as a comment character.

            Default is '\\0'.
         */
        char                otherCommentCharacter;

        /** Another (optional) 1-comment character.  Useful for files that
            support multiple comment syntaxes.  Default is '\\0'.
         */
        char                otherCommentCharacter2;

        /** If true, comments enabled by cppBlockComments, cppLineComments
            and otherLineComments will generate their respective tokens.
            If false, the same settings will enable parsing and ignoring
            comments

            Default is false.
         */
        bool                generateCommentTokens;

        /** If true, newlines will generate  tokens.
            If false, newlines will be discarded as whitespace when parsed
            outside of other tokens.

            Default is false.
         */
        bool                generateNewlineTokens;

        /** If true, "-1" parses as the number -1 instead of the
            symbol "-" followed by the number 1.  Default is true.*/
        bool                signedNumbers;

        /** If true, strings can be marked with single quotes (e.g.,
            'aaa').  If false, the quote character is parsed as a
            symbol. Default is true.  Backquote (`) is always parsed
            as a symbol. */
        bool                singleQuotedStrings;

        /** The character to use as a single quote.  Defaults to "'" (backquote),
            occasionally useful to set to "`" (forward quote) or to "," (comma) for
            reading CSV files. */
        char                singleQuoteCharacter;
        
        /** If set to a non-empty string, that string will be used in
            place of the real file name (or in place of a pseudonym
            constructed from the buffer if given FROM_STRING) in
            tokens and exceptions.
            
            Default is empty.
        */
        std::string         sourceFileName;

    
        /** Added to the line number reported by peekLineNumber and in
            exceptions.  Useful for concatenating files that are
            parsed separately.  Default is zero. */
        int                 startingLineNumberOffset;

        /** 
          Parse -1.#IND00 as the floating point number returned by
          nan(), -1.#INF00 as -G3D::inf(), and 1.#INF00 as G3D::inf().  
          
          Note that the C99 standard specifies that a variety of formats
          like "nan" are to be used; these are supported by 
          G3D::TextInput::Settings::simpleFloatSpecials.

          An alternative to specifying msvcFloatSpecials is to read numbers as:
          <pre>
            Token x = t.read();
            Token y = t.peek();
            if ((x.string() == "-1.") && 
                (y.string() == "#INF00") && 
                (y.character() == x.character() + 3) &&
                (y.line() == x.line()) {
                t.read();
                return nan();
            }
            // ... similar cases for inf
          </pre>

          If the single-comment character was #, the floating point
          special format overrides the comment and will be parsed
          instead.

          If signedNumbers is false msvcFloatSpecials will not be parsed.

          Default is true. */
        bool                msvcFloatSpecials;

        /** Parses "+inf', "-inf", "inf", "nan" as floats instead of symbols. 
            Defaults to true.*/
        bool                simpleFloatSpecials;

        /**
         Parse the following set of useful proof symbols:
         
           =>
           ::>
           <::
           :>
           <:
           |-
           ::=
           :=
           <-

           Default is false.
        */
        bool                proofSymbols;

        /**
         When parsing booleans and msvcFloatSpecials, is case significant?
         Default is {true}
        */
        bool                caseSensitive;

        /** All symbols that will become the 'true' boolean token.  See also caseSensitive.
            Clear this value to disable parsing of true booleans.

            Default is {true}.
         */
        Set<std::string>    trueSymbols;

        /** See trueSymbols. Default is {false}*/
        Set<std::string>    falseSymbols;

        Settings();
    };
	
private:

    std::deque<Token>       stack;

    /**
     Characters to be tokenized.
     */
    Array<char>             buffer;

    /**
     Offset of current character (the next character to consumed) in
     input buffer.
     */
    int                     currentCharOffset;

    /**
     Line number of next character to be consumed from the input buffer.  (1
     indicates first line of input.)

     Note that this is the line number of the @e next character to be
     consumed from the input, not the line number of the @e last character
     consumed!
     */
    int                     lineNumber;

    /**
     Character number (within the line) of the next character to be consumed
     from the input buffer.  (1 indicates first character of the line).

     Note that this is the character number of the @e next character to be
     consumed from the input, not the character number of the @e last
     character consumed!
     */
    int                     charNumber;

    /** Configuration options.  This includes the file name that will be
        reported in tokens and exceptions.  */
    Settings                options;
  
    void init();

    /**
     Consumes the next character from the input buffer, and returns that
     character.  Updates lineNumber and charNumber to reflect the location of
     the next character in the input buffer.

     Note: you shouldn't be using the return value of this function in most
     cases.  In general, you should peekInputChar() to get the next
     character, determine what to do with it, then consume it with this
     function (or with eatAndPeekInputChar()).  Given that usage, in most
     instances you already know what this function would return!
     */
    int eatInputChar();

    /**
     Returns the next character from the input buffer, without consuming any
     characters.  Can also be used to look deeper into the input buffer.
     Does not modify lineNumber or charNumber.

     @param distance Index of the character in the input buffer to peek at,
     relative to the next character.  Default is 0, for the next character in
     the input buffer.
     */
    int peekInputChar(int distance = 0);

    /**
     Helper function to consume the next character in the input buffer and
     peek at the one following (without consuming it).
     */
    inline int eatAndPeekInputChar() {
        eatInputChar();
        return peekInputChar(0);
    }

    /**
     Read the next token, returning an END token if no more input is
     available.
     */
    Token nextToken();

    /**
       Helper for nextToken.  Appends characters to t._string until the end
       delimiter is reached.
       
       When called, the next character in the input buffer should be first the
       first character after the opening delimiter character.
    */
    void parseQuotedString(unsigned char delimiter, Token& t);

public:

    class TokenException : public ParseError {
    public:
        /** Name of file being parsed when exception occurred. 
            \deprecated  Use filename
         */
        std::string     sourceFile;

        virtual ~TokenException() {}

    protected:
        
        TokenException(
            const std::string&  src,
            int                 ln,
            int                 ch);

    };

    /** While parsing a number of the form 1.\#IN?00, ? was 
        not 'D' or 'F'. */
    class BadMSVCSpecial : public TokenException {
    public:

        BadMSVCSpecial(
            const std::string&  src,
            int                 ln,
            int                 ch);
    };

    /** Thrown by the read methods. */
    class WrongTokenType : public TokenException {
    public:
        Token::Type     expected;
        Token::Type     actual;

        WrongTokenType(
            const std::string&  src,
            int                 ln,
            int                 ch,
            Token::Type         e,
            Token::Type         a);
    };

    class WrongSymbol : public TokenException {
    public:
        std::string             expected;
        std::string             actual;

        WrongSymbol(
            const std::string&  src,
            int                 ln,
            int                 ch,
            const std::string&  e,
            const std::string&  a);
    };


    /** String read from input did not match expected string.  */
    class WrongString : public TokenException {
    public:
        std::string             expected;
        std::string             actual;

        WrongString(
            const std::string&  src,
            int                 ln,
            int                 ch,
            const std::string&  e,
            const std::string&  a);
    };

    TextInput(const std::string& filename, const Settings& settings = Settings());

    enum FS {FROM_STRING};
    /** Creates input directly from a string.  The first argument must be
        TextInput::FROM_STRING.
    */
    TextInput(FS fs, const std::string& str, const Settings& settings = Settings());

    /** Returns true while there are tokens remaining. */
    bool hasMore();

    /** Read the next token (which will be the END token if ! hasMore()).
    
        Signed numbers can be handled in one of two modes.  If the option 
        TextInput::Settings::signedNumbers is true,
        A '+' or '-' immediately before a number is prepended onto that number and
        if there is intervening whitespace, it is read as a separate symbol.

        If TextInput::Settings::signedNumbers is false,
        read() does not distinguish between a plus or minus symbol next
        to a number and a positive/negative number itself.  For example, "x - 1" and "x -1"
        will be parsed the same way by read().  
        
        In both cases, readNumber() will contract a leading "-" or "+" onto
        a number.
    */
    Token read();

    /** Calls read() until the result is not a newline or comment */
    Token readSignificant();

    /** Read one token (or possibly two) as a number or throws
        WrongTokenType, and returns the number.

        If the first token in the input is a number, it is returned directly.

        If TextInput::Settings::signedNumbers is false and the input stream
        contains a '+' or '-' symbol token immediately followed by a number
        token, both tokens will be consumed and a single token will be
        returned by this method.

        WrongTokenType will be thrown if one of the input conditions
        described above is not satisfied.  When an exception is thrown, no
        tokens are consumed.
    */
    double readNumber();

    bool readBoolean();

    /** Reads a string token or throws WrongTokenType, and returns the token.

        Use this method (rather than readString) if you want the token's
        location as well as its value.

        WrongTokenType will be thrown if the next token in the input stream
        is not a string.  When an exception is thrown, no tokens are
        consumed.
    */
    Token readStringToken();

    /** Like readStringToken, but returns the token's string.

        Use this method (rather than readStringToken) if you want the token's
        value but don't really care about its location in the input.  Use of
        readStringToken is encouraged for better error reporting.
    */
    std::string readString();

    /** Reads a specific string token or throws either WrongTokenType or
        WrongString.  If the next token in the input is a string matching @p
        s, it will be consumed.

        Use this method if you want to match a specific string from the
        input.  In that case, typically error reporting related to the token
        is only going to occur because of a mismatch, so no location
        information is needed by the caller.

        WrongTokenType will be thrown if the next token in the input stream
        is not a string.  WrongString will be thrown if the next token in the
        input stream is a string but does not match the @p s parameter.  When
        an exception is thrown, no tokens are consumed.

        \sa readString(), readStringToken(), readUntilNewlineAsString()
      */
    void readString(const std::string& s);

    /** Read from the beginning of the next token until the following newline 
      and return the result as a string, ignoring all parsing in between. The newline 
      is not returned in the string, and the following token read will be a newline or
      end of file token (if they are enabled for parsing).*/
    std::string readUntilNewlineAsString();

    /** Reads a comment token or throws WrongTokenType, and returns the token.

        Use this method (rather than readComment) if you want the token's
        location as well as its value.

        WrongTokenType will be thrown if the next token in the input stream
        is not a comment.  When an exception is thrown, no tokens are
        consumed.
    */
    Token readCommentToken();

    /** Like readCommentToken, but returns the token's string.

        Use this method (rather than readCommentToken) if you want the token's
        value but don't really care about its location in the input.  Use of
        readCommentToken is encouraged for better error reporting.
    */
    std::string readComment();

    /** Reads a specific comment token or throws either WrongTokenType or
        WrongString.  If the next token in the input is a comment matching @p
        s, it will be consumed.

        Use this method if you want to match a specific comment from the
        input.  In that case, typically error reporting related to the token
        is only going to occur because of a mismatch, so no location
        information is needed by the caller.

        WrongTokenType will be thrown if the next token in the input stream
        is not a comment.  WrongString will be thrown if the next token in the
        input stream is a comment but does not match the @p s parameter.  When
        an exception is thrown, no tokens are consumed.
      */
     void readComment(const std::string& s);

    /** Reads a newline token or throws WrongTokenType, and returns the token.

        Use this method (rather than readNewline) if you want the token's
        location as well as its value.

        WrongTokenType will be thrown if the next token in the input stream
        is not a newline.  When an exception is thrown, no tokens are
        consumed.
    */
    Token readNewlineToken();

    /** Like readNewlineToken, but returns the token's string.

        Use this method (rather than readNewlineToken) if you want the token's
        value but don't really care about its location in the input.  Use of
        readNewlineToken is encouraged for better error reporting.
    */
    std::string readNewline();

    /** Reads a specific newline token or throws either WrongTokenType or
        WrongString.  If the next token in the input is a newline matching @p
        s, it will be consumed.

        Use this method if you want to match a specific newline from the
        input.  In that case, typically error reporting related to the token
        is only going to occur because of a mismatch, so no location
        information is needed by the caller.

        WrongTokenType will be thrown if the next token in the input stream
        is not a newline.  WrongString will be thrown if the next token in the
        input stream is a newlin but does not match the @p s parameter.  When
        an exception is thrown, no tokens are consumed.
      */
     void readNewline(const std::string& s);

    /** Reads a symbol token or throws WrongTokenType, and returns the token.

        Use this method (rather than readSymbol) if you want the token's
        location as well as its value.

        WrongTokenType will be thrown if the next token in the input stream
        is not a symbol.  When an exception is thrown, no tokens are
        consumed.
    */
    Token readSymbolToken();

    /** Like readSymbolToken, but returns the token's string.

        Use this method (rather than readSymbolToken) if you want the token's
        value but don't really care about its location in the input.  Use of
        readSymbolToken is encouraged for better error reporting.
    */
    std::string readSymbol();

    /** Reads a specific symbol token or throws either WrongTokenType or
        WrongSymbol.  If the next token in the input is a symbol matching @p
        symbol, it will be consumed.

        Use this method if you want to match a specific symbol from the
        input.  In that case, typically error reporting related to the token
        is only going to occur because of a mismatch, so no location
        information is needed by the caller.

        WrongTokenType will be thrown if the next token in the input stream
        is not a symbol.  WrongSymbol will be thrown if the next token in the
        input stream is a symbol but does not match the @p symbol parameter.
        When an exception is thrown, no tokens are consumed.
    */
    void readSymbol(const std::string& symbol);


    /** Read a series of two specific symbols.  See readSymbol.  */
    void readSymbols(const std::string& s1, const std::string& s2) {
        readSymbol(s1);
        readSymbol(s2);
    }

    /** Read a series of three specific symbols.  See readSymbol.  */
    void readSymbols(
        const std::string& s1, 
        const std::string& s2, 
        const std::string& s3) {
        readSymbol(s1);
        readSymbol(s2);
        readSymbol(s3);
    }

    /** Read a series of four specific symbols.  See readSymbol.  */
    void readSymbols(
        const std::string& s1, 
        const std::string& s2, 
        const std::string& s3,     
        const std::string& s4) {
        readSymbol(s1);
        readSymbol(s2);
        readSymbol(s3);
        readSymbol(s4);
    }

    /** Return a copy of the next token in the input stream, but don't remove
        it from the input stream.
    */
    Token peek();

    /** Returns the line number for the @e next token.  See also peek.  */
    int peekLineNumber();

    /** Returns the character number (relative to the line) for the @e next
        token in the input stream.  See also peek.
    */
    int peekCharacterNumber();

    /** Take a previously read token and push it back at the front of the
        input stream.

        Can be used in the case where more than one token of read-ahead is
        needed (i.e., when peek doesn't suffice).
    */
    void push(const Token& t);

    /** Returns the filename from which this input is drawn, or the first few
        characters of the string if created from a string.
        If settings::filename is non-empty that will replace the
        true filename.*/
    const std::string& filename() const;
};

void deserialize(bool& b, TextInput& ti);
void deserialize(int& b, TextInput& ti);
void deserialize(uint8& b, TextInput& ti);
void deserialize(double& b, TextInput& ti);
void deserialize(float& b, TextInput& ti);
void deserialize(std::string& b, TextInput& ti);

} // namespace

#endif

