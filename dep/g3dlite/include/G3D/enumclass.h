/**
  @file G3D/enumclass.h

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2007-01-27
  @edited  2007-07-20
*/
#ifndef G3D_enumclass_h
#define G3D_enumclass_h

#include "G3D/HashTrait.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

/**
\def G3D_DECLARE_ENUM_CLASS_METHODS

  \brief Creates a series of methods that turn a class into a scoped enumeration.

  Uses the "Intelligent Enum" design pattern 
  http://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4001/

  Enum classes are initialized to their zero value by default.

  You must implement the following method before calling G3D_DECLARE_ENUM_CLASS_METHODS, as either:

  <pre>
    static const char* toString(int i, Value& v) {
        static const char* str[] = {"FUEL", "FOOD", "WATER", NULL}; // Whatever your enum values are
        static const Value val[] = {FUEL, FOOD, WATER};             // Whatever your enum values are
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s;
    }
  </pre>

  See GLG3D/GKey.h for an example.
  \sa G3D_DECLARE_ENUM_CLASS_HASHCODE
 */
#define G3D_DECLARE_ENUM_CLASS_METHODS(Classname)\
private: \
    void fromString(const std::string& x) {\
        Value v;\
        const char* s;\
        int i = 0;\
\
        do {\
            s = toString(i, v);\
            if (x == s) {\
                value = v;\
                return;\
            }\
            ++i;\
        } while (s);\
    }\
\
public:\
\
    const char* toString() const {\
        const char* s;\
        int i = 0;\
        Value v = (Value)0;\
        while (true) {\
            s = toString(i, v);\
            if ((s == NULL) || (v == value)) {\
                return s;\
            }\
            ++i;\
        }\
        return NULL;\
    }\
\
    explicit Classname(const std::string& x) : value((Value)0) {\
        fromString(x);\
    }\
\
    Classname(const Any& a) : value((Value)0) {\
        fromString(a.string());\
    }\
\
    operator Any() const {\
        return Any(toString());\
    }\
\
    Classname(char v) : value((Value)v) {}\
\
    Classname() : value((Value)0) {}\
\
    Classname(const Value v) : value(v) {}\
\
    explicit Classname(int v) : value((Value)v) {}\
\
    /** Support cast back to the Value type, which is needed to allow implicit assignment inside unions. */\
    /*inline operator Value() const {
        return value;
	}*/\
\
    operator int() const {\
        return (int)value;\
    }\
\
    bool operator== (const Classname other) const {\
        return value == other.value;\
    }\
\
    bool operator== (const Classname::Value other) const {\
        return value == other;\
    }\
\
    bool operator!= (const Classname other) const {\
        return value != other.value;\
    }\
\
    bool operator!= (const Classname::Value other) const {\
        return value != other;\
    }\
\
    bool operator< (const Classname other) const {\
        return value < other.value;\
    }\
\
    bool operator> (const Classname other) const {\
        return value > other.value;\
    }\
\
    bool operator>= (const Classname other) const {\
        return value >= other.value;\
    }\
\
    bool operator<= (const Classname other) const {\
        return value <= other.value;\
    }\
\
    bool operator< (const Value other) const {\
        return value < other;\
    }\
\
    bool operator> (const Value other) const {\
        return value > other;\
    }\
\
    bool operator<= (const Value other) const {\
        return value <= other;\
    }\
\
    bool operator>= (const Value other) const {\
        return value >= other;\
    }\
\
    Classname& operator-- () {\
        value = (Value)((int)value - 1);\
        return *this;\
    }\
\
    Classname& operator++ () {\
        value = (Value)((int)value + 1);\
        return *this;\
    }\
\
    Classname& operator+= (const int x) {\
        value = (Value)((int)value + x);\
        return *this;\
    }\
\
    Classname& operator-= (const int x) {\
        value = (Value)((int)value - x);\
        return *this;\
    }\
\
    Classname operator+ (const int x) const {\
        return Classname((int)value + x);\
    }\
\
    Classname operator- (const int x) const {\
        return Classname((int)value - x);\
    }\
\
    unsigned int hashCode() const {\
        return (unsigned int)value;\
    }\
\
    void serialize(BinaryOutput& b) const {\
        b.writeInt32(value);\
    }\
\
    void deserialize(BinaryInput& b) {\
        value = (Value)b.readInt32();\
    }

/** \def G3D_DECLARE_ENUM_CLASS_HASHCODE
*/
#define G3D_DECLARE_ENUM_CLASS_HASHCODE(Classname)\
template <> struct HashTrait<Classname::Value>                                              \
{                                                                                           \
    static size_t hashCode(Classname::Value key) { return static_cast<size_t>(key); }       \
};                                                                                          \
                                                                                            \
template <> struct HashTrait<Classname>                                                     \
{                                                                                           \
    static size_t hashCode(Classname key) { return static_cast<size_t>(key.hashCode()); }   \
};

#endif
