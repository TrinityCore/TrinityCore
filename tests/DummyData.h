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

#ifndef TRINITY_DUMMYDATA_H
#define TRINITY_DUMMYDATA_H

#include "Common.h"
#include "Define.h"

#include <string_view>

struct ItemTemplate;

class UnitTestDataLoader
{
    public:
        static void LoadItemTemplates();

    private:
        static ItemTemplate& GetItemTemplate(uint32 id, std::string_view name);
        static void SetItemLocale(uint32 id, LocaleConstant locale, std::string_view name);
};

#endif
