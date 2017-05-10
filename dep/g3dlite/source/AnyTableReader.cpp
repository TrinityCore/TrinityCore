#include "G3D/Any.h"

namespace G3D {

/** Verifies that \a is a TABLE with the given \a name. */
AnyTableReader::AnyTableReader(const std::string& name, const Any& a) : m_any(a) {
    try {
        m_any.verifyType(Any::TABLE);
        m_any.verifyName(name);
    } catch (const ParseError& e) {
        // If an exception is thrown, the destructors will not be 
        // invoked automatically.
        m_any.~Any();
        m_alreadyRead.~Set();
        throw e;
    }
}


AnyTableReader::AnyTableReader(const Any& a) : m_any(a) {
    try {
        m_any.verifyType(Any::TABLE);
    } catch (const ParseError& e) {
        // If an exception is thrown, the destructors will not be 
        // invoked automatically.
        m_any.~Any();
        m_alreadyRead.~Set();
        throw e;
    }
}


void AnyTableReader::verifyDone() const {
    if (hasMore()) {
        // Some entries were unread.  Find them.
        const Table<std::string, Any>& table = m_any.table();

        for (Table<std::string, Any>::Iterator it = table.begin();
            it.hasMore();
            ++it) {
            
            if (containsUnread(it->key)) {
                it->value.verify(false, std::string("Unread Any table key \"") + it->key + "\"");
            }
        }
    }
}


} // namespace G3D
