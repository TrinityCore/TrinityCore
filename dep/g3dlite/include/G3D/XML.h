/**
 @file XML.h
  
 @author Morgan McGuire
 @maintainer Morgan McGuire
  
 @created 2010-02-11
 @edited  2010-02-24

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_XML_h
#define G3D_XML_h

#include "G3D/platform.h"
#include "G3D/Table.h"
#include "G3D/Array.h"
#include "G3D/format.h"
#include <string>

namespace G3D {

class TextInput;
class TextOutput;

/** 
\brief Easy loading and saving of XML and HTML files.

The XML class is intended primarily for interchange with other
programs. We recommend using G3D::Any to make your own human-readable
formats because it is a more general syntax, the implementation is
more efficient, and contains better error handling.

Every XML is either a <i>VALUE</i>, or a <i>TAG</i> that contains both
a table of its XML attributes and an array of its children. Children
are nested tags and the strings between the nested tags.

No validation is performed, and the XML must be completely legal.  XML
Entity references (e.g., the ampersand codes for greater than and less
than) are not automatically converted.

Tags with names that begin with "!" or "?" are ignored. Comment tags must
end with "-->" e.g.,

<pre>
  <?xml version="1.0" encoding="ISO-8859-1"?>
  <!DOCTYPE note SYSTEM "Note.dtd">
  <!-- a comment -->
</pre>

\sa G3D::Any, http://www.grinninglizard.com/tinyxml/

\htmlonly
<pre>
<foo key0="value0" key1="value1">
  child0 ...
  <child1>...</child1>
  child2 ...
</foo>
</pre>
\endhtmlonly
*/
class XML {
public:

    enum Type {VALUE, TAG};

    typedef Table<std::string, XML> AttributeTable;

private:

    Type                      m_type;
    std::string               m_name;
    std::string               m_value;
    AttributeTable            m_attribute;
    Array<XML>                m_child;

public:

    XML() : m_type(VALUE) {}

    XML(const std::string& v) : m_type(VALUE), m_value(v) {}

    XML(const double& v) : m_type(VALUE), m_value(format("%f", v)) {}

    XML(float v) : m_type(VALUE), m_value(format("%f", v)) {}

    XML(int v) : m_type(VALUE), m_value(format("%d", v)) {}

    /** \param tagType Must be XML::TAG to dismbiguate from the string constructor */
    XML(Type tagType, const std::string& name, const AttributeTable& at, const Array<XML>& ch = Array<XML>()) : m_type(TAG), m_name(name), m_attribute(at), m_child(ch) {
        (void)tagType;
        debugAssert(tagType == TAG);
    }

    /** \param tagType Must be XML::TAG to dismbiguate from the string constructor */
    XML(Type tagType, const std::string& name, const Array<XML>& ch = Array<XML>()) : m_type(TAG), m_name(name), m_child(ch) {
        (void)tagType;
        debugAssert(tagType == TAG);
    }

    XML(TextInput& t);

    void serialize(TextOutput& t) const;

    void deserialize(TextInput& t);

    void load(const std::string& filename);

    void save(const std::string& filename) const;

    void parse(const std::string &s);

    void unparse(std::string& s) const;

    const AttributeTable& attributeTable() const {
        return m_attribute;
    }

    const Array<XML>& childArray() const {
        return m_child;
    }
    
    /** Array size; zero for a VALUE */
    int numChildren() const {
        return m_child.size();
    }

    /** Attribute table size; zero for a TAG */
    size_t numAttributes() const {
        return m_attribute.size();
    }

    /** Return child \a i.  Children are nested tags and the unquoted
     strings of characters between tags.*/
    const XML& operator[](int i) const {
        return m_child[i];
    }

    /** Return the attribute with this name. */
    const XML& operator[](const std::string& k) const {
        return m_attribute[k];
    }

    bool containsAttribute(const std::string& k) const {
        return m_attribute.containsKey(k);
    }

    /** Note that the result is always copied, making this inefficient
        for return values that are not VALUEs. */
    XML get(const std::string& k, const XML& defaultVal) const {
        const XML* x = m_attribute.getPointer(k);
        if (x) {
            return *x;
        } else {
            return defaultVal;
        }
    }

    Type type() const {
        return m_type;
    }

    /** The name, if this is a TAG. */
    const std::string name() const {
        return m_name;
    }

    /** Returns "" if a TAG. */
    const std::string& string() const {
        return m_value;
    }

    /** Parse as a number.  Returns nan() if a TAG or unparseable as a number. */
    double number() const;

    /** Returns false if a TAG. */
    bool boolean() const;

    operator std::string() const {
        return m_value;
    }

    operator bool() const {
        return boolean();
    }

    operator double() const {
        return number();
    }

    operator float() const {
        return float(number());
    }

    operator int() const {
        return iRound(number());
    }

};    // class XML

}    // namespace G3D

#endif
