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
#include "halls_of_valor.h"

enum
{
    // Hymdal
    SPELL_BLODDLETTING_SWEEP    = 193083,
    SPELL_DANCING_BLADE         = 193235,
    SPELL_HORN_OF_VALOR         = 191284,

    // Drakes
    SPELL_STATIC_FIELD_DAMAGE   = 193260,
    SPELL_BALL_LIGHTNING        = 188395,
};

// 98542
struct boss_hymdall : public BossAI
{
    boss_hymdall(Creature* creature) : BossAI(creature, DATA_HYMDALL) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_BLODDLETTING_SWEEP, 16s);
        events.ScheduleEvent(SPELL_DANCING_BLADE, 16s);
        events.ScheduleEvent(SPELL_HORN_OF_VALOR, 16s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            default:
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_HORN_OF_VALOR:
            {
                // Summon drakes
                break;
            }
        }
    }
};

// 97960
struct npc_hymdall_dancing_blade : public ScriptedAI
{
    npc_hymdall_dancing_blade(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
    }
};

// 
struct npc_hymdall_drake : public ScriptedAI
{
    npc_hymdall_drake(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
    }
};

void AddSC_boss_hymdall()
{
    RegisterCreatureAI(boss_hymdall);
    RegisterCreatureAI(npc_hymdall_dancing_blade);
    RegisterCreatureAI(npc_hymdall_drake);
}
