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

#include "TSIncludes.h"
#include "TSSpellInfo.h"
#include <memory.h>
#include "SpellInfo.h"

TSSpellInfo::TSSpellInfo(SpellInfo const* info)
{
    this->info = info;
}

TSSpellInfo::TSSpellInfo()
{
    this->info = nullptr;
}

uint32 TSSpellInfo::ID()  {
    return info->Id;
}
