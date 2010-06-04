/**
 @file Any.h
  
 @author Morgan McGuire, Shawn Yarbrough, and Corey Taylor
 @maintainer Morgan McGuire
  
 @created 2006-06-11
 @edited  2009-12-16

 Copyright 2000-2010, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_Any_h
#define G3D_Any_h

#include "G3D/platform.h"
#include "G3D/Table.h"
#include "G3D/Array.h"
#include "G3D/AtomicInt32.h"
#include <string>

// needed for Token
#include "G3D/TextInput.h"

#ifdef verify
#undef verify
#endif

namespace G3D {

class TextOutput;

/** 
\brief Easy loading and saving of human-readable configuration files.

Encodes typed, structured data and can serialize it to a human
readable format that is very similar to the Python language's data
syntax.  Well-suited for quickly creating human-readable file formats,
especially since deserialization and serialization preserve comments and
an Any can tell you what file and line it came from.

The class is designed so that copying Anys generally is fast, even if
it is a large array or table.  This is because data is shared between
copies until it is mutated, at which point an actual copy occurs.

\section Example
Sample File:
<pre>
{
   shape = "round",

   # in meters
   radius = 3.7,

   position = Vector3(1.0, -1.0, 0.0),
   texture = { format = "RGB8", size = (320, 200)}
}
</pre>

Sample code using:
<pre>
Any x;
x.load("ball.txt");
if (x["shape"].string() == "round") {
    x["density"] = 3;
}
x.save("ball.txt");
</pre>

The custom serialization format was chosen to be terse, easy for
humans to read, and easy for machines to parse. It was specifically
chosen over formats like XML, YAML, JSON, S-expressions, and Protocol
Buffers, although there is no reason you could not write readers and
writers for G3D::Any that support those.

G3D::Any assumes that structures do not contain cycles; it is an 
error to create a structure like:

<pre>
Any x(Any::ARRAY);
x.array().append(x);    // don't do this!
</pre>

although no exception will be thrown at runtime during that append.


\section Parsing

The primary use of Any is to create your own text file formats.
The Vector3 constructor is a good example of how to use the Any::verify 
methods to provide good error checking while parsing such formats:

<pre>
Vector3::Vector3(const Any& any) {
    any.verifyName("Vector3");
    any.verifyType(Any::TABLE, Any::ARRAY);
    any.verifySize(3);

    if (any.type() == Any::ARRAY) {
        x = any[0];
        y = any[1];
        z = any[2];
    } else {
        // Table
        x = any["x"];
        y = any["y"];
        z = any["z"];
    }
}
</pre>

\section BNF
Serialized format BNF:

<pre>
identifier  ::= (letter | "_") (letter | digit | "_")*
identifier-op ::= "::" | "->" | "."

identifier-exp ::= [identifier-op] identifier (identifier-op identifier)*

comment     ::= "#" <any characters> "\n"
separator   ::= "," | ";"

number      ::= <legal C printf number format>
string      ::= <legal C double-quoted string; backslashes must be escaped>
boolean     ::= "True" | "False"
none        ::= "None"
array       ::= "(" [value ("," value)*] ")"
pair        ::= (identifier | string) "=" value
table       ::= "{" [pair (separator pair)*] "}"
named-array ::= identifier-exp tuple
named-table ::= identifier-exp dict

value       ::= [comment] (none | number | boolean | string | array | table | named-array | named-table)
</pre>

Except for single-line comments, whitespace is not significant.  
All parsing is case-insensitive.

The deserializer allows the substitution of [] for () when writing
tuples and ";" for ",".

The serializer indents four spaces for each level of nesting. 
Tables are written with the keys in alphabetic order.
*/
class Any {
public:

    enum Type {NONE, BOOLEAN, NUMBER, STRING, ARRAY, TABLE};

    static std::string toString(Type t);

    /** Where an Any came from in a file.  Useful for throwing parsing errors */
    class Source {
    public:
        std::string                 filename;
        int                         line;
        int                         character;

        Source() : line(0), character(0) {}

        void set(const TextInput& ti, const Token& t) {
            filename  = ti.filename();
            line      = t.line();
            character = t.character();
        }
    };

    typedef Array<Any> AnyArray;
    typedef Table<std::string, Any> AnyTable;

private:

    /** Called from deserialize() */
    static void deserializeComment(TextInput& ti, Token& token, std::string& comment);

    /** NONE, BOOLEAN, and NUMBER are stored directly in the Any */
    union SimpleValue {
        bool                        b;
        double                      n;

        inline SimpleValue() : n(0.0) {}
        inline SimpleValue(bool x) : b(x) {}
        inline SimpleValue(double x) : n(x) {}
    };
 
    class Data {
    public:
        /** ARRAY, TABLE, or STRING value only.  NULL otherwise. */
        union Value {
            std::string*             s;
            Array<Any>*              a;
            AnyTable*                t;
            inline Value() : s(NULL) {}
        };

        // Needed so that the destructor knows what is in Value
        // and can call its destructor. 
        Type                         type;
        
        /** Always points to memory that is allocated with the Data, so
           the destructor does not delete this. */
        Value                        value;
        
        std::string                  comment;

        std::string                  name;

        /** For STRING, ARRAY and TABLE types, m_value is shared between
            multiple instances.  Mutation is allowed only if the reference
            count is exactly 1, otherwise the mutating instance must copy
            the value.  This is not used for other types.
        */
        AtomicInt32                  referenceCount;

        Source                       source;

    private:

        /** Called by create() */
        inline Data(Type t) : type(t), referenceCount(1) {}

        /** Called by destroy */
        ~Data();

    public:

        /** Clones the argument */
        static Data* create(const Data* d);
        static Data* create(Type t);

        /** Free d, invoking its destructor and freeing the memory for
            the value. */
        static void destroy(Data* d);

    };

    /** If not empty, this Any was created from operator[] on a table
        and perhaps was not intended to exist.  The name is needed to
        format the error message if it is read from before it is
        written to.

        The source of a placeholder object is that of the parent
        object until it is written.
    */
    std::string         m_placeholderName;

    Type                m_type;
    SimpleValue         m_simpleValue;
    mutable Data*       m_data;

    /** Called before every read operation to ensure that this object
        is not a placeholder.  */
    void beforeRead() const;

    /** Called before every write operation to wipe the placeholder
        status. */
    void beforeWrite();

    /** Decrements the reference count (if there is one).  If the
    reference count is zero after decrement, calls delete on @a m_data
    and sets it to NULL.
    */
    void dropReference();

    /** Allocate the Data object if it does not exist */
    void ensureData();

    /** If m_data is not NULL, ensure that it has a unique reference
        and contains a valid m_data.  This has a race condition if two
        threads are both trying to modify the same Any
        simultaneously.*/    
    void ensureMutable();

    /** Read an unnamed a TABLE or ARRAY.  Token should be the open
        paren token; it is the next token after the close on
        return. Called from deserialize().*/
    void deserializeBody(TextInput& ti, Token& token);

    void deserialize(TextInput& ti, Token& token);

    /** Read the name of a named Array or Table. */
    static void deserializeName(TextInput& ti, Token& token, std::string& name);
    
    /** Read until a comma is consumed or a close paren is hit, and
     return that token.  Considers the passed in token to be the first
     value read. */
    static void readUntilCommaOrClose(TextInput& ti, Token& token);

    /** Construct an Any that is a proxy for a table fetch from \a data.
     This proxy can be copied exactly once on return from operator[].*/
    Any(const std::string& key, Data* data);

    inline bool isPlaceholder() const {
        return ! m_placeholderName.empty();
    }

public:

    /** Base class for all Any exceptions.*/
    class Exception {
    public:
        virtual ~Exception() {}
    };

    /** Thrown by operator[] when a key is not present in a const table. */
    class KeyNotFound : public ParseError {
    public:
        std::string key;
    };

    /** Thrown by operator[] when an array index is not present. */
    class IndexOutOfBounds : public Exception {
    public:
        int     index;
        int     size;
        inline IndexOutOfBounds() : index(0), size(0) {}
        inline IndexOutOfBounds(int i, int s) : index(i), size(s) {}
    };

    /** NONE constructor */
    Any();

    /** Deserialize */
    explicit Any(TextInput& t);

    Any(const Any& x);

    /** NUMBER constructor */
    Any(double x);

#ifdef G3D_32BIT
    /** NUMBER constructor */
    Any(int64 x);
#endif    // G3D_32BIT

#if 0
    /** NUMBER constructor */
    Any(int32 x);
#endif    // 0

    /** NUMBER constructor */
    Any(long x);

    /** NUMBER constructor */
    Any(int x);

    /** NUMBER constructor */
    Any(short x);

    /** BOOLEAN constructor */
    Any(bool x);

    /** STRING constructor */
    Any(const std::string& x);

    /** STRING constructor */
    Any(const char* x);

    /** \a t must be ARRAY or TABLE */
    Any(Type t, const std::string& name = "");
    
    ~Any();

    /** Removes the comment and name */
    Any& operator=(const Any& x);

    /** Removes the comment and name */
    Any& operator=(double x);

    /** Removes the comment and name */
    Any& operator=(int x);

    /** Removes the comment and name */
    Any& operator=(bool x);

    /** Removes the comment and name */
    Any& operator=(const std::string& x);

    /** Removes the comment and name */
    Any& operator=(const char* x);

    /** \a t must be ARRAY, TABLE, or NONE. Removes the comment and name */
    Any& operator=(Type t);

    Type type() const;

    /** Same as deserialize or load, but operates on a string instead
        of a stream or file.

      \sa deserialize, load
      */
    void parse(const std::string& src);

    std::string unparse() const;
    
    /** Comments appear before values when they are in serialized form.*/
    const std::string& comment() const;
    void setComment(const std::string& c);

    /** True if this is the NONE value */
    bool isNone() const;

    /** Throws a ParseError exception if this is not a number */
    double number() const;
    const std::string& string() const;
    bool boolean() const;

    /** If this is named ARRAY or TABLE, returns the name. */
    const std::string& name() const;

    /** \brief Set the name used when serializing an ARRAY or TABLE.
    
       Only legal for ARRAY or TABLE.  The \a name must begin with a letter
       and contain only letters, numbers, underscores and scope operators.

        <pre>
        a2z
        hello
        Foo::bar
        color.red
        this->that
        __x
        </pre>
        
                
        The scope operators "::", "->", and
        ".", may have spaces around them.  The name may not
        contain parentheses.
    */
    void setName(const std::string& name);

    /** Number of elements if this is an ARRAY or TABLE */
    int size() const;
    int length() const;

    /** For an array, returns the ith element */
    const Any& operator[](int i) const;
    Any& operator[](int i);

    /** Directly exposes the underlying data structure for an ARRAY. */
    const Array<Any>& array() const;
    void append(const Any& v0);
    void append(const Any& v0, const Any& v1);
    void append(const Any& v0, const Any& v1, const Any& v2);
    void append(const Any& v0, const Any& v1, const Any& v2, const Any& v3);

    /** Directly exposes the underlying data structure for table.*/
    const Table<std::string, Any>& table() const;

    /** For a table, returns the element for \a key. Throws KeyNotFound
        exception if the element does not exist.
       */ 
    const Any& operator[](const std::string& key) const;

    // Needed to prevent the operator[](int) overload from catching
    // string literals
    inline const Any& operator[](const char* key) const {
        return operator[](std::string(key));
    }

    /** 
        Fetch an element from a table.  This can be used as:

        <pre>
        a["key"] = value;  (create the key if it did not exist)
        </pre>
        
        or

        <pre>
        value = a["key"];  (throw an error if the key did not exist)
        </pre>

        <b>Note:</b>
        In order to cause elements to be correctly created in the
        first case while still providing "key not found" errors in the
        second case, the Any returned is a special object that delays
        the actual fetch until the following assignment or method
        call.  This means that in the event of an error, the exception
        may be thrown from a line other than the actual fetch.  Use
        the Any::get() or the const Any::operator[]() methods to avoid
        this behavior and ensure error-checking at fetch time.
     */
    Any& operator[](const std::string& key);

    /** \copydoc Any::operator[](const std::string&) */
    inline Any& operator[](const char* key) {
        return operator[](std::string(key));
    }
    
    /** For a table, returns the element for key \a x and \a
        defaultVal if it does not exist. */
    const Any& get(const std::string& key, const Any& defaultVal) const;

    /** Returns true if this key is in the TABLE.  Illegal to call on an object that is not a TABLE. */
    bool containsKey(const std::string& key) const;
    
    /** For a table, assigns the element for key k. */
    void set(const std::string& key, const Any& val);

    /** for an ARRAY, resizes and returns the last element */
    Any& next();


    /** True if the Anys are exactly equal, ignoring comments.  Applies deeply on arrays and tables. */
    bool operator==(const Any& x) const;
    bool operator!=(const Any& x) const;

    operator int() const;
    operator float() const;
    operator double() const;
    operator bool() const;
    operator std::string() const;

    /** Resize to \a n elements, where new elements are NIL 
       It is an error to call this method if this is not an Any::ARRAY */
    void resize(int n);

    /** 
       Clears all entries.
       This must be a TABLE or ARRAY */
    void clear();

    /** Parse from a file.
     \sa deserialize, parse */
    void load(const std::string& filename);

    /** Uses the serialize method. */
    void save(const std::string& filename) const;

    void serialize(TextOutput& to) const;
    /** Parse from a stream.
     \sa load, parse */
    void deserialize(TextInput& ti);

    const Source& source() const;

    /** Throws a ParseError if \a value is false.  Useful for quickly
        creating parse rules in classes that deserialize from Any.
    */
    void verify(bool value, const std::string& message = "") const;

    /** Verifies that the name begins with identifier \a n.  It may contain
        identifier operators after this */
    void verifyName(const std::string& n) const;

    /** Verifies that the type is \a t. */
    void verifyType(Type t) const;

    /** Throws an exception if the type is not \a t0 or \a t1. */
    void verifyType(Type t0, Type t1) const;

    /** Verifies that the size is between \a low and \a high, inclusive */
    void verifySize(int low, int high) const;

    /** Verifies that the size is exactly \a s */
    void verifySize(int s) const;

private:

    void deserializeTable(TextInput& ti);
    void deserializeArray(TextInput& ti,const std::string& term);

};    // class Any

}    // namespace G3D

#endif
