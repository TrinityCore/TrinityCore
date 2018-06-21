/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "eye_of_azshara.h"

enum Spells
{
    SPELL_STATIC_NOVA                   = 193597,
    SPELL_FOCUSED_LIGHT                 = 193611,
    
    SPELL_BECKON_STORM                  = 193682,
    SPELL_BECKON_STORM_SUMMON           = 193683,
    SPELL_WATERY_SPLASH                 = 193636,
    
    SPELL_CURSE_OF_THE_WITCH            = 193698,
    SPELL_CURSE_OF_THE_WITCH_KNOCK_BACK = 193700,
    SPELL_CURSE_OF_THE_WITCH_KILL       = 193720,
    SPELL_CURSE_OF_THE_WITCH_ROOT       = 194197,
};

// 91784
struct boss_lady_hatecoil : public BossAI
{
    boss_lady_hatecoil(Creature* creature) : BossAI(creature, DATA_LADY_HATECOIL) { }

    void ScheduleTasks() override
    {
    }

    void ExecuteEvent(uint32 /*eventId*/) override
    {
    }
};

void AddSC_boss_lady_hatecoil()
{
    RegisterCreatureAI(boss_lady_hatecoil);
}
