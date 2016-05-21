/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef DATABASEENV_H
#define DATABASEENV_H

#include "Common.h"
#include "Errors.h"
#include "Log.h"

#include "Field.h"
#include "QueryResult.h"

#include "MySQLThreading.h"
#include "Transaction.h"

#define _LIKE_           "LIKE"
#define _TABLE_SIM_      "`"
#define _CONCAT3_(A, B, C) "CONCAT( " A ", " B ", " C " )"
#define _OFFSET_         "LIMIT %d, 1"

#include "Implementation/LoginDatabase.h"
#include "Implementation/CharacterDatabase.h"
#include "Implementation/WorldDatabase.h"
#include "Implementation/HotfixDatabase.h"

/// Accessor to the world database
TC_DATABASE_API extern WorldDatabaseWorkerPool WorldDatabase;
/// Accessor to the character database
TC_DATABASE_API extern CharacterDatabaseWorkerPool CharacterDatabase;
/// Accessor to the realm/login database
TC_DATABASE_API extern LoginDatabaseWorkerPool LoginDatabase;
/// Accessor to the hotfix database
TC_DATABASE_API extern HotfixDatabaseWorkerPool HotfixDatabase;

#endif
