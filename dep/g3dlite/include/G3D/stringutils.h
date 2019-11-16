/**
 @file stringutils.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2000-09-09
 @edited  2015-03-17
 */

#ifndef G3D_stringutils_h
#define G3D_stringutils_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/DepthFirstTreeBuilder.h"
#include <cstring>
#include "G3D/G3DString.h"

namespace G3D {

extern const char* NEWLINE;

/** Separates a comma-separated line, properly escaping commas within
    double quotes (") and super quotes ("""). This matches Microsoft Excel's 
    CSV output.

    \param stripQuotes If true, strips leading and trailing " and """

    \sa G3D::stringSplit, G3D::TextInput, G3D::readWholeFile
*/
void parseCommaSeparated(const String s, Array<String>& array, bool stripQuotes = true);

/** Compares a < b ignoring case, but puts names beginning with "G3D" last in a sort. \sa Array::sort */
bool __cdecl alphabeticalIgnoringCaseG3DLastLessThan(const String& a, const String& b);

/** Finds the index of the first '\\' or '/' character, starting at index \a start. 
  \sa G3D::findLastSlash, G3D::isSlash
*/
inline size_t findSlash(const String& f, size_t start = 0) {
    size_t i = f.find('/', start);
    size_t j = f.find('\\', start);
    if ((i != String::npos) && (i < j)) {
        return i;
    } else {
        return j;
    }
}

/** \brief Returns the larger string index, ignoring String::npos. */
inline size_t maxNotNPOS(size_t i, size_t j) {
    if (i == String::npos) {
        return j;
    } else if (j == String::npos) {
        return i;
    } else {
        return max(i, j);
    }
}

/** Finds the index of the first '\\' or '/' character, starting at index \a start (if \a start is -1, starts at the end of the string).
  \sa G3D::findSlash, G3D::isSlash
  */
inline size_t findLastSlash(const String& f, size_t start = String::npos) {
    if (start == String::npos) {
        start = f.length() - 1;
    }

    size_t i = f.rfind('/', start);
    size_t j = f.rfind('\\', start);
    return maxNotNPOS(i, j);
}


/** Returns a string which is \a s, with all instances of \a pattern replaced */
String replace(const String& s, const String& pattern, const String& replacement);

/** Returns true if \a s is a valid C identifier */
bool isValidIdentifier(const String& s);

/** Replaces invalid characters in a string with underscroes to make the string a valid C identifier */
String makeValidIndentifierWithUnderscores(const String& s);

/**
 \brief Returns true if the test string begins with the pattern string.
 */
bool beginsWith
   (const String&          test,
    const String&          pattern);

/**
 \brief Returns true if the test string ends with the pattern string.
 */
bool endsWith
   (const String&          test,
    const String&          pattern);

/**
 \brief Produces a new string that is the input string
 wrapped at a certain number of columns (where
 the line is broken at the latest space before the
 column limit.)  Platform specific NEWLINEs
 are inserted to wrap.

 \sa G3D::GFont::wordWrapCut, G3D::TextOutput::Settings::WordWrapMode
 */
String wordWrap
   (const String&          input,
    int                         numCols);

/**
 A comparison function for passing to Array::sort.
 */
int stringCompare(
    const String&          s1,
    const String&          s2);

int stringPtrCompare(
    const String*          s1,
    const String*          s2);

/**
 Returns a new string that is an uppercase version of x.
 */
String toUpper(
    const String&          x);

String toLower(
    const String&          x);

/**
 Splits x at each occurance of splitChar.
 */
G3D::Array<String> stringSplit(
    const String&          x,
    char                        splitChar);

/**
 joinChar is not inserted at the beginning or end, just in between
 elements.
 */
String stringJoin(
    const G3D::Array<String>&   a,
    char                        joinChar);

String stringJoin(
    const G3D::Array<String>&   a,
    const String&               joinStr);

/**
 Strips whitespace from both ends of the string.
 */
String trimWhitespace(
    const String&              s);

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

/** Much faster than isDigit in MSVC */
inline bool isDigitFast(const unsigned char c) {
    return c >= '0' && c <= '9';
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

/** Number of new lines in the given string */
inline int countNewlines(const String& s) {
    int c = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '\n') {
            ++c;
        }
    }
    return c;
}

/** Finds the greatest common prefix of two strings 
    of ' ', ':', ';', '/', and '\' separated words.
    \param a const String
    \param b const String */
inline String greatestCommonPrefix(const String a, const String b) {
    String rest = a;  //rest of unsearched string a
    size_t i = 0;     //end index of gcp so far
        
    while ((i < a.length()) && (i < b.length())) {
        const size_t j = rest.find_first_of(" :/\\;"); 
        //since j is the index of the first found separator, the length of the prefix is j+1       
        if ((j == std::string::npos)    //no more separators in a
            || (i + j + 1 > b.length()) //not enough characters in b to contain the prefix
            || (a.substr(i, j + 1) != b.substr(i, j + 1))) { 
            return a.substr(0, i);
        }           
        i += j + 1;
        rest = a.substr(i);
    }
    return a.substr(0, i);
}   


/** Does a depth first traversal of a prefix tree 
    generated from the passed list. The list must 
    be sorted alphabetically.
\param list alphabetically sorted list of strings
\param tree depth first tree traversal, providing functions enterChild(n) and goToParent() */
void buildPrefixTree(const Array<String>& list, DepthFirstTreeBuilder<String>& tree);

}; // namespace

#endif

