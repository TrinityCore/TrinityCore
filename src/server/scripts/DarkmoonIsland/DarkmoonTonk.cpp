/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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

#include "ScriptMgr.h"
#include "DarkmoonIsland.h"

enum eSpells
{
    SPELL_PROGRESS_BAR  = 102178,
    SPELL_SUMMON_TONK   = 100752,
};

class go_tonk_console : public GameObjectScript
{
public:
    go_tonk_console() : GameObjectScript("go_tonk_console") { }

    bool OnGossipHello(Player* /*player*/, GameObject* /*go*/) override
    {
        return false;
    }
};

void AddSC_darkmoon_tonk()
{
    new go_tonk_console();
};
