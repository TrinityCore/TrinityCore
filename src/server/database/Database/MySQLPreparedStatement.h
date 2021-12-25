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

#ifndef MySQLPreparedStatement_h__
#define MySQLPreparedStatement_h__

#include "DatabaseEnvFwd.h"
#include "Define.h"
#include "MySQLWorkaround.h"
#include <string>
#include <vector>

class MySQLConnection;
class PreparedStatementBase;

//- Class of which the instances are unique per MySQLConnection
//- access to these class objects is only done when a prepared statement task
//- is executed.
class TC_DATABASE_API MySQLPreparedStatement
{
    friend class MySQLConnection;
    friend class PreparedStatementBase;

    public:
        MySQLPreparedStatement(MySQLStmt* stmt, std::string queryString);
        ~MySQLPreparedStatement();

        void BindParameters(PreparedStatementBase* stmt);

        uint32 GetParameterCount() const { return m_paramCount; }

    protected:
        void SetParameter(uint8 index, std::nullptr_t);
        void SetParameter(uint8 index, bool value);
        template<typename T>
        void SetParameter(uint8 index, T value);
        void SetParameter(uint8 index, std::string const& value);
        void SetParameter(uint8 index, std::vector<uint8> const& value);

        MySQLStmt* GetSTMT() { return m_Mstmt; }
        MySQLBind* GetBind() { return m_bind; }
        PreparedStatementBase* m_stmt;
        void ClearParameters();
        void AssertValidIndex(uint8 index);
        std::string getQueryString() const;

    private:
        MySQLStmt* m_Mstmt;
        uint32 m_paramCount;
        std::vector<bool> m_paramsSet;
        MySQLBind* m_bind;
        std::string const m_queryString;

        MySQLPreparedStatement(MySQLPreparedStatement const& right) = delete;
        MySQLPreparedStatement& operator=(MySQLPreparedStatement const& right) = delete;
};

#endif // MySQLPreparedStatement_h__
