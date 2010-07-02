/* Copyright (C) 2006 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Celebras_the_Cursed
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_WRATH                 21807
#define SPELL_ENTANGLINGROOTS       12747
#define SPELL_CORRUPT_FORCES        21968

struct celebras_the_cursedAI : public ScriptedAI
{
    celebras_the_cursedAI(Creature *c) : ScriptedAI(c) {}

    uint32 Wrath_Timer;
    uint32 EntanglingRoots_Timer;
    uint32 CorruptForces_Timer;

    void Reset()
    {
        Wrath_Timer = 8000;
        EntanglingRoots_Timer = 2000;
        CorruptForces_Timer = 30000;
    }

    void EnterCombat(Unit * /*who*/) { }

    void JustDied(Unit* /*Killer*/)
    {
        me->SummonCreature(13716, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 600000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Wrath
        if (Wrath_Timer <= diff)
        {
            Unit *pTarget = NULL;
            pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (pTarget)
                DoCast(pTarget, SPELL_WRATH);
            Wrath_Timer = 8000;
        } else Wrath_Timer -= diff;

        //EntanglingRoots
        if (EntanglingRoots_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_ENTANGLINGROOTS);
            EntanglingRoots_Timer = 20000;
        } else EntanglingRoots_Timer -= diff;

        //CorruptForces
        if (CorruptForces_Timer <= diff)
        {
            me->InterruptNonMeleeSpells(false);
            DoCast(me, SPELL_CORRUPT_FORCES);
            CorruptForces_Timer = 20000;
        } else CorruptForces_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_celebras_the_cursed(Creature* pCreature)
{
    return new celebras_the_cursedAI (pCreature);
}

void AddSC_boss_celebras_the_cursed()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "celebras_the_cursed";
    newscript->GetAI = &GetAI_celebras_the_cursed;
    newscript->RegisterSelf();
}

