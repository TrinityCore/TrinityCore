/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef MySQLHacks_h__
#define MySQLHacks_h__

#include "MySQLWorkaround.h"
#include <type_traits>

struct MySQLHandle : MYSQL { };
struct MySQLResult : MYSQL_RES { };
struct MySQLField : MYSQL_FIELD { };
struct MySQLBind : MYSQL_BIND { };
struct MySQLStmt : MYSQL_STMT { };

// mysql 8 removed my_bool typedef (it was char) and started using bools directly
// to maintain compatibility we use this trick to retrieve which type is being used
using MySQLBool = std::remove_pointer_t<decltype(std::declval<MYSQL_BIND>().is_null)>;

#endif // MySQLHacks_h__
