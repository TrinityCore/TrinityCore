/** 
 @file AnyVal.cpp
 @author Morgan McGuire
 @maintainer Morgan McGuire
 @created 2006-06-11
 @edited  2008-07-14
 */

#include "G3D/AnyVal.h"
#include "G3D/Array.h"
#include "G3D/stringutils.h"
#include "G3D/Table.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/Color1.h"
#include "G3D/Color3.h"
#include "G3D/Color4.h"
#include "G3D/Matrix2.h"
#include "G3D/Matrix3.h"
#include "G3D/Matrix4.h"
#include "G3D/Rect2D.h"
#include "G3D/AABox.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Quat.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

AnyVal AnyVal::fromFile(const std::string& filename) {
    TextInput t(filename);
    return AnyVal(t);
}


void AnyVal::load(const std::string& filename) {
    *this = fromFile(filename);
}


void AnyVal::save(const std::string& filename) const {
    TextOutput t(filename);
    serialize(t);
    t.commit();
}


AnyVal::AnyVal() : m_type(NIL), m_value(NULL), m_referenceCount(NULL) {
}


AnyVal::AnyVal(bool b) : m_type(BOOLEAN), m_value(new bool(b)), m_referenceCount(NULL) {
}


AnyVal::AnyVal(G3D::TextInput& t) : m_type(NIL), m_value(NULL), m_referenceCount(NULL) {
    deserialize(t);
}


/*AnyVal::AnyVal(G3D::BinaryInput& b) {
    deserialize(b);
}
*/

AnyVal::AnyVal(double v) : m_type(NUMBER), m_referenceCount(NULL) {
    m_value = new double(v);
}


AnyVal::AnyVal(int v) : m_type(NUMBER), m_referenceCount(NULL) {
    m_value = new double(v);
}


AnyVal::AnyVal(const Rect2D& v) : m_type(RECT2D), m_referenceCount(NULL) {
    m_value = new Rect2D(v);
}


AnyVal::AnyVal(const AABox& v) : m_type(AABOX), m_referenceCount(NULL) {
    m_value = new AABox(v);
}


AnyVal::AnyVal(const Vector2& v) : m_type(VECTOR2), m_referenceCount(NULL) {
    m_value = new Vector2(v);
}


AnyVal::AnyVal(const Vector3& v) : m_type(VECTOR3), m_referenceCount(NULL) {
    m_value = new Vector3(v);
}


AnyVal::AnyVal(const Vector4& v) : m_type(VECTOR4), m_referenceCount(NULL) {
    m_value = new Vector4(v);
}


AnyVal::AnyVal(const Color1& v) : m_type(COLOR1), m_referenceCount(NULL) {
    m_value = new Color1(v);
}


AnyVal::AnyVal(const Color3& v) : m_type(COLOR3), m_referenceCount(NULL) {
    m_value = new Color3(v);
}


AnyVal::AnyVal(const Color4& v) : m_type(COLOR4), m_referenceCount(NULL) {
    m_value = new Color4(v);
}


AnyVal::AnyVal(const std::string& v) : m_type(STRING), m_referenceCount(NULL) {
    m_value = new std::string(v);
}


AnyVal::AnyVal(const char* v) : m_type(STRING), m_referenceCount(NULL) {
    m_value = new std::string(v);
}


AnyVal::AnyVal(const Quat& v) : m_type(QUAT), m_referenceCount(NULL) {
    m_value = new Quat(v);
}


AnyVal::AnyVal(const CoordinateFrame& v) : m_type(COORDINATEFRAME), m_referenceCount(NULL) {
    m_value = new CoordinateFrame(v);
}


AnyVal::AnyVal(const Matrix2& v) : m_type(MATRIX2), m_referenceCount(NULL) {
    m_value = new Matrix2(v);
}

AnyVal::AnyVal(const Matrix3& v) : m_type(MATRIX3), m_referenceCount(NULL) {
    m_value = new Matrix3(v);
}


AnyVal::AnyVal(const Matrix4& v) : m_type(MATRIX4), m_referenceCount(NULL) {
    m_value = new Matrix4(v);
}


AnyVal::AnyVal(const AnyVal& c) : m_type(NIL), m_value(NULL), m_referenceCount(NULL) {
    *this = c;
}


AnyVal::AnyVal(Type arrayOrTable) : m_type(NIL), m_value(NULL), m_referenceCount(new int(1)) {
    // TODO: make AnyVal::createArray()
    switch (arrayOrTable) {
    case ARRAY:
        m_type = ARRAY;
        m_value = new Array<AnyVal>();
        break;

    case TABLE:
        m_type = TABLE;
        m_value = new Table<std::string, AnyVal>();
        break;

    default:
        debugAssertM(false, "Cannot construct AnyVal from constants except ARRAY or TABLE.");
    }
}


AnyVal::~AnyVal() {
    deleteValue();
}


void AnyVal::deleteValue() {
    if (m_referenceCount) {
        --(*m_referenceCount);
        if (*m_referenceCount <= 0) {
            delete m_referenceCount;
            m_referenceCount = NULL;
            // Pass through and delete the real object now
        } else {
            // Someone else is holding a reference, so we can't delete 
            // the object.
            m_referenceCount = NULL;
            return;
        }
    }

    switch (m_type) {
    case NIL:
        // Nothing to do
        break;

    case NUMBER:
        delete (double*)m_value;
        break;

    case BOOLEAN:
        delete (bool*)m_value;
        break;

    case STRING:
        delete (std::string*)m_value;
        break;
        
    case RECT2D:
        delete (Rect2D*)m_value;
        break;

    case AABOX:
        delete (AABox*)m_value;
        break;

    case VECTOR2:
        delete (Vector2*)m_value;
        break;

    case VECTOR3:
        delete (Vector3*)m_value;
        break;

    case VECTOR4:
        delete (Vector4*)m_value;
        break;

    case MATRIX2:
        delete (Matrix2*)m_value;
        break;

    case MATRIX3:
        delete (Matrix3*)m_value;
        break;

    case MATRIX4:
        delete (Matrix4*)m_value;
        break;

    case QUAT:
        delete (Quat*)m_value;
        break;

    case COORDINATEFRAME:
        delete (CoordinateFrame*)m_value;
        break;

    case COLOR1:
        delete (Color1*)m_value;
        break;

    case COLOR3:
        delete (Color3*)m_value;
        break;

    case COLOR4:
        delete (Color4*)m_value;
        break;

    case ARRAY:
        delete (Array<AnyVal>*)m_value;
        break;

    case TABLE:
        delete (Table<std::string, AnyVal>*)m_value;
        break;

    default:
        debugAssertM(false, "Internal error: no destructor for this type.");
    } 
   
    m_value = NULL;
}


AnyVal& AnyVal::operator=(const AnyVal& v) {
    deleteValue();

    m_type = v.m_type;

    m_referenceCount = v.m_referenceCount;
    
    if (isSharedType()) {
        ++(*m_referenceCount);
        m_value = v.m_value;
    } else {
        m_value = v.copyValue();
    }

    return *this;
}


void* AnyVal::copyValue() const {
  switch (m_type) {
    case NIL:
        return NULL;

    case NUMBER:
        return new double(*(double*)m_value);

    case BOOLEAN:
        return new bool(*(bool*)m_value);

    case STRING:
        return new std::string(*(std::string*)m_value);
        
    case RECT2D:
        return new Rect2D(*(Rect2D*)m_value);

    case AABOX:
        return new AABox(*(AABox*)m_value);

    case VECTOR2:
        return new Vector2(*(Vector2*)m_value);

    case VECTOR3:
        return new Vector3(*(Vector3*)m_value);

    case VECTOR4:
        return new Vector4(*(Vector4*)m_value);

    case MATRIX2:
        return new Matrix2(*(Matrix2*)m_value);

    case MATRIX3:
        return new Matrix3(*(Matrix3*)m_value);

    case MATRIX4:
        return new Matrix4(*(Matrix4*)m_value);

    case QUAT:
        return new Quat(*(Quat*)m_value);

    case COORDINATEFRAME:
        return new CoordinateFrame(*(CoordinateFrame*)m_value);

    case COLOR1:
        return new Color1(*(Color1*)m_value);

    case COLOR3:
        return new Color3(*(Color3*)m_value);

    case COLOR4:
        return new Color4(*(Color4*)m_value);

    case ARRAY:
        return new Array<AnyVal>(*(Array<AnyVal>*)m_value);

    case TABLE:
        return new Table<std::string, AnyVal>(*(Table<std::string, AnyVal>*)m_value);

    default:
        debugAssertM(false, "Internal error: no assignment operator for this type.");
        return NULL;
    }
}

AnyVal::Type AnyVal::type() const {
    return m_type;
}


static bool legalIdentifier(const std::string& s) {
    if (s.size() == 0) {
        return false;
    }

    if (! isLetter(s[0]) || (s[0] == '_')) {
        return false;
    }

    bool ok = true;    

    for (unsigned int i = 1; i < s.size(); ++i) {
        ok &= isDigit(s[i]) || isLetter(s[i]) || (s[i] == '_');
    }
   
    return ok;
}


void AnyVal::serialize(G3D::TextOutput& t) const {
    switch (m_type) {
    case NIL:
        t.writeSymbol("Nil");
        break;

    case NUMBER:
        t.printf("%g", *(double*)m_value);
        break;

    case BOOLEAN:
        t.writeBoolean(*(bool*)m_value);
        break;

    case STRING:
        t.writeString(*(std::string*)m_value);
        break;
        
    case RECT2D:
        t.printf("R(%g, %g, %g, %g)", ((Rect2D*)m_value)->x0(), ((Rect2D*)m_value)->y0(),
                 ((Rect2D*)m_value)->width(), ((Rect2D*)m_value)->height());
        break;

    case AABOX:
        t.printf("AAB(V3(%g, %g, %g), V3(%g, %g, %g))", 
                 aabox().low().x,
                 aabox().low().y,
                 aabox().low().z,
                 aabox().high().x,
                 aabox().high().y,
                 aabox().high().z);
        break;

    case VECTOR2:
        t.printf("V2(%g, %g)", ((Vector2*)m_value)->x, ((Vector2*)m_value)->y);
        break;

    case VECTOR3:
        t.printf("V3(%g, %g, %g)", ((Vector3*)m_value)->x, ((Vector3*)m_value)->y, ((Vector3*)m_value)->z);
        break;

    case VECTOR4:
        t.printf("V4(%g, %g, %g, %g)", ((Vector4*)m_value)->x, ((Vector4*)m_value)->y, ((Vector4*)m_value)->z, ((Vector4*)m_value)->w);
        break;

    case MATRIX2:
        {
            const Matrix2& m = *(Matrix2*)m_value;
            t.printf("M2(\n");
            t.pushIndent();
            t.printf("%10.5f, %10.5f,\n%10.5f, %10.5f)",
                     m[0][0], m[0][1],
                     m[1][0], m[1][1]);
            t.popIndent();
        }
        break;

    case MATRIX3:
        {
            const Matrix3& m = *(Matrix3*)m_value;
            t.printf("M3(\n");
            t.pushIndent();
            t.printf("%10.5f, %10.5f, %10.5f,\n%10.5f, %10.5f, %10.5f,\n%10.5f, %10.5f, %10.5f)",
                m[0][0], m[0][1], m[0][2],
                m[1][0], m[1][1], m[1][2],
                m[2][0], m[2][1], m[2][2]);
            t.popIndent();
        }
        break;

    case MATRIX4:
        {
            const Matrix4& m = *(Matrix4*)m_value;
            t.printf("M4(\n");
            t.pushIndent();
            t.printf(
                "%10.5f, %10.5f, %10.5f, %10.5f,\n"
                "%10.5f, %10.5f, %10.5f, %10.5f,\n"
                "%10.5f, %10.5f, %10.5f, %10.5f,\n"
                "%10.5f, %10.5f, %10.5f, %10.5f)",
                m[0][0], m[0][1], m[0][2], m[0][3],
                m[1][0], m[1][1], m[1][2], m[1][3],
                m[2][0], m[2][1], m[2][2], m[2][3],
                m[3][0], m[3][1], m[3][2], m[3][3]);
            t.popIndent();
        }
        break;

    case QUAT:
        t.printf("Q(%g, %g, %g, %g)", ((Quat*)m_value)->x, ((Quat*)m_value)->y, ((Quat*)m_value)->z, ((Quat*)m_value)->w);
        break;

    case COORDINATEFRAME:
        {
            const CoordinateFrame& c = *(CoordinateFrame*)m_value;
            float x,y,z,yaw,pitch,roll;
            c.getXYZYPRDegrees(x,y,z,yaw,pitch,roll);
            t.printf("CF(V3(%g,%g,%g), %g, %g, %g)", x, y, z, yaw, pitch, roll);
            /*
            t.pushIndent();
            t.printf(
                "CF(\n%10.5f, %10.5f, %10.5f,   %10.5f,\n"
                "%10.5f, %10.5f, %10.5f,   %10.5f,\n"
                "%10.5f, %10.5f, %10.5f,   %10.5f)",
                c.rotation[0][0], c.rotation[0][1], c.rotation[0][2], c.translation.x,
                c.rotation[1][0], c.rotation[1][1], c.rotation[1][2], c.translation.y,
                c.rotation[2][0], c.rotation[2][1], c.rotation[2][2], c.translation.z);
            t.popIndent();
            */
        }
        break;

    case COLOR1:
        t.printf("C1(%g)", ((Color1*)m_value)->value);
        break;

    case COLOR3:
        t.printf("C3(%g, %g, %g)", ((Color3*)m_value)->r, ((Color3*)m_value)->g, ((Color3*)m_value)->b);
        break;

    case COLOR4:
        t.printf("C4(%g, %g, %g, %g)", ((Color4*)m_value)->r, ((Color4*)m_value)->g, ((Color4*)m_value)->b, ((Color4*)m_value)->a);
        break;

    case ARRAY:
        {
            const Array<AnyVal>& a = *(Array<AnyVal>*)m_value;
            t.printf("[\n");
            t.pushIndent();
                for (int i = 0; i < a.size(); ++i) {
                    a[i].serialize(t);
                    if (i != a.size() - 1) {
                        t.printf(", \n");
                    }
                }
            t.printf("]");
            t.popIndent();
        }
        break;

    case TABLE:
        {
            const Table<std::string, AnyVal>& a = *(Table<std::string, AnyVal>*)m_value;
            t.printf("{\n");
            t.pushIndent();
                Table<std::string, AnyVal>::Iterator i = a.begin();
                const Table<std::string, AnyVal>::Iterator end = a.end();
                while (i != end) {
                    // Quote names that are not legal C++ identifiers
                    if (! legalIdentifier(i->key)) {
                        t.printf("'%s' ", i->key.c_str());
                    } else {
                        t.writeSymbol(i->key);
                    }
                    t.printf("= ");
                    
                    i->value.serialize(t);

                    if (i != end) {
                        t.printf("\n");
                    }
                    ++i;
                }
            t.popIndent();
            t.printf("}");
        }
        break;

    default:
        debugAssertM(false, "Internal error: no serialize method for this type.");
    }
}


std::string AnyVal::toString() const {
    TextOutput t;
    serialize(t);
    std::string s;
    t.commitString(s);
    return s;
}

void AnyVal::deserialize(G3D::TextInput& t) {
    deleteValue();
    m_type = NIL;
    m_value = NULL;

    if (! t.hasMore()) {
        return;
    }

    switch (t.peek().type()) {
    case Token::END:
        // should never get here because of the hasMore check above
        return;
        break;

    case Token::NUMBER:
        m_type = NUMBER;
        m_value = new double(t.readNumber());
        break;

    case Token::STRING:
        m_type = STRING;
        m_value = new std::string(t.readString());
        break;

    case Token::NEWLINE:
        m_type = STRING;
        m_value = new std::string(t.readNewline());
        break;

    case Token::COMMENT:
        m_type = STRING;
        m_value = new std::string(t.readComment());
        break;

    case Token::BOOLEAN:
        m_type = BOOLEAN;
        m_value = new bool(t.readBoolean());
        break;

    case Token::SYMBOL:
        {
            std::string s = t.readSymbol();
            if (s == "NIL") {
                break;

            } else if (s == "true") {
                
                m_type = BOOLEAN;
                m_value = new bool(true);

            } else if (s == "false") {
                
                m_type = BOOLEAN;
                m_value = new bool(false);

            } else if (s == "R") {
                
                m_type = RECT2D;
                t.readSymbol("(");
                float x,y,w,h;
                x = (float)t.readNumber();
                t.readSymbol(",");
                y = (float)t.readNumber();
                t.readSymbol(",");
                w = (float)t.readNumber();
                t.readSymbol(",");
                h = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Rect2D(Rect2D::xywh(x, y, w, h));

            } else if (s == "AAB") {

                m_type = AABOX;
                Vector3 v[2];
                t.readSymbol("(");
                for (int i = 0; i < 2; ++i) {
                    t.readSymbols("V3", "(");
                    v[i].x = (float)t.readNumber();
                    t.readSymbol(",");
                    v[i].y = (float)t.readNumber();
                    t.readSymbol(",");
                    v[i].z = (float)t.readNumber();
                    t.readSymbol(",");
                    if (i == 0) {
                        t.readSymbol(",");
                    }
                }
                t.readSymbol(")");
                m_value = new AABox(v[0], v[1]);

            } else if (s == "V2") {

                t.readSymbol("(");
                Vector2 v; 
                v.x = (float)t.readNumber();
                t.readSymbol(",");
                v.y = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Vector2(v);
                m_type = VECTOR2;

            } else if (s == "V3") {

                t.readSymbol("(");
                Vector3 v; 
                v.x = (float)t.readNumber();
                t.readSymbol(",");
                v.y = (float)t.readNumber();
                t.readSymbol(",");
                v.z = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Vector3(v);
                m_type = VECTOR3;

            } else if (s == "V4") {

                t.readSymbol("(");
                Vector4 v; 
                v.x = (float)t.readNumber();
                t.readSymbol(",");
                v.y = (float)t.readNumber();
                t.readSymbol(",");
                v.z = (float)t.readNumber();
                t.readSymbol(",");
                v.w = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Vector4(v);
                m_type = VECTOR4;

            } else if (s == "M2") {

                t.readSymbol("(");
                Matrix2 m;
                for (int r = 0; r < 2; ++r) {
                    for (int c = 0; c < 2; ++c) {
                        m[r][c] = (float)t.readNumber();
                        if ((c != 1) || (r != 1)) {
                            t.readSymbol(",");
                        }
                    }
                }
                t.readSymbol(")");
                m_value = new Matrix2(m);
                m_type = MATRIX2;

            } else if (s == "M3") {

                t.readSymbol("(");
                Matrix3 m;
                for (int r = 0; r < 3; ++r) {
                    for (int c = 0; c < 3; ++c) {
                        m[r][c] = (float)t.readNumber();
                        if ((c != 2) || (r != 2)) {
                            t.readSymbol(",");
                        }
                    }
                }
                t.readSymbol(")");
                m_value = new Matrix3(m);
                m_type = MATRIX3;

            } else if (s == "M4") {

                t.readSymbol("(");
                Matrix4 m;
                for (int r = 0; r < 4; ++r) {
                    for (int c = 0; c < 4; ++c) {
                        m[r][c] = (float)t.readNumber();
                        if ((c != 3) || (r != 3)) {
                            t.readSymbol(",");
                        }
                    }
                }
                t.readSymbol(")");
                m_value = new Matrix4(m);
                m_type = MATRIX4;

            } else if (s == "Q") {

                t.readSymbol("(");
                Quat q;
                q.x = (float)t.readNumber();
                t.readSymbol(",");
                q.y = (float)t.readNumber();
                t.readSymbol(",");
                q.z = (float)t.readNumber();
                t.readSymbol(",");
                q.w = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Quat(q);
                m_type = QUAT;

            } else if (s == "CF") {

                t.readSymbol("(");
                CoordinateFrame m;
                if (t.peek().type() == Token::SYMBOL) {
                    // Angle format
                    float x, y, z, yaw, roll, pitch;
                    t.readSymbols("V3", "(");
                    x = (float)t.readNumber();
                    t.readSymbol(",");
                    y = (float)t.readNumber();
                    t.readSymbol(",");
                    z = (float)t.readNumber();
                    t.readSymbols(")", ",");
                    yaw = (float)t.readNumber();
                    t.readSymbol(",");
                    pitch = (float)t.readNumber();
                    roll = 0;
                    if (t.peek().string() == ",") {
                        t.readSymbol(",");
                        roll = (float)t.readNumber();
                    }                        
                    m = CoordinateFrame::fromXYZYPRDegrees(x, y, z, yaw, pitch, roll);
                } else {
                    // Matrix format
                    for (int r = 0; r < 3; ++r) {
                        for (int c = 0; c < 3; ++c) {
                            m.rotation[r][c] = (float)t.readNumber();
                        }
                        m.translation[r] = (float)t.readNumber();
                        if (r != 2) {
                            t.readSymbol(",");
                        }
                    }
                }
                t.readSymbol(")");
                m_value = new CoordinateFrame(m);
                m_type = COORDINATEFRAME;

            } else if (s == "C1") {

                t.readSymbol("(");
                float v = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Color1(v);
                m_type = COLOR1;

            } else if (s == "C3") {

                t.readSymbol("(");
                Color3 c;
                c.r = (float)t.readNumber();
                t.readSymbol(",");
                c.g = (float)t.readNumber();
                t.readSymbol(",");
                c.b = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Color3(c);
                m_type = COLOR3;

            } else if (s == "C4") {

                t.readSymbol("(");
                Color4 c;
                c.r = (float)t.readNumber();
                t.readSymbol(",");
                c.g = (float)t.readNumber();
                t.readSymbol(",");
                c.b = (float)t.readNumber();
                t.readSymbol(",");
                c.a = (float)t.readNumber();
                t.readSymbol(")");
                m_value = new Color4(c);
                m_type = COLOR4;

            } else if (s == "[") {

                // Array
                m_type = ARRAY;
                m_value = new Array<AnyVal>();
                m_referenceCount = new int(1);
                Array<AnyVal>& a = *(Array<AnyVal>*)m_value;

                Token peek = t.peek();
                while ((peek.type() != Token::SYMBOL) || (peek.string() != "]")) {
                    // Avoid copying large objects
                    a.next().deserialize(t);

                    peek = t.peek();
                    if (peek.type() != Token::SYMBOL) {
                        throw CorruptText("Expected ',' or ']'", peek);
                    } else if (peek.string() == ",") {
                        t.readSymbol(",");
                    } else if (peek.string() != "]") {
                        throw CorruptText("Missing ']'", peek);
                    }
                }
                t.readSymbol("]");

            } else if (s == "{") {

                // Table
                m_type = TABLE;
                m_value = new Table<std::string, AnyVal>();
                m_referenceCount = new int(1);
                Table<std::string, AnyVal>& a = *(Table<std::string, AnyVal>*)m_value;

                Token peek = t.peek();
                while ((peek.type() != Token::SYMBOL) || (peek.string() != "}")) {

                    std::string key;
                    // Get the name
                    if (peek.type() == Token::SYMBOL) {
                        key = t.readSymbol();
                    } else if (peek.extendedType() == Token::SINGLE_QUOTED_TYPE) {
                        key = t.readString();
                    } else {
                        throw CorruptText("Expected name inside table", peek);
                    }

                    t.readSymbol("=");

                    // Avoid copying large values
                    a.set(key, AnyVal());
                    a[key].deserialize(t);

                    peek = t.peek();
                    if ((peek.type() != Token::SYMBOL) && (peek.extendedType() != Token::SINGLE_QUOTED_TYPE)) {
                        throw CorruptText("Missing expected name or '}'", peek);
                    }
                }
                t.readSymbol("}");

            } else {
                throw CorruptText("Invalid value type.", t.peek());
            } // dispatch on symbol type
        } // scope
        break;
    }
}


AnyVal& AnyVal::operator[](const char* key) {
    return this->operator[]((std::string)key);
}


const AnyVal& AnyVal::operator[](const char* key) const {
    return this->operator[]((std::string)key);
}


AnyVal& AnyVal::operator[](const std::string& key) {
    if (m_type != TABLE) {
        throw WrongType(TABLE, m_type);
    }

    makeMutable();

    Table<std::string, AnyVal>& t = *(Table<std::string, AnyVal>*)m_value;

    if (! t.containsKey(key)) {
        t.set(key, AnyVal());
    }

    return t[key];
}


const AnyVal& AnyVal::operator[](const std::string& key) const {
    if (m_type != TABLE) {
        throw WrongType(TABLE, m_type);
    }

    const Table<std::string, AnyVal>& t = *(const Table<std::string, AnyVal>*)m_value;

    if (! t.containsKey(key)) {
        throw KeyNotFound(key);
    }

    return t[key];
}


void AnyVal::append(const AnyVal& v) {
    if (m_type != ARRAY) {
        throw WrongType(ARRAY, m_type);
    }
    makeMutable();

    Array<AnyVal>& a = *(Array<AnyVal>*)m_value;
    a.append(v);
}


void AnyVal::getKeys(Array<std::string>& keys) const {
    if (m_type != TABLE) {
        throw WrongType(TABLE, m_type);
    }

    const Table<std::string, AnyVal>& t = *(const Table<std::string, AnyVal>*)m_value;
    t.getKeys(keys);
}


int AnyVal::size() const {
    switch (m_type) {
    case TABLE:
        {
            const Table<std::string, AnyVal>& t = *(const Table<std::string, AnyVal>*)m_value;
            return t.size();
        }

    case ARRAY:
        {
            const Array<AnyVal>& a = *(Array<AnyVal>*)m_value;
            return a.size();
        }

    default:
        throw WrongType(ARRAY, m_type);
    }
}


AnyVal& AnyVal::operator[](int i) {
    if (m_type != ARRAY) {
        throw WrongType(ARRAY, m_type);
    }
    makeMutable();

    Array<AnyVal>& a = *(Array<AnyVal>*)m_value;

    if (i < 0) {
        throw IndexOutOfBounds(i, a.size());
    }

    if (a.size() <= i) {
        a.resize(i + 1);
    }

    return a[i];
}


const AnyVal& AnyVal::operator[](int i) const {
    if (m_type != ARRAY) {
        throw WrongType(ARRAY, m_type);
    }

    const Array<AnyVal>& a = *(Array<AnyVal>*)m_value;

    if (a.size() <= i || i < 0) {
        throw IndexOutOfBounds(i, a.size());
    }

    return a[i];
}


void AnyVal::makeMutable() {
    if (*m_referenceCount > 1) {
        // This is a shared instance
        --(*m_referenceCount);
        m_referenceCount = new int(1);
        m_value = copyValue();
    }
}

bool AnyVal::boolean() const {
    if (m_type != BOOLEAN) {
        throw WrongType(BOOLEAN, m_type);
    }

    return *(bool*)m_value;
}


bool AnyVal::boolean(bool defaultVal) const {
    if (m_type != BOOLEAN) {
        return defaultVal;
    }

    return *(bool*)m_value;
}


const std::string& AnyVal::string() const {
    if (m_type != STRING) {
        throw WrongType(STRING, m_type);
    }

    return *(std::string*)m_value;
}


const std::string& AnyVal::string(const std::string& defaultVal) const {
    if (m_type != STRING) {
        return defaultVal;
    } else {
        return *(std::string*)m_value;
    }
}


double AnyVal::number() const {
    if (m_type != NUMBER) {
        throw WrongType(NUMBER, m_type);
    }

    return *(double*)m_value;
}


double AnyVal::number(double defaultVal) const {
    if (m_type != NUMBER) {
        return defaultVal;
    } else {
        return *(double*)m_value;
    }
}


const Rect2D& AnyVal::rect2D() const {
    if (m_type != RECT2D) {
        throw WrongType(RECT2D, m_type);
    }

    return *(Rect2D*)m_value;
}


const Rect2D& AnyVal::rect2D(const Rect2D& defaultVal) const {
    if (m_type != RECT2D) {
        return defaultVal;
    } else {
        return *(Rect2D*)m_value;
    }
}


const AABox& AnyVal::aabox() const {
    if (m_type != AABOX) {
        throw WrongType(AABOX, m_type);
    }

    return *(AABox*)m_value;
}


const AABox& AnyVal::aabox(const AABox& defaultVal) const {
    if (m_type != AABOX) {
        return defaultVal;
    } else {
        return *(AABox*)m_value;
    }
}


const Color1& AnyVal::color1() const {
    if (m_type != COLOR1) {
        throw WrongType(COLOR1, m_type);
    }

    return *(Color1*)m_value;
}


const Color1& AnyVal::color1(const Color1& defaultVal) const {
    if (m_type != COLOR1) {
        return defaultVal;
    } else {
        return *(Color1*)m_value;
    }
}


const Color3& AnyVal::color3() const {
    if (m_type != COLOR3) {
        throw WrongType(COLOR3, m_type);
    }

    return *(Color3*)m_value;
}


const Color3& AnyVal::color3(const Color3& defaultVal) const {
    if (m_type != COLOR3) {
        return defaultVal;
    } else {
        return *(Color3*)m_value;
    }
}


const Color4& AnyVal::color4() const {
    if (m_type != COLOR4) {
        throw WrongType(COLOR4, m_type);
    }

    return *(Color4*)m_value;
}


const Color4& AnyVal::color4(const Color4& defaultVal) const {
    if (m_type != COLOR4) {
        return defaultVal;
    } else {
        return *(Color4*)m_value;
    }
}


const Vector2& AnyVal::vector2() const {
    if (m_type != VECTOR2) {
        throw WrongType(VECTOR2, m_type);
    }

    return *(Vector2*)m_value;
}


const Vector2& AnyVal::vector2(const Vector2& defaultVal) const {
    if (m_type != VECTOR2) {
        return defaultVal;
    } else {
        return *(Vector2*)m_value;
    }
}


const Vector3& AnyVal::vector3() const {
    if (m_type != VECTOR3) {
        throw WrongType(VECTOR3, m_type);
    }

    return *(Vector3*)m_value;
}


const Vector3& AnyVal::vector3(const Vector3& defaultVal) const {
    if (m_type != VECTOR3) {
        return defaultVal;
    } else {
        return *(Vector3*)m_value;
    }
}


const Vector4& AnyVal::vector4() const {
    if (m_type != VECTOR4) {
        throw WrongType(VECTOR4, m_type);
    }

    return *(Vector4*)m_value;
}


const Vector4& AnyVal::vector4(const Vector4& defaultVal) const {
    if (m_type != VECTOR4) {
        return defaultVal;
    } else {
        return *(Vector4*)m_value;
    }
}


const CoordinateFrame& AnyVal::coordinateFrame() const {
    if (m_type != COORDINATEFRAME) {
        throw WrongType(COORDINATEFRAME, m_type);
    }

    return *(CoordinateFrame*)m_value;
}


const CoordinateFrame& AnyVal::coordinateFrame(const CoordinateFrame& defaultVal) const {
    if (m_type != COORDINATEFRAME) {
        return defaultVal;
    } else {
        return *(CoordinateFrame*)m_value;
    }
}

const Matrix2& AnyVal::matrix2(const Matrix2& defaultVal) const {
    if (m_type != MATRIX2) {
        return defaultVal;
    } else {
        return *(Matrix2*)m_value;
    }
}


const Matrix2& AnyVal::matrix2() const {
    if (m_type != MATRIX2) {
        throw WrongType(MATRIX2, m_type);
    }

    return *(Matrix2*)m_value;
}


const Matrix3& AnyVal::matrix3(const Matrix3& defaultVal) const {
    if (m_type != MATRIX3) {
        return defaultVal;
    } else {
        return *(Matrix3*)m_value;
    }
}


const Matrix3& AnyVal::matrix3() const {
    if (m_type != MATRIX3) {
        throw WrongType(MATRIX3, m_type);
    }

    return *(Matrix3*)m_value;
}


const Matrix4& AnyVal::matrix4(const Matrix4& defaultVal) const {
    if (m_type != MATRIX4) {
        return defaultVal;
    } else {
        return *(Matrix4*)m_value;
    }
}


const Matrix4& AnyVal::matrix4() const {
    if (m_type != MATRIX4) {
        throw WrongType(MATRIX4, m_type);
    }

    return *(Matrix4*)m_value;
}


const Quat& AnyVal::quat(const Quat& defaultVal) const {
    if (m_type != QUAT) {
        return defaultVal;
    } else {
        return *(Quat*)m_value;
    }
}


const Quat& AnyVal::quat() const {
    if (m_type != QUAT) {
        throw WrongType(QUAT, m_type);
    }

    return *(Quat*)m_value;
}


const AnyVal& AnyVal::get(const std::string& key, const AnyVal& defaultVal) const {
    if (m_type != TABLE) {
        return defaultVal;
    }

    const Table<std::string, AnyVal>& t = *(const Table<std::string, AnyVal>*)m_value;

    if (t.containsKey(key)) {
        return t[key];
    } else {
        return defaultVal;
    }
}


const AnyVal& AnyVal::get(const std::string& key) const {
    if (m_type != TABLE) {
        throw WrongType(TABLE, m_type);
    }

    const Table<std::string, AnyVal>& t = *(const Table<std::string, AnyVal>*)m_value;

    if (t.containsKey(key)) {
        return t[key];
    } else {
        throw KeyNotFound(key);
    }
}


const AnyVal& AnyVal::get(int i, const AnyVal& defaultVal) const {
    if (m_type != ARRAY) {
        return defaultVal;
    }

    const Array<AnyVal>& a = *(const Array<AnyVal>*)m_value;

    if ((i >= 0) && (i < a.size())) {
        return a[i];
    } else {
        return defaultVal;
    }
}


const AnyVal& AnyVal::get(int i) const {
    if (m_type != ARRAY) {
        throw WrongType(ARRAY, m_type);
    }

    const Array<AnyVal>& a = *(const Array<AnyVal>*)m_value;

    if ((i >= 0) && (i < a.size())) {
        return a[i];
    } else {
        throw IndexOutOfBounds(i, a.size());
    }
}

}
