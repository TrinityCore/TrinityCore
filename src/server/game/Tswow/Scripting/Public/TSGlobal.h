/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
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

#include "TSArray.h"
#include "TSItem.h"
#include "TSBase.h"
#include "TSString.h"

void TC_GAME_API SendMail(uint8 senderType, uint64 from, uint64 to, TSString subject, TSString body, uint32 money, uint32 cod, uint32 delay, TSArray<TSItem> items);
void TC_GAME_API SendWorldMessage(TSString string);