/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Transaction.h"
#include "Log.h"
#include "MySQLConnection.h"
#include "PreparedStatement.h"
#include "Timer.h"
#include <mysqld_error.h>
#include <sstream>
#include <thread>

std::mutex TransactionTask::_deadlockLock;

#define DEADLOCK_MAX_RETRY_TIME_MS 60000

//- Append a raw ad-hoc query to the transaction
void TransactionBase::Append(char const* sql)
{
    SQLElementData data;
    data.type = SQL_ELEMENT_RAW;
    data.element.query = strdup(sql);
    m_queries.push_back(data);
}

//- Append a prepared statement to the transaction
void TransactionBase::AppendPreparedStatement(PreparedStatementBase* stmt)
{
    SQLElementData data;
    data.type = SQL_ELEMENT_PREPARED;
    data.element.stmt = stmt;
    m_queries.push_back(data);
}

void TransactionBase::Cleanup()
{
    // This might be called by explicit calls to Cleanup or by the auto-destructor
    if (_cleanedUp)
        return;

    for (SQLElementData const& data : m_queries)
    {
        switch (data.type)
        {
            case SQL_ELEMENT_PREPARED:
                delete data.element.stmt;
            break;
            case SQL_ELEMENT_RAW:
                free((void*)(data.element.query));
            break;
        }
    }

    m_queries.clear();
    _cleanedUp = true;
}

bool TransactionTask::Execute()
{
    int errorCode = TryExecute();
    if (!errorCode)
        return true;

    if (errorCode == ER_LOCK_DEADLOCK)
    {
        std::ostringstream threadIdStream;
        threadIdStream << std::this_thread::get_id();
        std::string threadId = threadIdStream.str();

        // Make sure only 1 async thread retries a transaction so they don't keep dead-locking each other
        std::lock_guard<std::mutex> lock(_deadlockLock);

        for (uint32 loopDuration = 0, startMSTime = getMSTime(); loopDuration <= DEADLOCK_MAX_RETRY_TIME_MS; loopDuration = GetMSTimeDiffToNow(startMSTime))
        {
            if (!TryExecute())
                return true;

            TC_LOG_WARN("sql.sql", "Deadlocked SQL Transaction, retrying. Loop timer: %u ms, Thread Id: %s", loopDuration, threadId.c_str());
        }

        TC_LOG_ERROR("sql.sql", "Fatal deadlocked SQL Transaction, it will not be retried anymore. Thread Id: %s", threadId.c_str());
    }

    // Clean up now.
    CleanupOnFailure();

    return false;
}

int TransactionTask::TryExecute()
{
    return m_conn->ExecuteTransaction(m_trans);
}

void TransactionTask::CleanupOnFailure()
{
    m_trans->Cleanup();
}

bool TransactionWithResultTask::Execute()
{
    int errorCode = TryExecute();
    if (!errorCode)
    {
        m_result.set_value(true);
        return true;
    }

    if (errorCode == ER_LOCK_DEADLOCK)
    {
        std::ostringstream threadIdStream;
        threadIdStream << std::this_thread::get_id();
        std::string threadId = threadIdStream.str();

        // Make sure only 1 async thread retries a transaction so they don't keep dead-locking each other
        std::lock_guard<std::mutex> lock(_deadlockLock);
        for (uint32 loopDuration = 0, startMSTime = getMSTime(); loopDuration <= DEADLOCK_MAX_RETRY_TIME_MS; loopDuration = GetMSTimeDiffToNow(startMSTime))
        {
            if (!TryExecute())
            {
                m_result.set_value(true);
                return true;
            }

            TC_LOG_WARN("sql.sql", "Deadlocked SQL Transaction, retrying. Loop timer: %u ms, Thread Id: %s", loopDuration, threadId.c_str());
        }

        TC_LOG_ERROR("sql.sql", "Fatal deadlocked SQL Transaction, it will not be retried anymore. Thread Id: %s", threadId.c_str());
    }

    // Clean up now.
    CleanupOnFailure();
    m_result.set_value(false);

    return false;
}

bool TransactionCallback::InvokeIfReady()
{
    if (m_future.valid() && m_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        m_callback(m_future.get());
        return true;
    }

    return false;
}
