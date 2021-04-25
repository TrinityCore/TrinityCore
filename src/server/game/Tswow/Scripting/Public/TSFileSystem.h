/*
 * Copyright (C) 2021 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSBase.h"
#include "TSMain.h"
#include "TSString.h"

TC_GAME_API TSString ReadFile(TSString file, TSString def = JSTR(""));
TC_GAME_API void WriteFile(TSString file, TSString value);
TC_GAME_API void AppendFile(TSString file, TSString value);
TC_GAME_API bool FileExists(TSString file);
TC_GAME_API TSArray<TSString> ReadDirectory(TSString directory);