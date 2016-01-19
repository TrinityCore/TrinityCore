#include "Hw2Database.h"

void HW2DatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_HW2DATABASE_STATEMENTS);

    PrepareStatement(HW2_SEL_TEST, "SELECT test FROM test", CONNECTION_SYNCH);
    PrepareStatement(HW2_DEL_TEST, "DELETE FROM test WHERE guid = ?", CONNECTION_ASYNC);
}

