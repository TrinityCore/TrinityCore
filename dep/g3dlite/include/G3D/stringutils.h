/**
 @file stringutils.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2000-09-09
 @edited  2010-03-05
 */

#ifndef G3D_stringutils_h
#define G3D_stringutils_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include <cstring>

namespace G3D {

extern const char* NEWLINE;

/** Separates a comma-separated line, properly escaping commas within
    double quotes (") and super quotes ("""). This matches Microsoft Excel's 
    CSV output.

    \param stripQuotes If true, strips leading and trailing " and """

    \sa G3D::stringSplit, G3D::TextInput, G3D::readWholeFile
*/
void parseCommaSeparated(const std::string s, Array<std::string>& array, bool stripQuotes = true);

/** Finds the index of the first '\\' or '/' character, starting at index \a start. 
  \sa G3D::findLastSlash, G3D::isSlash
*/
inline int findSlash(const std::string& f, int start = 0) {
    int i = f.find('/', start);
    int j = f.find('\\', start);
    if (((i != -1) && (i < j)) || (j == -1)) {
        return i;
    } else {
        return j;
    }
}


/** Finds the index of the first '\\' or '/' character, starting at index \a start (if \a start is -1, starts at the end of the string).
  \sa G3D::findSlash, G3D::isSlash
  */
inline int findLastSlash(const std::string& f, int start = -1) {
    if (start == -1) {
        start = f.length() - 1;
    }

    int i = f.rfind('/', start);
    int j = f.rfind('\\', start);
    return max(i, j);
}

/**
 Returns true if the test string begins with the pattern string.
 */
bool beginsWith(
    const std::string&          test,
    const std::string&          pattern);

/**
 Returns true if the test string ends with the pattern string.
 */
bool endsWith(
    const std::string&          test,
    const std::string&          pattern);

/**
 Produces a new string that is the input string
 wrapped at a certain number of columns (where
 the line is broken at the latest space before the
 column limit.)  Platform specific NEWLINEs
 are inserted to wrap.
 */
std::string wordWrap(
    const std::string&          input,
    int                         numCols);

/**
 A comparison function for passing to Array::sort.
 */
int stringCompare(
    const std::string&          s1,
    const std::string&          s2);

int stringPtrCompare(
    const std::string*          s1,
    const std::string*          s2);

/**
 Returns a new string that is an uppercase version of x.
 */
std::string toUpper(
    const std::string&          x);

std::string toLower(
    const std::string&          x);

/**
 Splits x at each occurance of splitChar.
 */
G3D::Array<std::string> stringSplit(
    const std::string&          x,
    char                        splitChar);

/**
 joinChar is not inserted at the beginning or end, just in between
 elements.
 */
std::string stringJoin(
    const G3D::Array<std::string>&   a,
    char                        joinChar);

std::string stringJoin(
    const G3D::Array<std::string>&   a,
    const std::string&               joinStr);

/**
 Strips whitespace from both ends of the string.
 */
std::string trimWhitespace(
    const std::string&              s);

/** These standard C functions are renamed for clarity/naming
   conventions and to return bool, not int.
   */
inline bool isWhiteSpace(const unsigned char c) {
    return isspace(c) != 0;
}

/** These standard C functions are renamed for clarity/naming
   conventions and to return bool, not int.
   */
inline bool isNewline(const unsigned char c) {
    return (c == '\n') || (c == '\r');
}

/** These standard C functions are renamed for clarity/naming
   conventions and to return bool, not int.
   */
inline bool isDigit(const unsigned char c) {
    return isdigit(c) != 0;
}

/** These standard C functions are renamed for clarity/naming
   conventions and to return bool, not int.
   */
inline bool isLetter(const unsigned char c) {
    return isalpha(c) != 0;
}

inline bool isSlash(const unsigned char c) {
    return (c == '\\') || (c == '/');
}

inline bool isQuote(const unsigned char c) {
    return (c == '\'') || (c == '\"');
}

}; // namespace

#endif

