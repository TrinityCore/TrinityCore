/**
 \file Any.cpp

 \author Morgan McGuire
 \author Shawn Yarbrough
  
 \created 2006-06-11
 \edited  2013-03-29

 Copyright 2000-2013, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/Any.h"
#include "G3D/TextOutput.h"
#include "G3D/TextInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/stringutils.h"
#include "G3D/fileutils.h"
#include "G3D/FileSystem.h"
#include <deque>
#include <iostream>

namespace G3D {
const char* Any::PAREN   = "()";
const char* Any::BRACKET = "[]";
const char* Any::BRACE   = "{}";

static bool isContainerType(Any::Type& t) {
    return (t == Any::ARRAY) || (t == Any::TABLE) || (t == Any::EMPTY_CONTAINER);
}

void Any::serialize(BinaryOutput& b) const {
    TextOutput::Settings s;
    s.wordWrap = TextOutput::Settings::WRAP_NONE;
    b.writeInt32(1);
    b.writeString32(unparse(s));
}


void Any::deserialize(BinaryInput& b) {
    const int version = b.readInt32();
    alwaysAssertM(version == 1, "Wrong Any serialization version");
    _parse(b.readString32());
}


std::string Any::resolveStringAsFilename(bool errorIfNotFound) const {
    verifyType(STRING);
    if ((string().length() > 0) && (string()[0] == '<') && (string()[string().length() - 1] == '>')) {
        return string();
    }

    const std::string& f = FileSystem::resolve(string(), sourceDirectory());
    if (FileSystem::exists(f)) {
        return f;
    } else {
        const std::string& s = System::findDataFile(string(), errorIfNotFound);
        if (s.empty()) {
            return string();
        } else {
            return s;
        }
    }
}

void Any::become(const Type& t) {
    if ((t == ARRAY) || (t == TABLE)) {
        debugAssert(m_type == EMPTY_CONTAINER);
        m_type = t;
        m_data->type = m_type;
        if(t == ARRAY) {
            m_data->value.a = new AnyArray();
        } else {
            m_data->value.t = new AnyTable();
        }
    }
}


void Any::remove(const std::string& key) {
    verifyType(TABLE);
    ensureMutable();
    m_data->value.t->remove(key);
}


void Any::remove(int i) {
    verifyType(ARRAY);
    ensureMutable();
    m_data->value.a->remove(i);
}


Any Any::fromFile(const std::string& filename) {
    Any a;
    a.load(filename);
    return a;
}


void Any::loadIfExists(const std::string& filename) {
    if (FileSystem::exists(filename)) {
        load(filename);
    }
}


bool Any::nameBeginsWith(const std::string& s) const {
    return nameBeginsWith(s.c_str());
}


bool Any::nameEquals(const std::string& s) const {
    // If std::string has a fast hash compare, use it first
    return (name() == s) || nameEquals(s.c_str());
}


inline static char toLower(char c) {
    return ((c >= 'A') && (c <= 'Z')) ? (c - 'A' + 'a') : c;
}


bool Any::nameBeginsWith(const char* s) const {
    verifyType(Any::ARRAY, Any::TABLE);

    const char* n = name().c_str();
    // Walk through character-by-character
    while ((*s != '\0') && (*n != '\0')) {
        if (toLower(*s) != toLower(*n)) {
            // Mismatch
            return false;
        }
        ++s; ++n;
    }
    // Make sure s ran out no later than n
    return (*s == '\0');
}


bool Any::nameEquals(const char* s) const {
    verifyType(Any::ARRAY, Any::TABLE);
#ifdef G3D_WINDOWS
    return stricmp(name().c_str(), s) == 0;
#else
    return strcasecmp(name().c_str(), s) == 0;
#endif

}


void Any::beforeRead() const {
    if (isPlaceholder()) {
        // Tried to read from a placeholder--throw an exception as if
        // the original operator[] had failed.
        alwaysAssertM(m_data, "Corrupt placeholder");
        KeyNotFound e(m_data);

        e.key       = m_placeholderName;
        e.message   = "Key \"" + m_placeholderName + "\" not found in operator[] lookup.";

        throw e;
    } 
}

   
Any::Data* Any::Data::create(const Data* d) {
    Data* p = create(d->type);

    p->includeLine = d->includeLine;
    p->bracket   = d->bracket;
    p->separator = d->separator;
    p->comment   = d->comment;
    p->name      = d->name;
    p->source    = d->source;

    switch (d->type) {
    case NIL:
    case BOOLEAN:
    case NUMBER:
    case EMPTY_CONTAINER:
        // No clone needed
        break;

    case STRING:
        *(p->value.s) = *(d->value.s);
        break;

    case ARRAY:
        *(p->value.a) = *(d->value.a);
        break;

    case TABLE:
        *(p->value.t) = *(d->value.t);
        // Note that placeholders may be copied; that is ok--they are still
        // just placeholders.
        break;
    }

    return p;
}


Any::Data* Any::Data::create(Any::Type t, const char* b, char sep) {
    size_t s = sizeof(Data);

    switch (t) {
    case NIL:
    case BOOLEAN:
    case NUMBER:
        // No extra space needed
        break;

    case STRING:
        s += sizeof(std::string);
        break;

    case EMPTY_CONTAINER:
        // We need to allocate space for the worst-case
        s += max(sizeof(AnyArray), sizeof(AnyTable));
        // If no separator and brackets were provided, substitute defaults
        if (b == NULL) { b = PAREN; }
        if (sep == '\0') { sep = ','; }
        break;

    case ARRAY:
        s += sizeof(AnyArray);
        // If no separator and brackets were provided, substitute defaults
        if (b == NULL) { b = PAREN; }
        if (sep == '\0') { sep = ','; }
        break;

    case TABLE:
        s += sizeof(AnyTable);
        // If no separator and brackets were provided, substitute defaults
        if (b == NULL) { b = BRACE; }
        if (sep == '\0') { sep = ';'; }
        break;
    }

    // Allocate the data object
    Data* p = new (MemoryManager::create()->alloc(s)) Data(t, b, sep);

    // Create the (empty) value object at the end of the Data object
    switch (t) {
    case NIL:
    case BOOLEAN:
    case NUMBER:
    case EMPTY_CONTAINER:
        // No value
        break;

    case STRING:
        p->value.s = new (p + 1) std::string();
        break;

    case ARRAY:
        p->value.a = new (p + 1) AnyArray();
        break;

    case TABLE:
        p->value.t = new (p + 1) AnyTable();
        break;
    }

    if (isContainerType(p->type)) debugAssert(p->separator != '\0');

    return p;
}


void Any::Data::destroy(Data* d) {
    if (d != NULL) {
        d->~Data();
        MemoryManager::create()->free(d);
    }
}


Any::Data::~Data() {
    debugAssertM(referenceCount.value() <= 0, "Deleted while still referenced.");

    // Destruct but do not deallocate children
    switch (type) {
    case STRING:
        debugAssert(value.s != NULL);
        value.s->~basic_string();
        break;

    case ARRAY:
        debugAssert(value.a != NULL);
        value.a->~Array();
        break;

    case TABLE:
        debugAssert(value.t != NULL);
        value.t->~Table();
        break;

    default:
        // All other types should have a NULL value pointer (i.e., they were used just for name and comment fields)
        debugAssertM(value.s == NULL, "Corrupt Any::Data::Value");
    }

    value.s = NULL;
}


//////////////////////////////////////////////////////////////

bool Any::containsKey(const std::string& x) const {
    beforeRead();
    verifyType(TABLE);
    if (size() == 0) {
		//catches the case of an empty container, where value.t is null
        return false;
    }
    Any* a = m_data->value.t->getPointer(x);

    // Don't return true for placeholder objects
    return (a != NULL) && (! a->isPlaceholder());
}


void Any::dropReference() {
    if (m_data && m_data->referenceCount.decrement() <= 0) {
        // This was the last reference to the shared data
        Data::destroy(m_data);
    }
    m_data = NULL;
}


void Any::ensureMutable() {
    if (m_data && (m_data->referenceCount.value() >= 1)) {
        // Copy the data.  We must do this before dropping the reference
        // to avoid a race condition
        Data* d = Data::create(m_data);
        dropReference();
        m_data = d;
    }
}


Any::Any() : m_type(NIL), m_data(NULL) {
}


Any::Any(TextInput& t) : m_type(NIL), m_data(NULL) {
    deserialize(t);
}


Any::Any(const Any& x) : m_type(NIL), m_data(NULL) {
    x.beforeRead();
    *this = x;
}


Any::Any(double x) : m_type(NUMBER), m_simpleValue(x), m_data(NULL) {
}


Any::Any(float x) : m_type(NUMBER), m_simpleValue(double(x)), m_data(NULL) {
}


Any::Any(char x) : m_type(NUMBER), m_simpleValue(double(x)), m_data(NULL) {
}

Any::Any(long x) : m_type(NUMBER), m_simpleValue((double)x), m_data(NULL) {
}

Any::Any(int x) : m_type(NUMBER), m_simpleValue((double)x), m_data(NULL) {
}


Any::Any(short x) : m_type(NUMBER), m_simpleValue((double)x), m_data(NULL) {
}


Any::Any(bool x) : m_type(BOOLEAN), m_simpleValue(x), m_data(NULL) {
}


Any::Any(const std::string& s) : m_type(STRING), m_data(Data::create(STRING)) {
    *(m_data->value.s) = s;
}


Any::Any(const char* s) : m_type(STRING), m_data(NULL) {
    if (s == NULL) {
        m_type = NIL;
    } else {
        ensureData();
        *(m_data->value.s) = s;
    }
}




Any::Any(Type t, const std::string& name, const std::string& brackets, char separator) : m_type(t), m_data(NULL) {
    alwaysAssertM(isContainerType(t), "Can only create ARRAY or TABLE from Type enum.");

    ensureData();
    if (name != "") {
        m_data->name = name;
    }

    if (brackets == "") {
        if (t == ARRAY) {
            m_data->bracket = PAREN;
        } else {
            m_data->bracket = BRACE;
        }
    } else if (brackets == PAREN) {
        m_data->bracket = PAREN;
    } else if (brackets == BRACE) {
        m_data->bracket = BRACE;
    } else if (brackets == BRACKET) {
        m_data->bracket = BRACKET;
    } else {
        alwaysAssertM(false, std::string("illegal brackets: ") + brackets);
    }

    if (separator == '\0') {
        if (t == ARRAY) {
            m_data->separator = ',';
        } else {
            m_data->separator = ';';
        }
    } else if (separator == ',' || separator == ';') {
        m_data->separator = separator;
    } else {
        alwaysAssertM(false, std::string("illegal separator: ") + separator);
    }
}


Any::~Any() {
    dropReference();
}


void Any::beforeWrite() {
    if (isPlaceholder()) {
        // This is no longer a placeholder
        m_placeholderName.clear();
    }

    if (m_data && ! m_data->includeLine.empty()) {
        // Forget where this Any was included from...it no
        // longer matches the contents there.
        m_data->includeLine = "";
    }
}


Any& Any::operator=(const Any& x) {
    x.beforeRead();

    if (this == &x) {
        return *this;
    }

    beforeWrite();

    dropReference();

    m_type        = x.m_type;
    m_simpleValue = x.m_simpleValue;

    if (x.m_data != NULL) {
        x.m_data->referenceCount.increment();
        m_data = x.m_data;
    }

    return *this;
}


Any& Any::operator=(Type t) {
    switch (t) {
    case NIL:  
        *this = Any();
        break;

    case TABLE: // All 3 cases intentionally fall through
    case ARRAY:
    case EMPTY_CONTAINER:
        *this = Any(t);
        break;

    default:
        alwaysAssertM(false, "Can only assign NIL, TABLE, or ARRAY Type enum.");
    }

    return *this;
}


Any::Type Any::type() const {
    beforeRead();
    return m_type;
}


const std::string& Any::comment() const {
    beforeRead();

    static const std::string blank;
    if (m_data != NULL) {
        return m_data->comment;
    } else {
        return blank;
    }
}


void Any::setComment(const std::string& c) {
    beforeRead();
    ensureData();
    m_data->comment = c;
}


bool Any::isNil() const {
    beforeRead();
    return (m_type == NIL);
}

double Any::number() const {
    beforeRead();
    verifyType(NUMBER);
    return m_simpleValue.n;
}

float Any::floatValue() const {
    beforeRead();
    verifyType(NUMBER);
    return (float)m_simpleValue.n;
}


const std::string& Any::string() const {
    beforeRead();
    verifyType(STRING);
    return *(m_data->value.s);
}


bool Any::boolean() const {
    beforeRead();
    verifyType(BOOLEAN);
    return m_simpleValue.b;
}


const std::string& Any::name() const {
    beforeRead();
    static const std::string blank;
    if (m_data != NULL) {
        return m_data->name;
    } else {
        return blank;
    }
}


void Any::setName(const std::string& n) {
    beforeRead();
    ensureData();
    m_data->name = n;
}


int Any::size() const {
    beforeRead();
    verifyType(ARRAY, TABLE);
    switch (m_type) {
    case TABLE:
        return (int)m_data->value.t->size();

    case ARRAY:
        return m_data->value.a->size();

    default:
        return 0;
    }
}


int Any::length() const {
    beforeRead();
    return size();
}


void Any::resize(int n) {
    beforeRead();
    alwaysAssertM(n >= 0, "Cannot resize less than 0.");
    verifyType(ARRAY);
    if (type() == EMPTY_CONTAINER) {
        become(ARRAY);
    }
    m_data->value.a->resize(n);
}


void Any::clear() {
    beforeRead();
    verifyType(ARRAY, TABLE);
    switch (m_type) {
    case ARRAY:
        m_data->value.a->clear();
        break;

    case TABLE:
        m_data->value.t->clear();
        break;
    default:;
    }
}


const Any& Any::operator[](int i) const {
    beforeRead();
    verifyType(ARRAY);
    debugAssert(m_data != NULL);
    Array<Any>& array = *(m_data->value.a);
    if (i < 0 || i >= array.size()) {
        throw IndexOutOfBounds(m_data, i, array.size());
    }
    return array[i];
}


Any& Any::next() {
    beforeRead();
    verifyType(ARRAY);
    int n = size();
    resize(n + 1);
    return (*this)[n];
}


Any& Any::operator[](int i) {
    beforeRead();
    ensureMutable();
    verifyType(ARRAY);
    debugAssert(m_data != NULL);
    Array<Any>& array = *(m_data->value.a);
    if (i < 0 || i >= array.size()) {
        throw IndexOutOfBounds(m_data, i, array.size());
    }
    return array[i];
}


const Array<Any>& Any::array() const {
    beforeRead();
    verifyType(ARRAY);
    debugAssert(m_data != NULL);
    return *(m_data->value.a);
}


void Any::_append(const Any& x0) {
    beforeRead();
    verifyType(ARRAY);
    debugAssert(m_data != NULL);
    if (type() == EMPTY_CONTAINER) {
        become(ARRAY);
    }
    m_data->value.a->append(x0);
}


void Any::_append(const Any& x0, const Any& x1) {
    beforeRead();
    append(x0);
    append(x1);
}


void Any::_append(const Any& x0, const Any& x1, const Any& x2) {
    beforeRead();
    append(x0);
    append(x1);
    append(x2);
}


void Any::_append(const Any& x0, const Any& x1, const Any& x2, const Any& x3) {
    beforeRead();
    append(x0);
    append(x1);
    append(x2);
    append(x3);
}


const Table<std::string, Any>& Any::table() const {
    beforeRead();
    verifyType(TABLE);
    debugAssert(m_data != NULL);

    if (type() == Any::EMPTY_CONTAINER) {
        // if empty, m_data->value.t will not be initialized as it is unknown whether this is supposed to be an array or a table
        static const Table<std::string, Any> emptyTable;
        return emptyTable;
    }
    return *(m_data->value.t);
}


const Any& Any::operator[](const std::string& x) const {
    beforeRead();
    verifyType(TABLE);
    debugAssert(m_data != NULL);
    const Table<std::string, Any>& table = *(m_data->value.t);
    Any* value = table.getPointer(x);
    if (value == NULL) {
        KeyNotFound e(m_data);
        e.key = x;
        e.message = "Key not found in operator[] lookup.";
        throw e;
    }
    return *value;
}


Any& Any::operator[](const std::string& key) {
    beforeRead();
    ensureMutable();
    verifyType(TABLE);

    bool created = false;
    Any& value = m_data->value.t->getCreate(key, created);

    if (created) {
        // The entry was created by this method; do not allow it to be
        // read before it is written.
        value.m_placeholderName = key;

        // Write source data for the value
        value.ensureData();
        value.m_data->source = source();
    }

    return value;
}


void Any::_set(const std::string& k, const Any& v) {
    beforeRead();
    v.beforeRead();
    verifyType(TABLE);
    debugAssert(m_data != NULL);
    if ( type() == EMPTY_CONTAINER) {
        become(TABLE);
    }
    Table<std::string, Any>& table = *(m_data->value.t);
    table.set(k, v);
}


Any Any::_get(const std::string& x, const Any& defaultVal) const {
    beforeRead();
    defaultVal.beforeRead();
    try {
        return operator[](x);
    } catch(KeyNotFound) {
        return defaultVal;
    }
}


bool Any::operator==(const Any& x) const {
    beforeRead();
    x.beforeRead();

    if (m_type != x.m_type) {
        return false;
    }

    switch (m_type) {
    case NIL:
        return true;

    case BOOLEAN:
        return (m_simpleValue.b == x.m_simpleValue.b);

    case NUMBER:
        return (m_simpleValue.n == x.m_simpleValue.n);

    case STRING:
        debugAssert(m_data != NULL);
        return (*(m_data->value.s) == *(x.m_data->value.s));

    case TABLE: {
        if (size() != x.size()) {
            return false;
        }
        debugAssert(m_data != NULL);
        if (m_data->name != x.m_data->name) {
            return false;
        }
        const Table<std::string, Any>& table1 = table();
        const Table<std::string, Any>& table2 = x.table();
        for (Table<std::string, Any>::Iterator it = table1.begin(); it.isValid(); ++it) {
            const Any* p2 = table2.getPointer(it->key);
            if (p2 == NULL) {
                // Key not found
                return false;
            } else if (*p2 != it->value) {
                // Different value
                return false;
            }                
        }
        return true;
    }

    case ARRAY: {
        if (size() != x.size()) {
            return false;
        }
        debugAssert(m_data != NULL);
        if (m_data->name != x.m_data->name) {
            return false;
        }

        Array<Any>& cmparray  = *(  m_data->value.a);
        Array<Any>& xcmparray = *(x.m_data->value.a);

        for (int ii = 0; ii < size(); ++ii) {
            if (cmparray[ii] != xcmparray[ii]) {
                return false;
            }
        }
        return true;
    }
    
    case EMPTY_CONTAINER:
        return true;
    default:
        alwaysAssertM(false, "Unknown type.");
        return false;
    }

}


bool Any::operator!=(const Any& x) const {
    return ! operator==(x);
}


static void getDeserializeSettings(TextInput::Settings& settings) {
    settings.cppBlockComments = true;
    settings.cppLineComments = true;
    settings.otherLineComments = false;
    settings.generateCommentTokens = true;
    settings.singleQuotedStrings = false;
    settings.msvcFloatSpecials = true;
    settings.caseSensitive = false;
}


std::string Any::unparseJSON(const TextOutput::Settings& settings, bool allowCoercion) const {
    beforeRead();
    TextOutput to(settings);
    serialize(to, true, allowCoercion);
    return to.commitString();
}


std::string Any::unparse(const TextOutput::Settings& settings) const {
    beforeRead();
    TextOutput to(settings);
    serialize(to);
    return to.commitString();
}


Any Any::parse(const std::string& src) {
    Any a;
    a._parse(src);
    return a;    
}


void Any::_parse(const std::string& src) {
    beforeRead();
    TextInput::Settings settings;
    getDeserializeSettings(settings);

    TextInput ti(TextInput::FROM_STRING, src, settings);
    deserialize(ti);
}


void Any::load(const std::string& filename) {
    beforeRead();
    TextInput::Settings settings;
    getDeserializeSettings(settings);

    TextInput ti(FileSystem::resolve(filename), settings);
    deserialize(ti);
}


void Any::save(const std::string& filename) const {
    beforeRead();
    TextOutput::Settings settings;
    settings.wordWrap = TextOutput::Settings::WRAP_NONE;

    TextOutput to(filename,settings);
    serialize(to);
    to.commit();
}


static bool needsQuotes(const std::string& s) {
    if (! isLetter(s[0]) && (s[0] != '_')) {
        return true;
    }

    for (int i = 0; i < (int)s.length(); ++i) {
        char c = s[i];
        
        // peek character
        char p = (i == (int)s.length() - 1) ? '_' : s[i + 1];

        // Identify separators
        if ((c == '-' && p == '>') ||
            (c == ':' && p == ':')) {            
            // Skip over this symbol
            ++i;
            continue;
        }

        if (! isDigit(c) && ! isLetter(c) & (c != '.')) {
            // This is an illegal character for an identifier, so we need quotes
            return true;
        }
    }

    return false;
}


void Any::serialize(TextOutput& to, bool json, bool coerce) const {
    beforeRead();

    if (m_data && ! m_data->includeLine.empty()) {
        if (json) {
            if (! coerce) {
                throw "Could not coerce to JSON";
            }

            // Silently fall through
        } else {
            // This value came from a #include...preserve it.  This includes the comment
            // if any.
            to.printf("%s", m_data->includeLine.c_str());
            return;
        }
    }

    if (m_data && ! m_data->comment.empty()) {
        if (json) {
            if (! coerce) {
                throw "Could not coerce to JSON";
            }
        } else {
            to.printf("\n/* %s */\n", m_data->comment.c_str());
        }
    }

    switch (m_type) {
    case NIL:
        if (json) {
            to.writeSymbol("null");
        } else {
            to.writeSymbol("NIL");
        }
        break;

    case BOOLEAN:
        to.writeBoolean(m_simpleValue.b);
        break;

    case NUMBER:
        if (json) {
            // Specials have no legal syntax in JSON, so insert values that will parse 
            // to something close to what we want (there is no good solution for NaN, unfortunately)
            if (m_simpleValue.n == inf()) {
                to.writeSymbol("1e10000");
            } else if (m_simpleValue.n == -inf()) {
                to.writeSymbol("-1e10000");
            } else if (isNaN(m_simpleValue.n)) {
                if (! coerce) {
                    throw "There is no way to represent NaN in JSON";
                }
                to.writeSymbol("null");
            } else {
                to.writeNumber(m_simpleValue.n);
            }
        } else {
            to.writeNumber(m_simpleValue.n);
        }
        break;

    case STRING:
        debugAssert(m_data != NULL);
        to.writeString(*(m_data->value.s));
        break;

    case TABLE: {
        debugAssert(m_data != NULL);
        debugAssert(m_data->separator != '\0');

        if (! m_data->name.empty()) {
            if (json) {
                if (! coerce) {
                    throw "Could not coerce to JSON";
                }
            } else {
                if (needsQuotes(m_data->name)) {
                    to.writeString(m_data->name);
                } else {
                    to.writeSymbol(m_data->name);
                }
            }
        }
        if (json) {
            to.writeSymbol("{");
        } else {
            to.writeSymbol(m_data->bracket[0]);
        }
        to.writeNewline();
        to.pushIndent();
        AnyTable& table = *(m_data->value.t);
        Array<std::string> keys;
        table.getKeys(keys);
        keys.sort();

        for (int i = 0; i < keys.size(); ++i) {

            int prevLine = to.line();
            if (needsQuotes(keys[i]) || json) {
                to.writeString(keys[i]);
            } else {
                to.writeSymbol(keys[i]);
            }

            if (json) {
                to.writeSymbol(":");
            } else {
                to.writeSymbol("=");
            }
            table[keys[i]].serialize(to, json, coerce);

            to.deleteSpace();
            if (json) {
                // Don't put a separator after the last
                if (i != keys.size() - 1) {
                    to.writeSymbol(",");
                }
            } else {
                to.writeSymbol(m_data->separator);
            }

            // Skip an extra line between table entries that are longer than a line
            if (prevLine != to.line()) {
                to.writeNewline();
            }

            to.writeNewline();
        }

        to.popIndent();
        to.writeSymbol(m_data->bracket[1]);
        break;
    }

    case ARRAY: {
        debugAssert(m_data != NULL);
        debugAssert(m_data->separator != '\0');

        if (! m_data->name.empty()) {
            if (json) {
                if (! coerce) {
                    throw "Could not coerce to JSON";
                }
                to.writeSymbol("[");
            } else {
                // For arrays, leave no trailing space between the name and the paren
                to.printf("%s%c", m_data->name.c_str(), m_data->bracket[0]);
            }
        } else {
            if (json) {
                to.writeSymbol("[");
            } else {
                to.writeSymbol(m_data->bracket[0]);
            }
        }
        const Array<Any>& array = *(m_data->value.a);
        const bool longForm = (array.size() > 0) && ((array[0].type() == ARRAY) || (array[0].type() == TABLE));

        if (longForm) {
            to.writeNewline();
        }

        to.pushIndent();
        for (int ii = 0; ii < size(); ++ii) {
            array[ii].serialize(to, json, coerce);
            if (ii < size() - 1) {
                to.deleteSpace();
                if (longForm) {
                    // Probably a long-form array
                    if (json) {
                        to.writeSymbol(",");
                    } else {
                        to.writeSymbol(m_data->separator);
                    }
                    to.writeNewline();
                } else {
                    // Probably a short-form array
                    if (json) {
                        to.writeSymbol(",");
                    } else {
                        to.writeSymbol(m_data->separator);
                    }
                }
            }
            
            // Put the close paren on an array right behind the last element
        }
        to.popIndent();
        if (json) {
            to.writeSymbol("]");
        } else {
            to.writeSymbol(m_data->bracket[1]);
        }
        break;
    }

    case EMPTY_CONTAINER: {
        debugAssert(m_data != NULL);
        debugAssert(m_data->separator != '\0');

        if (json) {
            if (! coerce) {
                throw "Cannot strictly convert the ambiguous Any empty container to JSON";
            }
            to.writeSymbols("[", "]");
        } else {
            if (! m_data->name.empty()) {
                // Leave no trailing space between the name and the paren
                to.printf("%s%c", m_data->name.c_str(), m_data->bracket[0]);
            } else {
                to.writeSymbol(m_data->bracket[0]);
            }
            to.writeSymbol(m_data->bracket[1]);
        }
        break;
    }
    }
    
}


void Any::deserializeComment(TextInput& ti, Token& token, std::string& comment) {
    // Parse comments
    while (token.type() == Token::COMMENT) {
        comment += trimWhitespace(token.string());

        // Allow comments to contain newlines.
        do {
            token = ti.read();
            comment += "\n";
        } while (token.type() == Token::NEWLINE);
    }

    comment = trimWhitespace(comment);
}


/** True if \a c is an open paren of some form */
static bool isOpen(const char c) {
    return c == '(' || c == '[' || c == '{';
}


/** True if \a c is an open paren of some form */
static bool isClose(const char c) {
    return c == ')' || c == ']' || c == '}';
}


void Any::deserializeName(TextInput& ti, Token& token, std::string& name) {
    debugAssert(token.type() == Token::SYMBOL);
    std::string s = token.string();
    while (! isOpen(s[0])) {
        name += s;

        // Skip newlines and comments
        token = ti.readSignificant();

        if (token.type() != Token::SYMBOL) {
            throw ParseError(ti.filename(), token.line(), token.character(), 
                "Expected symbol while parsing Any");
        }
        s = token.string();
    }
}


void Any::deserialize(TextInput& ti) {
    beforeRead();
    Token token = ti.read();
    deserialize(ti, token);
    // Restore the last token
    ti.push(token);
}


void Any::deserialize(TextInput& ti, Token& token) {
    // Deallocate old data
    dropReference();
    m_type = NIL;
    m_simpleValue.b = false;

    // Skip leading newlines
    while (token.type() == Token::NEWLINE) {
        token = ti.read();
    } 

    std::string comment;
    if (token.type() == Token::COMMENT) {
        deserializeComment(ti, token, comment);
    }

    if (token.type() == Token::END) {
        // There should never be a comment without an Any following it; even
        // if the file ends with some commented out stuff,
        // that should not happen after a comma, so we'd never read that 
        // far in a proper file.
        throw ParseError(ti.filename(), token.line(), token.character(), 
            "File ended without a properly formed Any");
    }

    // Do we need to read one more token after the end? 
    bool needRead = true;

    switch (token.type()) {
    case Token::STRING:
        m_type = STRING;
        ensureData();
        *(m_data->value.s) = token.string();
        m_data->source.set(ti, token);
        break;

    case Token::NUMBER:
        m_type = NUMBER;
        m_simpleValue.n = token.number();
        ensureData();
        m_data->source.set(ti, token);
        break;

    case Token::BOOLEAN:
        m_type = BOOLEAN;
        m_simpleValue.b = token.boolean();
        ensureData();
        m_data->source.set(ti, token);
        break;

    case Token::SYMBOL:
        // Pragma, Named Array, Named Table, Array, Table, or NIL
        if (token.string() == "#") {
            // Pragma
            
            // Currently, "include" is the only pragma allowed
            token = ti.read();
            if (! ((token.type() == Token::SYMBOL) &&
                   (token.string() == "include"))) {
                throw ParseError(ti.filename(), token.line(), token.character(),
                                 "Expected 'include' pragma after '#'");
            }
            
            ti.readSymbol("(");
            // The string typed into the file, which may be relative
            const std::string& includeName = ti.readString();

            // Find the include file
            const std::string& myPath = FilePath::parent(ti.filename());

            std::string t = FileSystem::resolve(includeName, myPath);

            if (! FileSystem::exists(t)) {
                // Try and find the path, starting with the cwd
                t = System::findDataFile(includeName);
            }

            // Read the included file
            load(t);

            // Update the source information
            ensureData();
            if (! comment.empty()) {
                m_data->includeLine = format("\n/* %s */\n", comment.c_str());
            }
            m_data->includeLine += format("#include(\"%s\")", includeName.c_str());
            m_data->source.filename +=
                format(" [included from %s:%d(%d)]", ti.filename().c_str(), token.line(), token.character());
            
            ti.readSymbol(")");

        } else if (toUpper(token.string()) == "NIL" || token.string() == "None") {
            // Nothing left to do; we initialized to NIL originally
            ensureData();
            m_data->source.set(ti, token);
        } else if (isValidIdentifier(token.string()) && !isOpen(ti.peek().string()[0]) && ti.peek().string() != "::") {
            // Valid unquoted string
            m_type = STRING;
            ensureData();
            *(m_data->value.s) = token.string();
            m_data->source.set(ti, token);
        } else {
            // Array or Table

            // Parse the name
            // s must have at least one element or this would not have
            // been parsed as a symbol
            std::string name;
            deserializeName(ti, token, name);
            if (token.type() != Token::SYMBOL) {
                throw ParseError(ti.filename(), token.line(), token.character(), 
                    "Malformed Any TABLE or ARRAY; must start with [, (, or {");
            }

            if (isOpen(token.string()[0])) {
                // Array or table
                deserializeBody(ti, token);
            } else {
                throw ParseError(ti.filename(), token.line(), token.character(), 
                    "Malformed Any TABLE or ARRAY; must start with [, (, or {");
            }

            if (! name.empty()) {
                ensureData();
                m_data->name = name;
            }
            needRead = false;
        } // if NIL
        break;

    default:
        throw ParseError(ti.filename(), token.line(), token.character(), 
            "Unexpected token");

    } // switch

    if (! comment.empty()) {
        ensureData();
        m_data->comment = comment;
    }

    if (needRead) {
        // Array and table already consumed their last token
        token = ti.read();
    }
}


void Any::ensureData() {
    if (m_data == NULL) {
        m_data = Data::create(m_type);
    }
}


static bool isSeparator(char c) {
    return c == ',' || c == ';';
}


void Any::readUntilSeparatorOrClose(TextInput& ti, Token& token) {
    bool atClose = (token.type() == Token::SYMBOL) && isClose(token.string()[0]);
    bool atSeparator = isSeparator(token.string()[0]);

    while (! (atClose || atSeparator)) {
        switch (token.type()) {
        case Token::NEWLINE:
        case Token::COMMENT:
            // Consume
            token = ti.read();
            break;

        default:
            throw ParseError(ti.filename(), token.line(), token.character(), 
                "Expected a comma or close paren");
        }

        // Update checks
        atSeparator = isSeparator(token.string()[0]);
        atClose = (token.type() == Token::SYMBOL) && isClose(token.string()[0]);
    }
}

/**
  Determines the type [TABLE, ARRAY, or EMPTY_CONTAINER] from the given TextInput
  TextInput is the same at the end as it was beofr  
*/
static Any::Type findType(TextInput& ti, const char closeSymbol) {
    Any::Type type = Any::NIL;
    std::vector<Token> tokens;
    // consumes the open symbol
    Token token = ti.read();
    tokens.push_back(token);

    bool hasAnElement = false;
    while (type == Any::NIL) {
        if (token.type() == Token::COMMENT) {
            // consumes tokens and prepares to push them back onto the TextInput
            token = ti.read();
            tokens.push_back(token);
        } else if ((token.type() == Token::SYMBOL) && ((token.string() == "=") || (token.string() == ":"))) {
            // an '=' indicates a key = value pairing, and thus a table
            type = Any::TABLE;
        } else if (hasAnElement) {
            // any non-comment, non-'=' token after any element indicates an array
            type = Any::ARRAY;
        } else if ((token.type() == Token::SYMBOL) && (token.string()[0] == closeSymbol)) {
            // catches no previous element and a closing symbol (e.g [])
            type = Any::EMPTY_CONTAINER;
        } else {
            // consumes elements, indicating one has been seen, and prepares to push them back onto TextInput
            hasAnElement = true;
            token = ti.read();
            tokens.push_back(token);
        }
    }
    // pushes everything back to the TextInput
    while (!tokens.empty()) {
        token = tokens.back();
        ti.push(token);
        tokens.pop_back();
    }
    return type;
}


void Any::deserializeBody(TextInput& ti, Token& token) {
    char closeSymbol = '\0';
    m_type = TABLE;
    
    const char c = token.string()[0];

    // Chose the appropriate close symbol based on the open symbol
    const char* bracket;
    if (c == '(') {
        bracket = PAREN;
    } else if (c == '[') {
        bracket = BRACKET;
    } else if (c == '{') {
        bracket = BRACE;
    } else {
        debugAssertM(false, "Illegal bracket type");
	bracket = PAREN;
    }
    closeSymbol = bracket[1];

    // We must set the type before we allocate m_data in ensureData().
    m_type = findType(ti, closeSymbol);

    // Allocate the underlying data structure
    ensureData();
    m_data->source.set(ti, token);
    m_data->bracket = bracket;

    debugAssert(m_data->type == m_type);
    debugAssert(m_data->separator != '\0');

    // Consume the open token
    token = ti.read();

    while (! ((token.type() == Token::SYMBOL) && (token.string()[0] == closeSymbol))) {

        // Read any leading comment.  This must be done here (and not in the recursive deserialize
        // call) in case the body contains only a comment.
        std::string comment;
        deserializeComment(ti, token, comment);

        if ((token.type() == Token::SYMBOL) && (token.string()[0] == closeSymbol)) {
            // We're done; this catches the case where the container is empty
            break;
        }

        // Pointer the value being read
        Any a;
        std::string key;
        
        if (m_type == TABLE) {
            // Read the key
            if (token.type() != Token::SYMBOL && token.type() != Token::STRING) {
                throw ParseError(ti.filename(), token.line(), token.character(), "Expected a name");
            } 
            
            key = token.string();
            // Consume everything up to the = sign, returning the "=" sign.
            token = ti.readSignificant();

            if ((token.type() != Token::SYMBOL) || ((token.string() != "=") && token.string() != ":")) {
                throw ParseError(ti.filename(), token.line(), token.character(), "Expected = or :");
            } else {
                // Read the next token, which is the value (don't consume comments--we want the value pointed to by a to get those).
                token = ti.read();
            }
        }
        a.deserialize(ti, token);

        if (! comment.empty()) {
            // Prepend the comment we read earlier
            a.ensureData();
            a.m_data->comment = trimWhitespace(comment + "\n" + a.m_data->comment);
        }
        
        if (m_type == TABLE) {
            set(key, a);
        } else {
            append(a);
        }

        // Read until the separator or close paren, discarding trailing comments and newlines
        readUntilSeparatorOrClose(ti, token);

        char s = token.string()[0];

        // Consume the separator
        if (isSeparator(s)) {
            token = ti.read();
            m_data->separator = s;
            debugAssert(m_data->separator != '\0');
        }
    }

    // Consume the close paren (to match other deserialize methods)
    token = ti.read();
}


Any::operator int() const {
    beforeRead();
    return iRound(number());
}


Any::operator uint32() const {
    beforeRead();
    return uint32(number() + 0.5);
}


Any::operator float() const {
    beforeRead();
    return float(number());
}


Any::operator double() const {
    beforeRead();
    return number();
}


Any::operator bool() const {
    beforeRead();
    return boolean();
}


Any::operator std::string() const {
    beforeRead();
    return string();
}


const Any::Source& Any::source() const {
    static Source s;
    if (m_data) {
        return m_data->source;
    } else {
        return s;
    }
}


std::string Any::sourceDirectory() const {
    if (m_data) {
        return FilePath::parent(m_data->source.filename);
    } else {
        return "";
    }
}

void Any::verify(bool value, const std::string& message) const {
    beforeRead();
    if (! value) {
        ParseError p;
        if (m_data) {
            p.filename  = m_data->source.filename;
            p.line      = m_data->source.line;
            p.character = m_data->source.character;
        }

        if (name().empty()) {
            p.message = "Parse error";
        } else {
            p.message = "Parse error while reading the contents of " + name();
        }

        if (! message.empty()) {
            p.message = p.message + ": " + message;
        }

        throw p;
    }
}


void Any::verifyName(const std::string& n) const {
    beforeRead();
    verify(name() == n, "Name must be " + n);
}


void Any::verifyName(const std::string& n, const std::string& m) const {
    beforeRead();
    const std::string& x = name();
    verify(x == n ||
           x == m, "Name must be " + n + " or " + m);
}


void Any::verifyName(const std::string& n, const std::string& m, const std::string& p) const {
    beforeRead();
    const std::string& x = name();
    verify(x == n ||
           x == m ||
           x == p, "Name must be " + n + ", " + m + ", or " + p);
}


void Any::verifyName(const std::string& n, const std::string& m, const std::string& p, const std::string& q) const {
    beforeRead();
    const std::string& x = name();
    verify(x == n ||
           x == m ||
           x == p ||
           x == q, "Name must be " + n + ", " + m + ", " + p + ", or " + q);
}


void Any::verifyNameBeginsWith(const std::string& n) const {
    beforeRead();
    verify(beginsWith(name(), n), "Name must begin with " + n);
}


void Any::verifyNameBeginsWith(const std::string& n, const std::string& m) const {
    beforeRead();
    const std::string& x = name();
    verify(beginsWith(x, n) ||
           beginsWith(x, m), "Name must be " + n + " or " + m);
}


void Any::verifyNameBeginsWith(const std::string& n, const std::string& m, const std::string& p) const {
    beforeRead();
    const std::string& x = name();
    verify(beginsWith(x, n) ||
           beginsWith(x, m) ||
           beginsWith(x, p), "Name must be " + n + ", " + m + ", or " + p);
}


void Any::verifyNameBeginsWith(const std::string& n, const std::string& m, const std::string& p, const std::string& q) const {
    beforeRead();
    const std::string& x = name();
    verify(beginsWith(x, n) ||
           beginsWith(x, m) ||
           beginsWith(x, p) ||
           beginsWith(x, q), "Name must be " + n + ", " + m + ", " + p + ", or " + q);
}


void Any::verifyNameBeginsWith(const std::string& n, const std::string& m, const std::string& p, const std::string& q, const std::string& r) const {
    beforeRead();
    const std::string& x = name();
    verify(beginsWith(x, n) ||
           beginsWith(x, m) ||
           beginsWith(x, p) ||
           beginsWith(x, q) ||
           beginsWith(x, r), "Name must be " + n + ", " + m + ", " + p + ", or " + q + ", or " + r);
}


void Any::verifyNameBeginsWith(const std::string& n, const std::string& m, const std::string& p, const std::string& q, const std::string& r, const std::string& s) const {
    beforeRead();
    const std::string& x = name();
    verify(beginsWith(x, n) ||
           beginsWith(x, m) ||
           beginsWith(x, p) ||
           beginsWith(x, q) ||
           beginsWith(x, r) ||
           beginsWith(x, s), "Name must be " + n + ", " + m + ", " + p + ", or " + q + ", or " + r + ", or " + s);
}


void Any::verifyNameBeginsWith(const std::string& n, const std::string& m, const std::string& p, const std::string& q, const std::string& r, const std::string& s, const std::string& t) const {
    beforeRead();
    const std::string& x = name();
    verify(beginsWith(x, n) ||
           beginsWith(x, m) ||
           beginsWith(x, p) ||
           beginsWith(x, q) ||
           beginsWith(x, r) ||
           beginsWith(x, s) ||
           beginsWith(x, t), "Name must be " + n + ", " + m + ", " + p + ", or " + q + ", or " + r + ", or " + s + ", or " + t);
}


void Any::verifyType(Type t) const {
    beforeRead();
    if ((type() != t) && ! ((type() == EMPTY_CONTAINER) && isContainerType(t))) {
        verify(false, "Must have type " + toString(t));
    }
}


void Any::verifyType(Type t0, Type t1) const {
    beforeRead();
    if ((type() != t0 && !((type() == EMPTY_CONTAINER) && isContainerType(t0))) &&
        (type() != t1 && !((type() == EMPTY_CONTAINER) && isContainerType(t1)))) {
        verify(false, "Must have type " + toString(t0) + " or " + toString(t1));
    }
}


void Any::verifySize(int low, int high) const {
    beforeRead();
    verifyType(ARRAY, TABLE);
    if (size() < low || size() > high) {
        verify(false, format("Size must be between %d and %d", low, high));
    }
}


void Any::verifySize(int s) const {
    beforeRead();
    verifyType(ARRAY, TABLE);
    if (size() != s) {
        verify(false, format("Size must be %d", s));
    }
}


std::string Any::toString(Type t) {
    switch(t) {
    case NIL:    return "NIL";
    case BOOLEAN: return "BOOLEAN";
    case NUMBER:  return "NUMBER";
    case STRING:  return "STRING";
    case ARRAY:   return "ARRAY";
    case TABLE:   return "TABLE";
    default:
        alwaysAssertM(false, "Illegal Any::Type");
        return "";
    }
}

}    // namespace G3D

