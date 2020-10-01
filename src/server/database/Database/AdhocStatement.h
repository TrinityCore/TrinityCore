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

#ifndef _ADHOCSTATEMENT_H
#define _ADHOCSTATEMENT_H

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "SQLOperation.h"

/*! Raw, ad-hoc query. */
class TC_DATABASE_API BasicStatementTask : public SQLOperation
{
    public:
        BasicStatementTask(char const* sql, bool async = false);
        ~BasicStatementTask();

        bool Execute() override;
        QueryResultFuture GetFuture() const { return m_result->get_future(); }

    private:
        char const* m_sql;      //- Raw query to be executed
        bool m_has_result;
        QueryResultPromise* m_result;
};

#endif
