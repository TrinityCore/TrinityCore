/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "precompiled.h"
#include "def_ulduar.h"
#include "Vehicle.h"

#define SPELL_ARM_DEAD_DAMAGE   HEROIC(63629,63979)
#define SPELL_TWO_ARM_SMASH     HEROIC(63356,64003)
#define SPELL_ONE_ARM_SMASH     HEROIC(63573,64006)
#define SPELL_STONE_SHOUT       HEROIC(63716,64005)
#define SPELL_PETRIFY_BREATH    HEROIC(62030,63980)

#define SPELL_STONE_GRIP        HEROIC(62166,63981)
#define SPELL_ARM_SWEEP         HEROIC(63766,63983)

struct TRINITY_DLL_DECL boss_kologarnAI : public BossAI
{
    boss_kologarnAI(Creature *c) : BossAI(c, BOSS_KOLOGARN), vehicle(me->GetVehicleKit())
    {
        assert(vehicle);
    }

    Vehicle *vehicle;

    void AttackStart(Unit *who)
    {
        me->Attack(who, true);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_kologarn(Creature* pCreature)
{
    return new boss_kologarnAI (pCreature);
}

void AddSC_boss_kologarn()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_kologarn";
    newscript->GetAI = &GetAI_boss_kologarn;
    newscript->RegisterSelf();
}
