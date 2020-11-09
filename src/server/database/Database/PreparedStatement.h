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

#ifndef _PREPAREDSTATEMENT_H
#define _PREPAREDSTATEMENT_H

#include "Define.h"
#include "SQLOperation.h"
#include <future>
#include <vector>
#include <variant>

struct PreparedStatementData
{
    std::variant<
        bool,
        uint8,
        uint16,
        uint32,
        uint64,
        int8,
        int16,
        int32,
        int64,
        float,
        double,
        std::string,
        std::vector<uint8>,
        std::nullptr_t
    > data;

    template<typename T>
    static std::string ToString(T value);

    static std::string ToString(bool value);
    static std::string ToString(uint8 value);
    static std::string ToString(int8 value);
    static std::string ToString(std::string const& value);
    static std::string ToString(std::vector<uint8> const& value);
    static std::string ToString(std::nullptr_t);
};

//- Upper-level class that is used in code
class TC_DATABASE_API PreparedStatementBase
{
    friend class PreparedStatementTask;

    public:
        explicit PreparedStatementBase(uint32 index, uint8 capacity);
        virtual ~PreparedStatementBase();

        void setNull(const uint8 index);
        void setBool(const uint8 index, const bool value);
        void setUInt8(const uint8 index, const uint8 value);
        void setUInt16(const uint8 index, const uint16 value);
        void setUInt32(const uint8 index, const uint32 value);
        void setUInt64(const uint8 index, const uint64 value);
        void setInt8(const uint8 index, const int8 value);
        void setInt16(const uint8 index, const int16 value);
        void setInt32(const uint8 index, const int32 value);
        void setInt64(const uint8 index, const int64 value);
        void setFloat(const uint8 index, const float value);
        void setDouble(const uint8 index, const double value);
        void setString(const uint8 index, const std::string& value);
        void setStringView(const uint8 index, const std::string_view value);
        void setBinary(const uint8 index, const std::vector<uint8>& value);
        template <size_t Size>
        void setBinary(const uint8 index, std::array<uint8, Size> const& value)
        {
            std::vector<uint8> vec(value.begin(), value.end());
            setBinary(index, vec);
        }

        uint32 GetIndex() const { return m_index; }
        std::vector<PreparedStatementData> const& GetParameters() const { return statement_data; }

    protected:
        uint32 m_index;

        //- Buffer of parameters, not tied to MySQL in any way yet
        std::vector<PreparedStatementData> statement_data;

        PreparedStatementBase(PreparedStatementBase const& right) = delete;
        PreparedStatementBase& operator=(PreparedStatementBase const& right) = delete;
};

template<typename T>
class PreparedStatement : public PreparedStatementBase
{
public:
    explicit PreparedStatement(uint32 index, uint8 capacity) : PreparedStatementBase(index, capacity)
    {
    }

private:
    PreparedStatement(PreparedStatement const& right) = delete;
    PreparedStatement& operator=(PreparedStatement const& right) = delete;
};

//- Lower-level class, enqueuable operation
class TC_DATABASE_API PreparedStatementTask : public SQLOperation
{
    public:
        PreparedStatementTask(PreparedStatementBase* stmt, bool async = false);
        ~PreparedStatementTask();

        bool Execute() override;
        PreparedQueryResultFuture GetFuture() { return m_result->get_future(); }

    protected:
        PreparedStatementBase* m_stmt;
        bool m_has_result;
        PreparedQueryResultPromise* m_result;
};
#endif
