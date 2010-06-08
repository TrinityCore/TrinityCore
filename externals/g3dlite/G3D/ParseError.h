/**
 @file ParseError.h
  
 @maintainer Morgan McGuire
  
 @created 2009-11-15
 @edited  2009-11-15

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */
#ifndef G3D_ParseError_h
#define G3D_ParseError_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include <string>

namespace G3D {

/** Thrown by TextInput, Any, and other parsers on unexpected input. */
class ParseError {
public:
    enum {UNKNOWN = -1};
    
    /** Empty means unknown */
    std::string     filename;
    
    /** For a binary file, the location of the parse error. -1 if unknown.*/
    int64           byte;

    /** For a text file, the line number is the line number of start of token which caused the exception.  1 is
        the first line of the file.  -1 means unknown.  Note that you can use 
        TextInput::Settings::startingLineNumberOffset to shift the effective line
        number that is reported by that class.
    */
    int             line;

    /** Character number (in the line) of the start of the token which caused the
    exception.  1 is the character in the line. May be -1 if unknown.
    */
    int             character;

    std::string     message;
 
    ParseError() : byte(UNKNOWN), line(UNKNOWN), character(UNKNOWN) {}

    virtual ~ParseError() {}

    ParseError(const std::string& f, int l, int c, const std::string& m) :
        filename (f),  byte(UNKNOWN), line(l), character(c), message(m) {}

    ParseError(const std::string& f, int64 b, const std::string& m) :
        filename (f),  byte(b), line(UNKNOWN), character(UNKNOWN), message(m) {}
};

}

#endif
