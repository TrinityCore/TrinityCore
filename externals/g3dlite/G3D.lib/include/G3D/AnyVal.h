/**
 @file AnyVal.h
 @author Morgan McGuire
 @created 2006-06-11
 @edited  2008-07-14
 */

#ifndef G3D_ANYVAL_H
#define G3D_ANYVAL_H

#include "G3D/platform.h"
#include <string>
#include "G3D/Array.h"
#include "G3D/TextInput.h"

namespace G3D {
// Forward declarations for G3D types
class Vector2;
class Vector3;
class Vector4;
class Color1;
class Color3;
class Color4;
class Quat;
class Matrix2;
class Matrix3;
class Matrix4;
class CoordinateFrame;
class TextInput;
class TextOutput;
class BinaryInput;
class BinaryOutput;
class Rect2D;
class AABox;

/**
 A generic value, useful for defining property trees that can
 be loaded from and saved to disk.  The values are intentionally
 restricted to a small set.  

 When written to files, the syntax is as follows.  Note that you can
 nest arrays and tables in order to create full tree (i.e., XML-like)
 structures as configuration files:

 <table>
  <tr><td>NULL</td><td><code>Nil</code></td></tr>
  <tr><td>double</td><td><i>The number in printf double format</i></td></tr>
  <tr><td>bool</td><td><code>true</code> <i>or</i> <code>false</code></td></tr>
  <tr><td>std::string</td><td><i>The string in double-quotes (</i><code>"</code><i>)</i></td></tr>
  <tr><td>Rect2D</td><td><code>R(</code><i>x<sub>0</sub></i><code>,</code><i>y<sub>0</sub></i><code>,</code><i>x<sub>1</sub></i><code>,</code><i>y<sub>1</sub></i><code>)</code></td></tr>
  <tr><td>Color1</td><td><code>C1(</code><i>value</i><code>)</code></td></tr>
  <tr><td>Color3</td><td><code>C3(</code><i>r</i><code>,</code><i>g</i><code>,</code><i>b</i><code>)</code></td></tr>
  <tr><td>Color4</td><td><code>C4(</code><i>r</i><code>,</code><i>g</i><code>,</code><i>b</i><code>,</code><i>a</i><code>)</code></td></tr>
  <tr><td>Vector2</td><td><code>V2(</code><i>x</i><code>,</code><i>y</i><code>)</code></td></tr>
  <tr><td>Vector3</td><td><code>V3(</code><i>x</i><code>,</code><i>y</i><code>,</code><i>z</i><code>)</code></td></tr>
  <tr><td>Vector4</td><td><code>V4(</code><i>x</i><code>,</code><i>y</i><code>,</code><i>z</i><code>,</code><i>w</i><code>)</code></td></tr>
  <tr><td>Quat</td><td><code>V(</code>x<code>,</code>y<code>,</code>z<code>,</code>w<code>)</code></td></tr>
  <tr><td>AABox</td><td><code>AAB(</code>low Vector3<code>, </code>high Vector3<code>)</code></td></tr>
  <tr><td>Matrix2</td><td><code>M2(</code>r0c0<code>, </code>r0c1<code>,
                             <br>&nbsp;&nbsp;&nbsp;</code>r1c0<code>, </code>r1c1<code>)</code></td></tr>
  <tr><td>Matrix3</td><td><code>M3(</code>r0c0<code>, </code>r0c1<code>, </code>r0c2<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r1c0<code>, </code>r1c1<code>, </code>r1c2<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r2c0<code>, </code>r2c1<code>, </code>r2c2<code>)</code></td></tr>
  <tr><td>Matrix4</td><td><code>M4(</code>r0c0<code>, </code>r0c1<code>, </code>r0c2<code>, </code>r0c3<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r1c0<code>, </code>r1c1<code>, </code>r1c2<code>, </code>r1c3<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r2c0<code>, </code>r2c1<code>, </code>r2c2<code>, </code>r2c3<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r3c0<code>, </code>r3c1<code>, </code>r3c2<code>, </code>r3c3<code>)</code></td></tr>
  <tr><td>CoordinateFrame</td><td><code>CF(</code>r0c0<code>, </code>r0c1<code>, </code>r0c2<code>,   </code>r0c3<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r1c0<code>, </code>r1c1<code>, </code>r1c2<code>,   </code>r1c3<code>,
         <br>&nbsp;&nbsp;&nbsp;</code>r2c0<code>, </code>r2c1<code>, </code>r2c2<code>,   </code>r2c3<code>)</code></td></tr>
  <tr><td>CoordinateFrame</td><td><code>CF(V3(</code><i>x</i><code>, </code><i>y</i><code>, </code><i>z</i><code>), </code><i>yaw deg</i><code>, </code><i>pitch deg</i><code>, </code><i>optional roll deg</i><code>)</code></td></tr>

  <tr><td>Array</td><td><code>[</code><i>element<sub>0</sub></i><code>, </code><i>element<sub>1</sub></i><code>, </code> ... <code>, </code><i>element<sub>n-1</sub></i><code>]</code></td></tr>
  <tr><td>Table</td><td><code>{</code><i>symbol<sub>0</sub></i><code> = </code><i>value<sub>0</sub></i>
                               <br><code>&nbsp;</code><i>symbol<sub>1</sub></i><code> = </code><i>value<sub>1</sub></i>  
                               <br><code>&nbsp;</code>...
                               <br><code>&nbsp;</code><i>symbol<sub>n-1</sub></i><code> = </code><i>value<sub>n-1</sub></i><code>}</code></td></tr>
  </table>

 See also boost::any for a more general purpose but slightly harder to use
 "any" for C++.

 The semantics of operator[] and the get() methods are slightly different;
 operator[] acts more like a scripting language that automatically extends
 arrays and tables instead of generating errors.  get() has more strict semantics,
 like a C++ class.

 AnyVal uses copy-on-mutate, so that <code>AnyVal a = b</code> semantically copies <code>b</code> (like <code>int a = b</code> would), although in practice
 it delays the copy until one is mutated so that it is still fast to "copy" large arrays and tables.

 Reading example:
 <pre>
    AnyVal property = AnyVal::fromFile("c:/tmp/test.txt"));

    Vector3 vel = property["angular velocity"]

    <i>Using defaults to handle errors:
       If there was no "enabled" value, this will return the default instead of failing</i>
    bool enabled = property["enabled"].boolean(true);

 </pre>

 Writing to a file:
 <pre>
    AnyVal dict(AnyVal::TABLE);

    dict["enabled"] = AnyVal(true);
    dict["weight"] = 100;
    dict["angular velocity"] = Vector3(1, -3, 4.5);

    TextOutput t("c:/tmp/test.txt");
    dict.serialize(t);
    t.commit();
  </pre>

  Example of a data file:
  <pre>
   {
      heights = [1, 17, 32]
      model = 
        {
           color = C3(1, 1, 1)
           filename = "foo.md2"
        }
      position = V3(23, 14, 0)
      name = "Elmer"
   }
  </pre>

  <p>
  <b>What's the difference from boost::any?</b>
  <br>I think that AnyVal will be easier for novice C++ users.  It addresses the problem that
   even though G3D::TextInput makes reading configuration files extremely simple, many people
   still don't use it.  So AnyVal makes it ridiculously simple to read and write a tree of G3D 
   types to a file. 

   <i>AnyVal:</i>
<pre>
{
AnyVal tree(TextInput("config.txt"));

bool enabled = tree.get("enabled", false);
Vector3 direction = tree.get("direction", Vector3::zero());
...
}
</pre>

<i>boost:</i>
<pre>
{
bool enabled = false;
Vector3 direction;
Table<boost::any> tree;

 ...write lots of file parsing code...

   if (tree.containsKey("enabled")) {
      const boost::any& val = tree["enabled"];
      try {
        enabled = any_cast<bool>(val);
      } catch(const boost::bad_any_cast &) {
      }
    }

   if (tree.containsKey("direction")) {
      const boost::any& val = tree["direction"];
      try {
        direction = any_cast<Vector3>(val);
      } catch(const boost::bad_any_cast &) {
      }
    }
   ...
}
</pre>
 */
class AnyVal {
public:

    /** Array and table values are all Any.*/
    enum Type {
        NIL, 
        NUMBER,
        BOOLEAN, 
        STRING, 
        VECTOR2, 
        VECTOR3, 
        VECTOR4, 
        MATRIX2,
        MATRIX3, 
        MATRIX4, 
        QUAT, 
        COORDINATEFRAME,
        COORDINATEFRAME2D,
        CFRAME = COORDINATEFRAME,
        CFRAME2D = COORDINATEFRAME2D,
        COLOR1,
        COLOR3,
        COLOR4,
        RECT2D,
        AABOX2D = RECT2D,
        AABOX,
        ARRAY, 
        TABLE};

    /** Base class for all AnyVal exceptions.*/
    class Exception {
    public:
        virtual ~Exception() {}
    };

    /** Thrown when an inappropriate operation is performed (e.g., operator[] on a number) */
    class WrongType : public Exception {
    public:
        Type        expected;
        Type        actual;
        WrongType() : expected(NIL), actual(NIL) {}
        WrongType(Type e, Type a) : expected(e), actual(a) {}
    };

    /** Thrown by operator[] when a key is not present. */
    class KeyNotFound : public Exception {
    public:
        std::string key;
        KeyNotFound() {}
        KeyNotFound(const std::string& k) : key(k) {}
    };

    class IndexOutOfBounds : public Exception {
    public:
        int     index;
        int     size;
        IndexOutOfBounds() : index(0), size(0) {}
        IndexOutOfBounds(int i, int s) : index(i), size(s) {}
    };

    /** Thrown when deserialize() when the input is incorrectly formatted. */
    class CorruptText : public Exception {
    public:
        std::string      message;

        /** Token where the problem occurred.*/
        G3D::Token       token;

        CorruptText() {}
        CorruptText(const std::string& s, const G3D::Token& t) : message(s), token(t) {}
    };

private:

    Type        m_type;
    void*       m_value;

    /** For table and array types, *m_value is shared between multiple
        instances.  Mutation is allowed only if the reference count is
        exactly 1, otherwise the mutating instance must copy the
        value.  This is not used for other types.
        */
    int*        m_referenceCount;

    /** Decrements the reference count (if there is one).  If the
    reference count is zero or does not exist.  Calls delete on @a
    m_value and sets it to NULL.
    */
    void deleteValue();

    /** Returns a copy of the value. */
    void* copyValue() const;

    /** Assumes isSharedType.  Ensures that this has a unique reference */
    void makeMutable();

    /** True if this is a shared value between multiple instances. */
    inline bool isShared() const {
        return m_referenceCount && (*m_referenceCount > 1);
    }

    /** True when m_value is a double pointer */
    inline bool isSharedType() const {
        return (m_type == TABLE) || (m_type == ARRAY);
    }

public:

    AnyVal();

    /** Deserialize */
    explicit AnyVal(G3D::TextInput& t);

    static AnyVal fromFile(const std::string& filename);

    void load(const std::string& filename);

    void save(const std::string& filename) const;

    ///** Deserialize */
    //explicit AnyVal(G3D::BinaryInput& t);

    /** Construct a number */
    AnyVal(double);
    AnyVal(int);

    // Explicit to avoid ambiguity with the 'double' constructor
    // when an integer type is constructed
    AnyVal(bool);
    AnyVal(const G3D::Vector2&);
    AnyVal(const G3D::Vector3&);
    AnyVal(const G3D::Vector4&);

    AnyVal(const G3D::Color1&);
    AnyVal(const G3D::Color3&);
    AnyVal(const G3D::Color4&);

    AnyVal(const std::string&);
    AnyVal(const char*);

    AnyVal(const G3D::Quat&);

    AnyVal(const G3D::Rect2D&);
    AnyVal(const G3D::AABox&);

    AnyVal(const G3D::CoordinateFrame&);
    AnyVal(const G3D::Matrix2&);
    AnyVal(const G3D::Matrix3&);
    AnyVal(const G3D::Matrix4&);

    AnyVal(const AnyVal&);

    AnyVal(Type arrayOrTable);

    AnyVal& operator=(const AnyVal&);

    /** Frees the underlying storage */
    ~AnyVal();

    Type type() const;

    bool isNil() const {
        return type() == NIL;
    }

    void serialize(G3D::TextOutput& t) const;
    //void serialize(G3D::BinaryOutput& t) const;
    void deserialize(G3D::TextInput& t);
    //void deserialize(G3D::BinaryInput& t);

    /** Array dereference.  If the index is out of bounds, IndexOutOfBounds is thrown */
    const AnyVal& operator[](int) const;

    /** Extend this array by one element. */
    void append(const AnyVal&);

    /** If the index is out of bounds, the array is resized.  If the index is negative,
        IndexOutOfBounds is thrown.*/
    AnyVal& operator[](int);

    /** If @a i is out of bounds or this is not an ARRAY, defaultVal is returned.*/
    const AnyVal& get(int i, const AnyVal& defaultVal) const;

    /** If out of bounds, IndexOutOfBounds is thrown. */
    const AnyVal& get(int i) const;

    /** Returns defaultVal if this is not a TABLE or the key is not found. */
    const AnyVal& get(const std::string& key, const AnyVal& defaultVal) const;

    /** Throws KeyNotFound exception if the key is not present.*/
    const AnyVal& get(const std::string& key) const;

    /** Table reference */
    const AnyVal& operator[](const std::string&) const;

    /** Table reference.  If the element does not exist, it is created. */
    AnyVal& operator[](const std::string&);

    /** Table reference */
    const AnyVal& operator[](const char*) const;

    /** Table reference.  If the element does not exist, it is created. */
    AnyVal& operator[](const char*);

    /** If this value is not a number throws a WrongType exception. */
    double number() const;

    /** If this value is not a number, returns defaultVal. */
    double number(double defaultVal) const;

    operator double () const {
        return number();
    }

    operator float () const {
        return (float)number();
    }

    bool boolean() const;
    bool boolean(bool b) const;

    operator bool() const {
        return boolean();
    }

    const std::string& string() const;
    const std::string& string(const std::string& defaultVal) const;

    operator const std::string& () const {
        return string();
    }

    const G3D::Rect2D& rect2D() const;
    const G3D::Rect2D& rect2D(const G3D::Rect2D& defaultVal) const;

    operator const Rect2D& () const {
        return rect2D();
    }

    const G3D::AABox& aabox() const;
    const G3D::AABox& aabox(const G3D::AABox& defaultVal) const;

    operator const AABox& () const {
        return aabox();
    }

    const G3D::Vector2& vector2() const;
    const G3D::Vector2& vector2(const G3D::Vector2& defaultVal) const;

    operator const Vector2& () const {
        return vector2();
    }

    const G3D::Vector3& vector3() const;
    const G3D::Vector3& vector3(const G3D::Vector3& defaultVal) const;
    
    operator const Vector3& () {
        return vector3();
    }

    const G3D::Vector4& vector4() const;
    const G3D::Vector4& vector4(const G3D::Vector4& defaultVal) const;

    operator const Vector4& () const {
        return vector4();
    }

    const G3D::Color1& color1() const;
    const G3D::Color1& color1(const G3D::Color1& defaultVal) const;

    const G3D::Color3& color3() const;
    const G3D::Color3& color3(const G3D::Color3& defaultVal) const;

    operator const Color3& () const {
        return color3();
    }

    const G3D::Color4& color4() const;
    const G3D::Color4& color4(const G3D::Color4& defaultVal) const;

    operator const Color4& () const {
        return color4();
    }

    const G3D::CoordinateFrame& coordinateFrame() const;
    const G3D::CoordinateFrame& coordinateFrame(const G3D::CoordinateFrame& defaultVal) const;

    operator const CoordinateFrame& () const {
        return coordinateFrame();
    }

    const G3D::Matrix2& matrix2() const;
    const G3D::Matrix2& matrix2(const G3D::Matrix2& defaultVal) const;

    operator const Matrix2& () const {
        return matrix2();
    }

    const G3D::Matrix3& matrix3() const;
    const G3D::Matrix3& matrix3(const G3D::Matrix3& defaultVal) const;

    operator const Matrix3& () const {
        return matrix3();
    }

    const G3D::Matrix4& matrix4() const;
    const G3D::Matrix4& matrix4(const G3D::Matrix4& defaultVal) const;

    operator const Matrix4& () const {
        return matrix4();
    }

    const G3D::Quat& quat() const;
    const G3D::Quat& quat(const G3D::Quat& defaultVal) const;

    operator const Quat& () const {
        return quat();
    }

    std::string toString() const;

    /** Number of elements for an array or table.*/
    int size() const;

    /** For a table, returns the keys. */
    void getKeys(G3D::Array<std::string>&) const;
};

}

#endif
