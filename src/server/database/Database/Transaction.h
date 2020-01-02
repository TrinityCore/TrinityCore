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

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "SQLOperation.h"
#include "StringFormat.h"
#include <mutex>
#include <vector>

/*! Transactions, high level class. */
class TC_DATABASE_API TransactionBase
{
    friend class TransactionTask;
    friend class MySQLConnection;

    template <typename T>
    friend class DatabaseWorkerPool;

    public:
        TransactionBase() : _cleanedUp(false) { }
        virtual ~TransactionBase() { Cleanup(); }

        void Append(const char* sql);
        template<typename Format, typename... Args>
        void PAppend(Format&& sql, Args&&... args)
        {
            Append(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
        }

        std::size_t GetSize() const { return m_queries.size(); }

    protected:
        void AppendPreparedStatement(PreparedStatementBase* statement);
        void Cleanup();
        std::vector<SQLElementData> m_queries;

    private:
        bool _cleanedUp;
};

template<typename T>
class Transaction : public TransactionBase
{
public:
    using TransactionBase::Append;
    void Append(PreparedStatement<T>* statement)
    {
        AppendPreparedStatement(statement);
    }
};

/*! Low level class*/
class TC_DATABASE_API TransactionTask : public SQLOperation
{
    template <class T> friend class DatabaseWorkerPool;
    friend class DatabaseWorker;

    public:
        TransactionTask(std::shared_ptr<TransactionBase> trans) : m_trans(trans) { }
        ~TransactionTask() { }

    protected:
        bool Execute() override;

        std::shared_ptr<TransactionBase> m_trans;
        static std::mutex _deadlockLock;
};

#endif
