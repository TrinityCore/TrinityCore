/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Grilek
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptedPch.h"
#include "zulgurub.h"

#define SPELL_AVARTAR                24646                  //The Enrage Spell
#define SPELL_GROUNDTREMOR            6524

struct boss_grilekAI : public ScriptedAI
{
    boss_grilekAI(Creature *c) : ScriptedAI(c) {}

    uint32 Avartar_Timer;
    uint32 GroundTremor_Timer;

    void Reset()
    {
        Avartar_Timer = 15000 + rand()%10000;
        GroundTremor_Timer = 8000 + rand()%8000;
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Avartar_Timer
        if (Avartar_Timer <= diff)
        {

            DoCast(me, SPELL_AVARTAR);
            Unit *pTarget = NULL;

            pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);

            if (DoGetThreat(me->getVictim()))
                DoModifyThreatPercent(me->getVictim(),-50);
            if (pTarget)
                AttackStart(pTarget);

            Avartar_Timer = 25000 + rand()%10000;
        } else Avartar_Timer -= diff;

        //GroundTremor_Timer
        if (GroundTremor_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_GROUNDTREMOR);
            GroundTremor_Timer = 12000 + rand()%4000;
        } else GroundTremor_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_grilek(Creature* pCreature)
{
    return new boss_grilekAI (pCreature);
}

void AddSC_boss_grilek()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_grilek";
    newscript->GetAI = &GetAI_boss_grilek;
    newscript->RegisterSelf();
}

