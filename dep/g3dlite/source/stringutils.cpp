/**
 \file stringutils.cpp

 \maintainer Morgan McGuire, http://graphics.cs.williams.edu

 \created 2000-09-09
 \edited  2011-08-20
*/

#include "G3D/platform.h"
#include "G3D/stringutils.h"
#include "G3D/BinaryInput.h"
#include <algorithm>

#ifdef G3D_WINDOWS
extern "C" {    
    // Define functions for ffmpeg since we don't link in gcc's c library
    extern int strncasecmp(const char *string1, const char *string2, size_t count) { return _strnicmp(string1, string2, count); }
    extern int strcasecmp(const char *string1, const char *string2) { return _stricmp(string1, string2); }
}
#endif

namespace G3D {

#ifdef _MSC_VER
    // disable: "C++ exception handler used"
#   pragma warning (push)
#   pragma warning (disable : 4530)
#endif
#ifdef G3D_WINDOWS
    const char* NEWLINE = "\r\n";
#else
    const char* NEWLINE = "\n";
    static bool iswspace(int ch) { return (ch==' ' || ch=='\t' || ch=='\n' || ch=='\r'); }
#endif

bool __cdecl alphabeticalIgnoringCaseG3DLastLessThan(const String& _a, const String& _b) {
    const String& a = toLower(_a);
    const String& b = toLower(_b);

    if (beginsWith(a, "g3d")) {
        if (beginsWith(b, "g3d")) {
            return (a < b);
        } else {
            return false;
        }
    } else if (beginsWith(b, "g3d")) {
        return true;
    } else {
        return (a < b);
    }
}

void parseCommaSeparated(const String s, Array<String>& array, bool stripQuotes) {
    array.fastClear();
    if (s == "") {
        return;
    }

    size_t begin = 0;
    const char delimiter = ',';
    const char quote = '\"';
    do {
        size_t end = begin;
        // Find the next comma, or the end of the string
        bool inQuotes = false;
        while ((end < s.length()) && (inQuotes || (s[end] != delimiter))) {
            if (s[end] == quote) {
                if ((end < s.length() - 2) && (s[end + 1] == quote) && (s[end + 2]) == quote) {
                    // Skip over the superquote
                    end += 2;
                }
                inQuotes = ! inQuotes;
            }
            ++end;
        }
        array.append(s.substr(begin, end - begin));
        begin = end + 1;
    } while (begin < s.length());

    if (stripQuotes) {
        for (int i = 0; i < array.length(); ++i) {
            String& t = array[i];
            size_t L = t.length();
            if ((L > 1) && (t[0] == quote) && (t[L - 1] == quote)) {
                if ((L > 6)  && (t[1] == quote) && (t[2] == quote) && (t[L - 3] == quote) && (t[L - 2] == quote)) {
                    // Triple-quote
                    t = t.substr(3, L - 6);
                } else {
                    // Double-quote
                    t = t.substr(1, L - 2);
                }
            }
        }
    }
}

bool beginsWith(
    const String& test,
    const String& pattern) {

    if (test.size() >= pattern.size()) {
        for (int i = 0; i < (int)pattern.size(); ++i) {
            if (pattern[i] != test[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

String replace(const String& s, const String& pattern, const String& replacement) {
    if (pattern.length() == 0) {
        return s;
    }
	String temp = "";
    size_t lastindex = 0;
    size_t nextindex = 0;
    do {
        nextindex = s.find(pattern, lastindex);
        if (nextindex == String::npos) {
            break;
        }
        temp += s.substr(lastindex, nextindex - lastindex) + replacement;
        lastindex = nextindex + pattern.length();
    } while (lastindex + pattern.length() <= s.length());
    return temp + (lastindex < s.length() ? s.substr(lastindex) : "");
}

bool isValidIdentifier(const String& s) {
    if (s.length() > 0 && (isLetter(s[0]) || s[0] == '_')) {   
        for (size_t i = 1; i < s.length() ; ++i) {
            if (!( isLetter(s[i]) || (s[i] == '_') || isDigit(s[i]) )) {
                return false;
            }
        }
        return true;
    }
    return false;
}

String makeValidIndentifierWithUnderscores(const String& s) {
    
    String valid = s;
    if (!isValidIdentifier(s)) {
        //begin with underscore if invalid first character
        if (!(isLetter(s[0]) || s[0] == '_')) {
            valid = '_' + s;
        }
        for (size_t i = 1; i < valid.length(); ++i) {
            if (! ((valid[i] == '_') || isLetter(valid[i]) || isDigit(valid[i]))) {
                valid[i] = '_';
            }
        }
    }
    return valid;
}

bool endsWith(
    const String& test,
    const String& pattern) {

    if (test.size() >= pattern.size()) {
        size_t te = test.size() - 1;
        size_t pe = pattern.size() - 1;
        for (int i = (int)pattern.size() - 1; i >= 0; --i) {
            if (pattern[pe - i] != test[te - i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}


String wordWrap(
    const String&      input,
    int                     numCols) {

    String output;
    size_t      c = 0;
    int         len;

    // Don't make lines less than this length
    int         minLength = numCols / 4;
    size_t      inLen = input.size();

    bool first = true;
    while (c < inLen) {
        if (first) {
            first = false;
        } else {
            output += NEWLINE;
        }

        if ((int)inLen - (int)c - 1 < numCols) {
            // The end
            output += input.substr(c, inLen - c);
            break;
        }

        len = numCols;

        // Look at character c + numCols, see if it is a space.
        while ((len > minLength) &&
               (input[c + len] != ' ')) {
            len--;
        }

        if (len == minLength) {
            // Just crop
            len = numCols;

        }

        output += input.substr(c, len);
        c += len;
        if (c < input.size()) {
            // Collapse multiple spaces.
            while ((input[c] == ' ') && (c < input.size())) {
                ++c;
            }
        }
    }

    return output;
}


int stringCompare(
    const String&      s1,
    const String&      s2) {

    return stringPtrCompare(&s1, &s2);
}


int stringPtrCompare(
    const String*      s1,
    const String*      s2) {

    return s1->compare(*s2);
}


String toUpper(const String& x) {
    String result = x;
    std::transform(result.begin(), result.end(), result.begin(), toupper);
    return result;
}


String toLower(const String& x) {
    String result = x;
    std::transform(result.begin(), result.end(), result.begin(), tolower);
    return result;
}


Array<String> stringSplit(
    const String&          x,
    char                        splitChar) {

    Array<String> out;
    
    // Pointers to the beginning and end of the substring
    const char* start = x.c_str();
    const char* stop = start;
    
    while ((stop = strchr(start, splitChar))) {
        out.append(String(start, stop - start));
        start = stop + 1;
    }

    // Append the last one
    out.append(String(start));
    
    return out;
}


String stringJoin(
    const Array<String>&   a,
    char                        joinChar) {

    String out;

    for (int i = 0; i < (int)a.size() - 1; ++i) {
        out += a[i] + joinChar;
    }

    if (a.size() > 0) {
        return out + a.last();
    } else {
        return out;
    }
}


String stringJoin(
    const Array<String>&   a,
    const String&          joinStr) {

    String out;

    for (int i = 0; i < (int)a.size() - 1; ++i) {
        out += a[i] + joinStr;
    }

    if (a.size() > 0) {
        return out + a.last();
    } else {
        return out;
    }
}


String trimWhitespace(const String& s) {

    if (s.length() == 0) {
        return s;
    }
    size_t left = 0;
    
    // Trim from left
    while ((left < s.length()) && iswspace(s[left])) {
        ++left;
    }

    size_t right = s.length() - 1;
    // Trim from right
    while ((right > left) && iswspace(s[right])) {
        --right;
    }
    
    return s.substr(left, right - left + 1);
}


}; // namespace

#undef NEWLINE
#ifdef _MSC_VER
#   pragma warning (pop)
#endif
