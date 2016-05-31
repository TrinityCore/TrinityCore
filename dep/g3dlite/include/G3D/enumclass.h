/**
  \file G3D/enumclass.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  \created 2007-01-27
  \edited  2013-04-09
*/
#ifndef G3D_enumclass_h
#define G3D_enumclass_h

#include "G3D/platform.h"
#include "G3D/HashTrait.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextOutput.h"
#include "G3D/Any.h"

namespace G3D {
    namespace _internal {
        const char** smartEnumParseNames(const char* enumValList);
    }
}

/**
\def G3D_DECLARE_ENUM_CLASS_METHODS

  \brief Creates a series of methods that turn a class into a scoped enumeration.

  Example of use:

  \code
  class Resource {
  public:
    enum Value {FUEL, FOOD, WATER} value;
    
    // i is the position the enum value in Value (not the enum value itself)
    static const char* toString(int i, Value& v) {
        static const char* str[] = {"FUEL", "FOOD", "WATER", NULL}; // Whatever your enum values are
        static const Value val[] = {FUEL, FOOD, WATER};             // Whatever your enum values are
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s;
    }

    G3D_DECLARE_ENUM_CLASS_METHODS(Resource);
  };
  G3D_DECLARE_ENUM_CLASS_HASHCODE(Resource);
  \endcode

  Extends the "Intelligent Enum" design pattern 
  http://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4001/

  Enum classes are initialized to their zero value by default.

  See GLG3D/GKey.h and G3D/WrapMode for an example.
  \sa G3D_DECLARE_ENUM_CLASS_HASHCODE
 */
#define G3D_DECLARE_ENUM_CLASS_METHODS(Classname)\
private: \
    void fromString(const std::string& x) {\
        Value v = (Value)0;\
        const char* s;\
        int i = 0;\
\
        do {\
            s = toString(i, v);\
            if (s == NULL) { return; /** Needed to get correct compilation on gcc */ } \
            if (x == s) {\
                value = v;\
                return;\
            }\
            ++i;\
        } while (true);\
    }\
\
public:\
    static const char* classname() {\
        return #Classname;\
    }\
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
    }\
\
    explicit Classname(const std::string& x) : value((Value)0) {\
        fromString(x);\
    }\
\
    explicit Classname(const G3D::Any& a) : value((Value)0) {   \
        fromString(a.string());\
    }\
\
    G3D::Any toAny() const {                    \
        return G3D::Any(toString());            \
    }\
\
    explicit Classname(char v) : value((Value)v) {}\
\
    Classname() : value((Value)0) {}\
\
    Classname(const Value v) : value(v) {}\
\
    explicit Classname(int v) : value((Value)v) {}\
\
    operator int() const {\
        return (int)value;\
    }\
\
    Classname& operator=(const Any& a) {\
        value = Classname(a).value;\
        return *this;\
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
    void serialize(G3D::BinaryOutput& b) const {    \
        b.writeInt32(value);\
    }\
\
    void deserialize(G3D::BinaryInput& b) {         \
        value = (Value)b.readInt32();\
    }

/** \def G3D_DECLARE_ENUM_CLASS_HASHCODE
   Must be used at top level (i.e., not inside a class or namespace), with a fully qualified class name.
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

/**
\def G3D_DECLARE_ENUM_CLASS

\code
// Arguments may not have initializer expressions.  Arguments may contain comments.
// Namespaces aren't *required*, this example just shows how to use them.
namespace Foo {
   G3D_DECLARE_ENUM_CLASS(Day, SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY);
}
G3D_DECLARE_ENUM_CLASS_HASHCODE(Foo::Day);
...

using namespace Foo;
// Example use of the smart enum
Day d = Day::TUESDAY;
Day d2("SATURDAY");
Any a(d);
d = a;
printf("%s = %d\n", d.toString(), d.value);
\endcode

\sa G3D_DECLARE_ENUM_CLASS_METHODS, G3D_DECLARE_ENUM_CLASS_HASHCODE, G3D::enumToJavaScriptDeclaration, G3D_BEGIN_ENUM_CLASS_DECLARATION
*/
#define G3D_DECLARE_ENUM_CLASS(ClassName, ...)\
    G3D_BEGIN_ENUM_CLASS_DECLARATION(ClassName, __VA_ARGS__);\
    G3D_END_ENUM_CLASS_DECLARATION();

/** \def G3D_BEGIN_ENUM_CLASS_DECLARATION

\code
G3D_BEGIN_ENUM_CLASS_DECLARATION(Day, SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY);
   // Put extra methods here, e.g., 
   Value nextValue() { ... }
G3D_END_ENUM_CLASS_DECLARATION();
}
G3D_DECLARE_ENUM_CLASS_HASHCODE(Foo::Day);

\endcode
    \sa G3D_DECLARE_ENUM_CLASS, G3D_END_ENUM_CLASS_DECLARATION
*/
#define G3D_BEGIN_ENUM_CLASS_DECLARATION(ClassName, ...)\
class ClassName {\
public:\
    enum Value {\
        __VA_ARGS__\
    } value;\
\
    /* The static variables here may be duplicated in different shared object binaries (DLLs), but that's ok--we only depend on their values, not their uniqueness.  See also http://stackoverflow.com/questions/11962918/local-static-variable-is-instantiated-multiple-times-why */\
    static const char* toString(int i, Value& v) {\
        static const char** str = G3D::_internal::smartEnumParseNames(#__VA_ARGS__);\
        static const Value val[] = {__VA_ARGS__};\
        const char* s = str[i];\
        if (s) { v = val[i]; }\
        return s;\
    }\
\
    G3D_DECLARE_ENUM_CLASS_METHODS(ClassName);

/** \def G3D_END_ENUM_CLASS_DECLARATION
    \sa G3D_BEGIN_ENUM_CLASS_DECLARATION */
#define G3D_END_ENUM_CLASS_DECLARATION() }


namespace G3D {

/**
 \brief Generates JavaScript source code defining an enum equivalent to
 EnumClass.

 \code
    TextOutput t("WrapMode.js");
    enumToJavaScriptDeclaration<WrapMode, WrapMode::Value>(t);
    t.commit();
 \endcode
 */
template<class EnumClass, class EnumClassValue>
void enumToJavaScriptDeclaration(TextOutput& t) {
    t.printf("/* BEGIN GENERATED CODE. The following was automatically generated by G3D::enumToJavaScriptDeclaration().  Do not edit it manually. */\n\n");
    t.printf("var %s = (function (propList) {", EnumClass::classname()); t.writeNewline();
    t.pushIndent(); {
        t.printf("// Define immutable properties"); t.writeNewline();
        t.printf("var en = {};"); t.writeNewline();
        t.printf("for (var i = 0; i < propList.length; i += 2)"); t.writeNewline();
        t.pushIndent(); {
            t.printf("Object.defineProperty(en, propList[i], {enumerable: true, value: propList[i + 1]});"); t.writeNewline();
        } t.popIndent();
        t.printf("return en;");
        t.writeNewline();
    } t.popIndent();
    t.printf("})([");
    int i = 0;
    EnumClassValue m;
    const char* s = EnumClass::toString(i, m);
    while (notNull(s)) {
        t.printf("\"%s\", %d, ", s, int(m));
        ++i;
        s = EnumClass::toString(i, m);
    }
    // JavaScript allows a trailing comma
    t.printf("]);"); t.writeNewline();
    t.printf("/* END GENERATED CODE */"); t.writeNewline();
}

}
#endif
