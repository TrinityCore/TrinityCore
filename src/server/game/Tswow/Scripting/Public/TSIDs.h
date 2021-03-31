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

class TC_GAME_API IDRange {
public:
    IDRange() {
        this->low = 0;
        this->high = 0;
    }

    IDRange(uint32 low, uint32 high) {
        this->low = low;
        this->high = high;
    }

    uint32 low;
    uint32 high;

    uint32 offset(uint32 offset) {
        return this->low + offset;
    }
};

TC_GAME_API IDRange GetIDRange(TSString table, TSString mod, TSString name);
TC_GAME_API uint32 GetID(TSString table, TSString mod, TSString name);
void LoadIDs();